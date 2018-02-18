#include "regexUtil.h"


regex_t regex;
int reti;
char msgbuf[LINE_SIZE];

///Source: https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples
/* Compile regular expression */
void compileRegex() {
    reti = regcomp(&regex, "^a[[:alnum:]]", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n"); //todo
        exit(1);
    }
}

/* test regular expression */
int testRegex(char * str) {
    reti = regexec(&regex, str, 0, NULL, 0);
    int retValue;
    if (!reti) {
        retValue = 1;
    } else if (reti == REG_NOMATCH) {
        retValue = 0;
    } else {
        //TODO write to the output/error file
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        retValue = 0;
    }
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    return retValue;
}
