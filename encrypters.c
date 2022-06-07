#include "encrypters.h"

void CaeserCipherEncryption(const char* fileName, const int size, const char* key){
  FILE *inputFile, *outputFile;
  char ch;
  char fileOutputName[size];
  int k = atoi(key);
  inputFile = FileReader(fileName, "r");
  strcpy(fileOutputName, fileName);
  fileOutputName[strlen(fileOutputName) - 3] = '\0';
  strcat(fileOutputName, "enc");
  outputFile = FileReader(fileOutputName, "w");

  do{
    ch = fgetc(inputFile);
    if(ch != -1)
      if(ch == '?')
        continue;
      // else if(ch + 3 > 'Z')
      //   fputc((ch + 3) - 26, outputFile);
      // else if(ch == ' ')
      //   fputc(' ', outputFile);
      else
        fputc(ch + k, outputFile);

  } while (ch != EOF);
    

    fclose(inputFile);
    remove(fileName);
    fclose(outputFile);
}


void TranspositionCipherEncryption(char*fileName, int fileSize, char*  encryptKey, const int keySize){
  int TranslatedKey[keySize];
  int originalTextSize ,newTextSize, tempSize, nrows; // #cols equals the keySize so no need to define a var for it
  originalTextSize = tempSize = 0;
  char* plaintText = NULL;
  TranslateKey(encryptKey, keySize, TranslatedKey);
  OrganizeKey(TranslatedKey, keySize);

  char ch; //*
  
  FILE *inputFile, *outputFile;
  char chunk[128];
  char fileOutputName[fileSize];
  inputFile = FileReader(fileName, "r");
  strcpy(fileOutputName, fileName);
  fileOutputName[strlen(fileOutputName) - 3] = '\0';
  strcat(fileOutputName, "enc");
  outputFile = FileReader(fileOutputName, "w");
  while(fgets(chunk, 128, inputFile) != NULL) {
    tempSize = strlen(chunk);
    originalTextSize += tempSize;
    plaintText = (char*) realloc(plaintText, sizeof(char) * originalTextSize);
    memcpy(plaintText + (originalTextSize - tempSize), chunk, tempSize);
  }

  nrows = ceil((float)originalTextSize/keySize);
  newTextSize = keySize * nrows;
  plaintText = (char*) realloc(plaintText, sizeof(char) * (newTextSize));

  for(int i = 0, c = 0; i < keySize; i++){
      for(int j = 0; j < nrows; j++){
        ch = plaintText[TranslatedKey[i]  + j * keySize];
        if(ch != -1)
          if(!ch)
            fputc('?', outputFile);
          else  
            fputc(ch ,outputFile);
      }
  }

  fclose(inputFile);
  remove(fileName);
  fclose(outputFile);
  free(plaintText);
}