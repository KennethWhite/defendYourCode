
#ifndef CDEFENDYOURCODE_FILEUTIL_H
#define CDEFENDYOURCODE_FILEUTIL_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include "regex.h"
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "regex.h"
#include "inputUtil.h"
#endif

FILE* openFileWrite(const char *path);
void getInputPath(char* path);
void getOutputPath(char* path);
FILE* openFileRead(const char *path);
int checkFile(char * filename, int isOutput);
int checkNames(char* fname, int isOutput);
void writeToErrorFile(char message[]);
off_t fileSize(int fd);
void writeInputToOutput(FILE* fin, FILE* fout);
