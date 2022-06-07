#include "helpers.h"
void TranslateKey(const char* encryptKey, const int size, int* trannslatedKey){
  char allChars[26];
  for(char i = 'A'; i <= 'Z'; i++)
        allChars[(int)(i - 'A')] = i;
  for(int i = 0, c = 0; i < 26 && c < size; i++)
      for(int j = 0; j < size; j++)
          if(allChars[i] == encryptKey[j])
              trannslatedKey[j] = ++c;
}

void OrganizeKey(int* TranslatedKey, const int keySize){
  int temp[keySize];
  for(int i = 1; i <= keySize; i++)
    for(int j = 0; j < keySize; j++){
      if(TranslatedKey[j] == i)
          temp[i - 1] = j;
    }
  for(int i = 0 ; i < keySize; i++){
    TranslatedKey[i] = temp[i];
  }
}


int IsAllDigits(const char* key){
  while (*key)
    if (!isdigit(*key++)) return 0;
  return 1;
}

int IsAllChars(const char* key){
 while (*key)
    if (isdigit(*key++)) return 0;
  return 1;
}


void StringToUpper(char *str, const int size){
  for(int i = 0; i < size; i++)
    str[i] = toupper(str[i]);
}
