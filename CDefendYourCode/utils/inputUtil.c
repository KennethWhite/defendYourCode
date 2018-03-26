
#include "inputUtil.h"

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

void getAndCheckName(char* name, char* firstOrLast){
    int valid = 0;
    int ch;

    while(!valid){
        printf("\nPlease enter your %s name, must be between 1-50 characters,\n "
                       "cannot contain numbers or special characters other than - and ' : ", firstOrLast);
        fgets(name,LINE_SIZE,stdin);

        //https://stackoverflow.com/questions/30388101/how-to-remove-extra-characters-input-from-fgets-in-c
        if(!strchr(name, '\n'))     //newline does not exist
            while((ch = fgetc(stdin)) !='\n' && ch != EOF); //discard everything from input(stdin) buffer

        name[LINE_SIZE] = '\0';
        stripNewLine(name);
        compileNameRegex();
        valid = regexIsValid(name);
        if(!valid){
            printf("That is not a valid name, please retry.\n");
        }
    }
}

void stripNewLine(char * string){
string[strcspn(string, "\n")] = '\0';//remove newline
}



long getAndCheckInts(char * firstOrSecond){
    char intLine[INT_LINE_SIZE];
    bzero(intLine, INT_LINE_SIZE);
    char *endPtr = NULL;
    long int num_entered = 0;
    int valid;

    printf("\nEnter %s number, numbers longer than 10 digits will be rejected: ", firstOrSecond);

    valid = 0;
    while (!valid){
        readInt(intLine);
        stripNewLine(intLine);

        intLine[INT_LINE_SIZE] = '\0';

        valid = checkIntInput(intLine);
        errno = 0;
        num_entered = strtol(intLine, &endPtr, BASE);
        valid = valid && strtolAndIntCheck(num_entered);
        if(!valid){
            printf("\nInvalid input, please retry: ");
        }
    }
    return num_entered;
}

void readInt(char *intLine){
    if (fgets(intLine, LINE_SIZE, stdin) == NULL) {
        printf("Error reading buffer.\n");
        writeToErrorFile("Error reading from buffer in readInt()\n");
    }
    int ch;
    if(!strchr(intLine, '\n'))     //newline does not exist
        while((ch = fgetc(stdin)) !='\n' && ch != EOF); //remove everything extra from input(stdin) buffer

}


int strtolAndIntCheck(long num_entered){

    if(errno == ERANGE)
    {
        return 0;
    }

    if(num_entered > +2147483647 || num_entered < -2147483647)
    {
        return 0;
    }
    return 1;
}

int checkIntInput(char* line){

    if (!*line) {
        printf("No user input entered, please retry.\n");
        return 0;
    }
    if(line[0] == '\n'){
        printf("No user input entered, please retry.\n");
        return 0;
    }
    compileIntRegex();
    return regexIsValid(line);
}


void getPassword(char* line){
    int ch, valid = 0;
    while(!valid){
        printf("\n%s", "Please enter a password, (Minimum 8 characters, can contain a-Z, 0-9, !@#$%^&*?-+=): ");
        fgets(line,LINE_SIZE,stdin);

        if(!strchr(line, '\n'))
            while((ch = fgetc(stdin)) !='\n' && ch != EOF); //discard everything from input(stdin) buffer

        line[LINE_SIZE] = '\0';
        stripNewLine(line);
        compilePasswordRegex();
        valid = regexIsValid(line);
        if(!valid){
            printf("\nThat is not a valid password, please retry.\n");
        }
    }
}

void getAndCheckPassword()
{
    int valid = 0;
    char* pass = calloc(LINE_SIZE, sizeof(char));

    while(!valid) {
        printf("\n%s",
               "Please enter a password, (Minimum 8 characters and max 99, can contain any character that is not a newline (\\n)\n");
        fgets(pass, LINE_SIZE, stdin);
        valid = hashAndStore(pass);
    }

    free(pass);
    pass = calloc(LINE_SIZE, sizeof(char));
    valid = 0;

    while(!valid) {
        printf("\n%s",
               "Enter password again to check if its accepted, (Minimum 8 characters and max 99, can contain any character that is not a newline (\\n)\n");
        fgets(pass, LINE_SIZE, stdin);
        valid = getAndCheckPass(pass);
        if(!valid){
            printf("\nPassword did not match, please try again.\n\n");
        }
    }

    free(pass);

}

