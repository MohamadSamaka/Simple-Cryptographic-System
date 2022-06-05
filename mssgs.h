#ifndef MESSAGES_H
#define MESSAGES_H

#define MISSING_ENCRYPTON_TYPE "[-] you didn't specify the algorithm of encryption\n"
#define MISSING_KEY_TRANSPOSITION_ALGO "[-] key is required for the transposition Cipher algorithm\n"
#define MISSING_MODE "[-] you didn't specify if you want to encrypt or decrypt\n"
#define TWO_MODES_ERR "[-] you can't encrypt and decrypt at thre same time!\n"
#define DIR_FILE_ARGS "[-] a diretory and a single file was given, you muse give either a directory or a single file\n"
#define NO_FILE_OR_DIRECTORY_SPECEFIED "[-] you didn't specify a directory or a file.\n"
#define USAGE "[!] Usage: %s [-h *help*] [-D string] directory path [-f string] file name [-e *encryption mode*] [-d *decryption mode*] [-E int] Algorithm [-c string] key\n"
#define FULL_MANUAL "\n[!] Descryption:\n\n"\
    "[*] -h prints this help mssg\n"\
    "[*] -D specefies the directory you targeting to encrypt the whole files in it\n"\
    "[*] -f specefies a single file to decrypt\n"\
    "[*] -e makes the program in encryption mode\n"\
    "[*] -d makes the program in decryption mode\n"\
    "[*] -c the encrypt/decrypt key that gonna be used in Transposition/Ceaser Ciper enc/dec\n"\
    "    it muse be given as a string any other symbols will be ignored\n"\
    "[*] -E specifies the algorithm you gonna use for encryption / decryption\n"\
    "    you can insert either 1 or 2\n\t"\
    "[1] Caeser Cipher\n\t"\
    "[2] Transposition Cipher\n"\
    "\n[!] Examples:\n"\
    "\n[*] ./programName -D . -e -E 1\n"\
    "encrypt the whole text files in the current directory using Ceaser algo\n"\
    "\n[*] ./programName -f Desktop/dir1/dir2/text1.txt -e -E 2 -c ECZA\n"\
    "encrypt the file that gived by absolute path by using Transposition algo with help of the given key\n"\
    "\n[*] ./programName -D /home/username/Desktop/dir1 -d -E 1\n"\
    "decrypt whole files with extension enc in the given directory path using Ceaser algo\n"\
    "\n[*] ./programName -f text3.txt -d -E 1\n"\
    "decrypt the file named text3.txt (located in currenct directory) using Ceaser algo\n"\
    "\n[!!!] THIS PRGORAM WILL IGNORE ANY '?' SIGN EXISTS IN THE TEXT FILE!\n"
#endif 