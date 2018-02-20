#ifndef commands_h
#define commands_h

#include "inputUtil.h"
#include "regex.h"

void compilePasswordRegex();
void compileNameRegex();
void compileIntRegex();
int regexIsValid(char *str);
#endif


