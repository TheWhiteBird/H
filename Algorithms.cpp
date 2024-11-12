#pragma comment(lib, "bcrypt.lib")

#include <windows.h>
#include <stdio.h>
#include <bcrypt.h>
#include <ntstatus.h>
#include <conio.h>

int main()
{
	ULONG algCount;
	BCRYPT_ALGORITHM_IDENTIFIER* pAlgList = NULL;

	if (BCryptEnumAlgorithms(BCRYPT_HASH_OPERATION, &algCount, &pAlgList, 0) == STATUS_SUCCESS) {
		wprintf(L"Hashing algorithms\n");
		wprintf(L"~~~~~~~~~~~~~~~~~~\n");

		for (int i = 0; i < algCount; i++)
			wprintf(L"%s\n", pAlgList[i].pszName);

		BCryptFreeBuffer(pAlgList);
	}
	else
		wprintf(L"Could not retrieve CNG hashing algorithms.");

	if (BCryptEnumAlgorithms(BCRYPT_CIPHER_OPERATION, &algCount, &pAlgList, 0) == STATUS_SUCCESS) {
		wprintf(L"\nCipher algorithms\n");
		wprintf(L"~~~~~~~~~~~~~~~~~~\n");

		for (int i = 0; i < algCount; i++)
			wprintf(L"%s\n", pAlgList[i].pszName);

		BCryptFreeBuffer(pAlgList);
	}
	else
		wprintf(L"Could not retrieve CNG cipher algorithms.");

	if (BCryptEnumAlgorithms(BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION, &algCount, &pAlgList, 0) == STATUS_SUCCESS) {
		wprintf(L"\nAsymetric encription algorithms\n");
		wprintf(L"~~~~~~~~~~~~~~~~~~\n");

		for (int i = 0; i < algCount; i++)
			wprintf(L"%s\n", pAlgList[i].pszName);

		BCryptFreeBuffer(pAlgList);
	}
	else
		wprintf(L"Could not retrieve CNG asymetric encription algorithms.");

	if (BCryptEnumAlgorithms(BCRYPT_SECRET_AGREEMENT_OPERATION, &algCount, &pAlgList, 0) == STATUS_SUCCESS) {
		wprintf(L"\nSecret agreement algorithms\n");
		wprintf(L"~~~~~~~~~~~~~~~~~~\n");

		for (int i = 0; i < algCount; i++)
			wprintf(L"%s\n", pAlgList[i].pszName);

		BCryptFreeBuffer(pAlgList);
	}
	else
		wprintf(L"Could not retrieve CNG secret agreement algorithms.");

	if (BCryptEnumAlgorithms(BCRYPT_SIGNATURE_OPERATION, &algCount, &pAlgList, 0) == STATUS_SUCCESS) {
		wprintf(L"\nSignature algorithms\n");
		wprintf(L"~~~~~~~~~~~~~~~~~~\n");

		for (int i = 0; i < algCount; i++)
			wprintf(L"%s\n", pAlgList[i].pszName);

		BCryptFreeBuffer(pAlgList);
	}
	else
		wprintf(L"Could not retrieve CNG signature algorithms.");

	if (BCryptEnumAlgorithms(BCRYPT_RNG_OPERATION, &algCount, &pAlgList, 0) == STATUS_SUCCESS) {
		wprintf(L"\nRandom number generator\n");
		wprintf(L"~~~~~~~~~~~~~~~~~~\n");

		for (int i = 0; i < algCount; i++)
			wprintf(L"%s\n", pAlgList[i].pszName);

		BCryptFreeBuffer(pAlgList);
	}
	else
		wprintf(L"Could not retrieve CNG random number generator algorithms.");

	_getch();  // çàäåðæêà ýêðàíà

	return 0;
}