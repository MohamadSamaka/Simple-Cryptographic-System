#ifndef PROGRAM_HANDLER_H
#define PROGRAM_HANDLER_H

void callEncryptionAlgos(char*, int, int, char*, int);
void callDecryptionAlgos(char*, int, int, char*, int);
void modeRouter(char*, int, int, int, char*, int);
void mainRouter(char*, int, int, int, int, char*, int);
void ProgramHandler(int, char**);

#endif