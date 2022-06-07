#ifndef ARGPARSER_H
#define ARGPARSER_H
// #include "helpers.h"
// #include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mssgs.h"
#include "helpers.h"

void argHandler(int, char**, char**, int*, int*, int*, int*, char**, int*);
void printUsage();
void printManual();
#endif