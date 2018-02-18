
#include "inputUtil.h"



void getAndCheckName(char* name, char * firstOrLast){
    int valid = 0;
    while(!valid){
        printf("Please enter your %s name, must be between 1-50 characters,\n "
                       "cannot contain numbers or special characters other than - and ' : ", firstOrLast);
        fgets(name,LINE_SIZE,stdin);
        name[LINE_SIZE] = '\0';
        stripNewLine(name);
        compileNameRegex();
        valid = regexIsValid(name);
        if(!valid){
            printf("That is not a valid name, please retry.");
        }
    }
}

void stripNewLine(char * string){
string[strcspn(string, "\n")] = '\0';//remove newline
}



//https://stackoverflow.com/questions/41669086/how-do-i-read-in-an-array-of-characters-and-convert-to-an-integer-in-c-with-erro
long getAndCheckInts(char * firstOrSecond){
    char line[LINE_SIZE];
    bzero(line, LINE_SIZE);
    char strToPars[INT_LINE_SIZE];
    bzero(strToPars, INT_LINE_SIZE);
    char *endPtr = NULL;
    long num_entered = 0;
    int valid;

    printf("\nEnter %s number, numbers longer than 10 digits will be truncated: ", firstOrSecond);

    valid = 0;
    while (!valid){
        readInt(line);
        strncpy(strToPars, line, INT_LINE_SIZE);

        strToPars[INT_LINE_SIZE] = '\0';
        bzero(line, LINE_SIZE);

        valid = checkIntInput(strToPars);
        num_entered = strtol(strToPars, &endPtr, BASE);
        valid = valid && strtolErrorCheck(line,endPtr,num_entered);
        if(!valid){
            printf("\nInvalid input, please retry: ");
        }
    }
    return num_entered;
}

void readInt(char *line){
    if (fgets(line, LINE_SIZE, stdin) == NULL) {
        printf("Error reading buffer.\n");
    }
}


int strtolErrorCheck(char *line, char *endPtr, long num_entered){
    /* error checking for strtol() */
    if (endPtr == line) {
        printf("No digits parsed from input, please retry\n"); //TODO remove, debug purposes
        return 0;
    }

    /* validating that range is within bounds */
    if (((num_entered >= (int)INT_MAX || num_entered <= (int)INT_MIN) && errno == ERANGE) //TODO comparizon not working correctly, numbers larger than 2.14 billion succeed
        || (errno != 0 && num_entered == 0)) {
        printf("number found is out of range, %d - %d.\n", INT_MIN, INT_MAX);
        return 0;
    }
    /* prints out excess characters found */
    if (*endPtr != '\0') {
        printf("Further characters found after number, or no number entered: %s\n", endPtr);
        return 0;
    }
    printf("Number entered: %ld\n", num_entered);
    return 1;
}

int checkIntInput(char * line){
    size_t slen;
    if (!*line) {
        printf("No user input entered, please retry.\n");
        return 0;
    }
    if(line[0] == '\n'){
        printf("No user input entered, please retry.\n");
        return 0;
    }
    slen = strlen(line);
    if (slen > 0) {
        if (line[slen-1] == '\n') {
            line[slen-1] = '\0';
        } else {
            printf("Number entered is too long, please retry.\n");//TODO remove, debug purposes
            bzero(line, INT_LINE_SIZE);
            return 0;
        }
        return 1;
    }
    return 0;
}