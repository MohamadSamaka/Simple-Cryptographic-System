#include "decrypters.h"

void CaeserCipherDecryption(const char* fileName, const int size, const char* key){
    FILE *inputFile, *outputFile;
    char ch;
    char fileOutputName[size];
    int k = atoi(key);
    inputFile = FileReader(fileName, "r");
    strcpy(fileOutputName, fileName);
    fileOutputName[strlen(fileOutputName) - 3] = '\0';
    strcat(fileOutputName, "txt");
    outputFile = FileReader(fileOutputName, "w");

  do{
    ch = fgetc(inputFile);
    if(ch != -1)
      if(ch == '?')
        continue;
      // else if(ch == '\r')
      //   fputc('\n', outputFile);
      // else if(ch == ' ')
      //   fputc(' ', outputFile);
      // else if(ch - 3 < 'A')
      //   fputc((ch - 3) + 26, outputFile);
      else
        fputc(ch - k, outputFile);
    
  } while (ch != EOF);

    fclose(inputFile);
    remove(fileName);
    fclose(outputFile);
}


void TranspositionCipherDecryption(char*fileName, int fileSize, char*  encryptKey, const int keySize){
  int TranslatedKey[keySize];
  int originalTextSize ,newTextSize, tempSize, nrows; // #cols equals the keySize so no need to define a var for it
  originalTextSize = tempSize = 0;
  char *plaintText = (char*) calloc(fileSize, sizeof(char));
  TranslateKey(encryptKey, keySize, TranslatedKey);
  
  FILE *inputFile, *outputFile;
  char ch;
  char fileOutputName[fileSize];
  inputFile = FileReader(fileName, "r");
  strcpy(fileOutputName, fileName);
  fileOutputName[strlen(fileOutputName) - 3] = '\0';
  strcat(fileOutputName, "txt");
  outputFile = FileReader(fileOutputName, "w");
  char chunk[128];
  while(fgets(chunk, 128, inputFile) != NULL) {
    tempSize = strlen(chunk);
    originalTextSize += tempSize;
    memcpy(plaintText + (originalTextSize - tempSize), chunk, tempSize);
  }
  nrows = ceil((float)originalTextSize/keySize);
  newTextSize = keySize * nrows;
  plaintText = (char*) realloc(plaintText, sizeof(char) * (newTextSize));

  for(int i = nrows; i >= 1; i--)
    for(int j = 0; j < keySize; j++){
        ch = plaintText[TranslatedKey[j] * nrows - i];
        if(ch != -1 && ch)
          if(ch == '?')
            continue;
          else if(ch == '\r')
            fputc('\n', outputFile);
          else
            fputc(ch, outputFile);
    }
  
  free(plaintText);
  fclose(inputFile);
  remove(fileName);
  fclose(outputFile);
}