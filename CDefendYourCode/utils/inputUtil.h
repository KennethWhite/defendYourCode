#ifndef inpututil_h
#define inpututil_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regexUtil.h"
#include "fileUtil.h"
#include <values.h>
#include "errno.h"





#define LINE_SIZE 100
#define INT_LINE_SIZE 12    //+ or - and then up to 10 digits and then '\0' ======> length 12
#define BASE 10
#endif

void stripNewLine(char * string);
void getAndCheckName(char* name, char * firstOrLast);
long getAndCheckInts(char * firstOrSecond);
void readInt(char *line);
int checkIntInput(char * line);
int strtolAndIntCheck(long num_entered);
void getAndCheckPassword();