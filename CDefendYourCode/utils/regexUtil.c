#include "regexUtil.h"


regex_t regex;
char msgbuf[LINE_SIZE];

///Source: https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples

void compilePasswordRegex() {
    //8-20 characters, can contain a-Z, 1-9 and !@#$%^&*\-=+?
    int result = regcomp(&regex, "^(.){8,99}$", REG_EXTENDED);
    if (result) {
        writeToErrorFile("Could not compile password regex\n");
        exit(1);
    }
}

void compileNameRegex() {
    int result = regcomp(&regex, "^([A-Za-z]-?'?){1,50}$", REG_EXTENDED);
    if (result) {
        writeToErrorFile("Could not compile name regex\n");
        exit(1);
    }
}

void compileIntRegex() {
    //optional +/- and then followed by 1-10 digits
    int result = regcomp(&regex, "^[+-]?([0-9]){1,10}$", REG_EXTENDED);
    if (result) {
        writeToErrorFile("Could not compile int regex\n");
        exit(1);
    }
}

void compileFileRegex() {
    int result = regcomp(&regex, "^([A-Za-z0-9\\\\-\\\\.]){1,20}(.txt)$", REG_EXTENDED);
    if (result) {
        writeToErrorFile("Could not compile file regex\n");
        exit(1);
    }
}

int regexIsValid(char *str) {
    int result = regexec(&regex, str, 0, NULL, 0);
    int retValue;
    if (!result) {
        retValue = 1;
    } else if (result == REG_NOMATCH) {
        retValue = 0;
    } else {

        regerror(result, &regex, msgbuf, sizeof(msgbuf));
        char error[512];
        sprintf(error, "Regex match failed:\n%s\n", msgbuf);
        writeToErrorFile(error);
        retValue = 0;
    }
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    return retValue;
}

