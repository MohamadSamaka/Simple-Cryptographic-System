#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "fileSystem.h"

FILE* FileReader(const char* fileName, const char* mode){
    FILE *filePtr;
    char errMssg[100];
    filePtr = fopen(fileName, mode);
    if (!filePtr) {
        sprintf(errMssg, "[-] File %s Open Error.", fileName);
        puts(errMssg);
        exit(EXIT_FAILURE);
    }
  
    return filePtr;
}

struct dirent** GetAllFilesInDir(const char* dirPath, const char* mode, int* filesNum){
    // DIR *di;
    char *ptr1,*ptr2, errMssg[100];
    int retn, size = 5, c = 0;
    struct dirent** dir = (struct dirent**)calloc(size, sizeof(struct dirent*));
    struct dirent *tempDir;
    char tempName[25];
    di = opendir(dirPath); //specify the directory name
    if (di){
        while ((tempDir = readdir(di)) != NULL)
        {
            strcpy(tempName, tempDir->d_name);
            ptr1=strtok(tempDir->d_name,".");
            ptr2=strtok(NULL,".");
            if(ptr2!=NULL)
            {
                retn=strcmp(ptr2, mode);
                if(retn==0)
                {
                    strcpy(tempDir->d_name, tempName);
                    dir[c++] = tempDir;
                    if(c == size){
                        size += 5;
                        dir = (struct dirent**)realloc(dir, size * sizeof(struct dirent*));
                    }
                }
            }
        }
    }else{
        sprintf(errMssg, "[-] Directory %s Open Error.", dirPath);
        puts(errMssg);
        exit(1);
    }
    *filesNum = size - (size - c);
    return dir;
}