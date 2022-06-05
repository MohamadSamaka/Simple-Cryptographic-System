#ifndef ENCRYPTERS_H
#define ENCRYPTERS_H
void CaeserCipherEncryption(char*, int);
void TranspositionCipherEncryption(char*, int, char*, const int);
void TranslateKey(char*, const int, int*);
#endif
