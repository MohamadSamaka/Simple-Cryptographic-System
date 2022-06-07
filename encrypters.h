#ifndef ENCRYPTERS_H
#define ENCRYPTERS_H
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fileSystem.h"
#include "helpers.h"
void CaeserCipherEncryption(const char*, const int, const char*);
void TranspositionCipherEncryption(char*, int, char*, const int);
// void TranslateKey(char*, const int, int*);
#endif
