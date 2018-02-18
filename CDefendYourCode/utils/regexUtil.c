#include "regexUtil.h"


regex_t regex;
char msgbuf[LINE_SIZE];

///Source: https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples

void compilePasswordRegex() {
    int result = regcomp(&regex, "^([A-Za-z0-9!@#$%^&*\\-=+?]){8,20}$", REG_EXTENDED);
    if (result) {
        fprintf(stderr, "Could not compile password regex\n"); //todo
        exit(1);
    }
}

void compileNameRegex() {
    int result = regcomp(&regex, "^([A-Za-z]-?'?){1,50}$", REG_EXTENDED);
    if (result) {
        fprintf(stderr, "Could not compile name regex\n"); //todo
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
        //TODO write to the output/error file
        regerror(result, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        retValue = 0;
    }
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    return retValue;
}

