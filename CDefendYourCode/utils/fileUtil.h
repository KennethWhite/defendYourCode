
#ifndef CDEFENDYOURCODE_FILEUTIL_H
#define CDEFENDYOURCODE_FILEUTIL_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "regex.h"
#include <unistd.h>
#include <string.h>
#include "regex.h"
#include "inputUtil.h"
#endif

FILE* openFileWrite(const char *path);
void getInputPath(char* path);
void getOutputPath(char* path);
FILE* openFileRead(const char *path);
int checkFile(char * filename);
int checkOutputFile(char* path);