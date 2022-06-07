#ifndef HELPERS_H
#define HELPERS_H
#include <ctype.h>
void TranslateKey(const char*, const int, int*);
void OrganizeKey(int*,const int);
void StringToUpper(char*, const int);
int IsAllDigits(const char*);
int IsAllChars(const char*);
#endif