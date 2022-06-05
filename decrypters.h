#ifndef DECRYPTERS_H
#define DECRYPTERS_H
void CaeserCipherDecryption(char*, int);
void TranspositionCipherDecryption(char*fileName, int fileSize, char*  encryptKey, const int keySize);
void CopyTranslateKey(char* encryptKey, const int size, int* trannslatedKey);

#endif