#include <string.h>
#include <math.h>
#include "fileSystem.h"
#include "decrypters.h"
#include "helpers.h"

void CaeserCipherDecryption(char* fileName, int size){
    FILE *inputFile, *outputFile;
    char ch;
    char fileOutputName[size];
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
        fputc(ch - 3, outputFile);
    
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
    // printf("%d\n", tempSize);
    // printf("chunk: %s\n", chunk);
    // strcat(plaintText, chunk);
    memcpy(plaintText + (originalTextSize - tempSize), chunk, tempSize);
  }
  nrows = ceil((float)originalTextSize/keySize);
  newTextSize = keySize * nrows;
  plaintText = (char*) realloc(plaintText, sizeof(char) * (newTextSize));

  for(int i = nrows; i >= 1; i--)
    for(int j = 0; j < keySize; j++){
      // printf("i: %d\nj: %d\n", i, j);
        ch = plaintText[TranslatedKey[j] * nrows - i];
        // printf("%c", ch);
        if(ch != -1 && ch)
          if(ch == '?')
            continue;
          else if(ch == '\r'){
            fputc('\n', outputFile);
            printf("\n");
          }
          else {
            fputc(ch, outputFile);
            printf("%c", ch);
          }
    }
  
  free(plaintText);
  fclose(inputFile);
  remove(fileName);
  fclose(outputFile);
}