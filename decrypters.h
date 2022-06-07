#ifndef DECRYPTERS_H
#define DECRYPTERS_H
#include <string.h>
#include <math.h>
#include "fileSystem.h"
#include "helpers.h"
void CaeserCipherDecryption(const char*, const int, const char*);
void TranspositionCipherDecryption(char*fileName, int fileSize, char*  encryptKey, const int keySize);
#endif