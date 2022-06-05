#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "argParser.h"
#include "mssgs.h"

char* FILE_NAME;

void printUsage(){
    fprintf(stderr, USAGE, FILE_NAME);
}

void printManual(){
    printUsage();
    printf(FULL_MANUAL);
}


void flagChecker(int encF, int decF, int dirF, int fileF, int keyF, int encryptAlgo){
    int flag = 0;
    if(encF && decF){ //can't encrypt and decrypt at the same time
        fprintf(stderr, TWO_MODES_ERR);
        flag = 1;
    }
    if(!encF && !decF){ //task is not given
        fprintf(stderr, MISSING_MODE);
        flag = 1;
    }
    if (encF && !encryptAlgo || decF && !encryptAlgo) //task is given but algorithm has not been specified
    {
        fprintf(stderr, MISSING_ENCRYPTON_TYPE);
        flag = 1;
    }

    if(encryptAlgo == 2 && !keyF){ //if the algo is transposition Cipher and the key is not gived{
        fprintf(stderr, MISSING_KEY_TRANSPOSITION_ALGO);
        flag = 1;
    }
    
    if(dirF && fileF){ // can't target a directory and a single file at the same time
        fprintf(stderr, DIR_FILE_ARGS);
        flag = 1;
    }
    if(!dirF && !fileF){ // target has not been given (directory or a single file)
        fprintf(stderr, NO_FILE_OR_DIRECTORY_SPECEFIED);
        flag = 1;
    }
    if(flag){
        printf("[!] make sure of the arguments you sent\n[!] do %s -h for program manual (help).\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
}

void argHandler(int argc, char** argv, char** Target, int* size, int* targetType, int* mode, int* algo, char** keyText ,int* keySize){
    int opt, encF, decF, dirF, fileF, keyF, encryptAlgo, temp;
    FILE_NAME = argv[0];
    encF = decF = dirF = fileF = keyF = encryptAlgo = 0;
    while((opt = getopt(argc, argv, "D:f:E:c:edh")) != EOF)
        switch (opt)
        {
            case 'd': //decryption
                *mode = decF++;
                break;
            case 'e': //encryption
                *mode = ++encF;
                break;
            case 'c': //keyCode for trans algo
                keyF = 1;
                strcpy(optarg, strdup(optarg)); //making the string upper case
                *keySize = strlen(optarg);
                *keyText = (char*)malloc(*size * sizeof(char));
                strcpy(*keyText, optarg);
                break;
            case 'f': //file
                if(!*Target){
                    *size = strlen(optarg);
                    *Target = (char *)malloc(*size * sizeof(char));
                    strcpy(*Target, optarg);
                }
                *targetType = fileF++;
                break;
            case 'D': // directory
                if(!*Target){
                    *size = strlen(optarg);
                    *Target = (char *)malloc(*size * sizeof(char));
                    strcpy(*Target, optarg);
                }
                *targetType = ++dirF;
                break;
            case 'E': // Encryption algo 
                temp  = atoi(optarg);
                /*if the user entered 1 it will use ceaser else if 
                he entered 2 it will be trans otherwise it will assign it to 0*/
                *algo = encryptAlgo = (temp == 1? 1: (temp == 2? 2: 0));
                break;
            case 'h':
                printManual();
                exit(EXIT_SUCCESS);
                break;
            default:
                printUsage();
                exit(EXIT_FAILURE);
        }

        flagChecker(encF, decF, dirF, fileF, keyF, encryptAlgo);
}