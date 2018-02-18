#ifndef inpututil_h
#define inpututil_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regexUtil.h"
#include <values.h>
#include "errno.h"

#define LINE_SIZE 100
#define INT_LINE_SIZE 11
#define BASE 10
#endif

void stripNewLine(char * string);
void getAndCheckName(char* name, char * firstOrLast);
long getAndCheckInts(char * firstOrSecond);
void readInt(char *line);
int checkIntInput(char * line);
int strtolErrorCheck(char *line, char *endPtr, long num_entered);