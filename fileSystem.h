#include<stdio.h>
#include <stdlib.h>
#include <dirent.h>

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

static DIR *di;

FILE* FileReader(const char*, const char*);
struct dirent** GetAllFilesInDir(const char*, const char*, int*);

#endif