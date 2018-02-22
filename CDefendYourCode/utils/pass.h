#ifndef CDEFENDYOURCODE_PASS_H
#define CDEFENDYOURCODE_PASS_H
#include <stdio.h>
#include "regex.h"
#include <unistd.h>
#include <string.h>
#include <crypt.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include "regexUtil.h"
#endif //CDEFENDYOURCODE_PASS_H

int hashAndStore(char * password);
int getAndCheckPass(char * password);