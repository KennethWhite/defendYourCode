
#ifndef CDEFENDYOURCODE_FILEUTIL_H
#define CDEFENDYOURCODE_FILEUTIL_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

FILE* openFileWrite(const char *path);
int file_isReg(const char *path);
FILE* openFileRead(const char *path);
