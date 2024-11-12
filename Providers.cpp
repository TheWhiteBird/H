#include <windows.h>
#include <bcrypt.h>
#include <stdio.h>

#pragma comment(lib, "bcrypt.lib")

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

void EnumProviders1()
{
	NTSTATUS status;
	ULONG cbBuffer = 0;
	PCRYPT_PROVIDERS pBuffer = NULL;

	/*
	Get the providers, letting the BCryptEnumRegisteredProviders
	function allocate the memory.
	*/
	status = BCryptEnumRegisteredProviders(&cbBuffer, &pBuffer);

	if (NT_SUCCESS(status)) 
	{
		if (pBuffer != NULL) 
		{
			// Enumerate the providers.
			for (ULONG i = 0; i < pBuffer->cProviders; i++) 
			{
				wprintf(L"%s\n", pBuffer->rgpszProviders[i]);
			}
		}
	}

	else 
	{
		printf("BCryptEnumRegisteredProviders failed with error code 0x%08x\n", status);
	}

	// Free the memory
	if (NULL != pBuffer)
	{
		BCryptFreeBuffer(pBuffer);
	}
}

int main() 
{
	EnumProviders1();
	return 0;
}
