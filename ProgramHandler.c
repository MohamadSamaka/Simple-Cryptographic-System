#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "ProgramHandler.h"
#include "fileSystem.h"
#include "encrypters.h"
#include "decrypters.h"
#include "argParser.h"
//mode is for encryption or decryption, nalgo speceifies the used algo in theses modes


void callEncryptionAlgos(char* targetPath, int size, int algo, char* key, int KeySize){
    switch (algo)
    {
    case 1:
        CaeserCipherEncryption(targetPath, size, key);
        break;
    case 2:
        TranspositionCipherEncryption(targetPath, size, key, KeySize);
        break;
    }
}

void callDecryptionAlgos(char* targetPath, int size, int algo, char* key, int KeySize){
    switch (algo)
    {
    case 1:
        CaeserCipherDecryption(targetPath, size, key);
        break;
    case 2: 
        TranspositionCipherDecryption(targetPath, size, key, KeySize);
        break;
    }
}

void modeRouter(char* targetPath, int size, int mode, int algo, char* transKey, int transKeySize){
    if(mode == 1)
        callEncryptionAlgos(targetPath, size, algo, transKey, transKeySize);
    else
        callDecryptionAlgos(targetPath, size, algo, transKey, transKeySize);
}


void mainRouter(char* targetPath, int size, int targetType, int mode, int algo, char* key, int KeySize){
    int dirFileNum;
    if(!targetType)
        modeRouter(targetPath, size, mode, algo, key, KeySize);
    else{
        struct dirent **dir = GetAllFilesInDir(targetPath, mode? "txt": "enc", &dirFileNum);
        if(dirFileNum)
            for (int i = 0 ; i < dirFileNum; i++)
                modeRouter(dir[i]->d_name, size, mode, algo, key, KeySize);
        else{
            printf("[!] no files to %s\n", mode? "encrypt": "decrypt");
            free(dir);
            closedir(di);
            exit(EXIT_SUCCESS);
        }
        free(dir);
        closedir(di);
    }
}

void ProgramHandler(int argc, char** argv){
    char *targetPath, *keyText;
    targetPath = keyText = NULL;
    int mode, algoCode, targetType, size, transKeySize;
    argHandler(argc, argv, &targetPath, &size, &targetType, &mode, &algoCode, &keyText, &transKeySize);
    mainRouter(targetPath, size, targetType, mode, algoCode, keyText, transKeySize);
    free(targetPath);
    printf(mode == 1? "[+] Files has been encrypted successfuly.\n":
        "[+] Files has been decrypted successfuly.\n");
}