
#include "inputUtil.h"



void getAndCheckName(char* name, char* firstOrLast){
    int valid = 0;
    int ch;

    while(!valid){
        printf("Please enter your %s name, must be between 1-50 characters,\n "
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
            printf("That is not a valid name, please retry.");
        }
    }
}

void stripNewLine(char * string){
string[strcspn(string, "\n")] = '\0';//remove newline
}



//https://stackoverflow.com/questions/41669086/how-do-i-read-in-an-array-of-characters-and-convert-to-an-integer-in-c-with-erro
long getAndCheckInts(char * firstOrSecond){
    char intLine[INT_LINE_SIZE+1];
    bzero(intLine, INT_LINE_SIZE);
    char *endPtr = NULL;
    long int num_entered = 0;
    int valid;

    printf("\nEnter %s number, numbers longer than 10 digits will be truncated: ", firstOrSecond);

    valid = 0;
    while (!valid){
        readInt(intLine);
        stripNewLine(intLine);

        intLine[INT_LINE_SIZE] = '\0';

        valid = checkIntInput(intLine);
        errno = 0;
        num_entered = strtol(intLine, &endPtr, BASE);
        valid = valid && strtolAndIntCheck(intLine,endPtr,num_entered);
        if(!valid){
            printf("\nInvalid input, please retry: ");
        }
    }
    return num_entered;
}

void readInt(char *intLine){
    if (fgets(intLine, LINE_SIZE, stdin) == NULL) {
        printf("Error reading buffer.\n");
    }

    //https://stackoverflow.com/questions/30388101/how-to-remove-extra-characters-input-from-fgets-in-c
    int ch;
    if(!strchr(intLine, '\n'))     //newline does not exist
        while((ch = fgetc(stdin)) !='\n' && ch != EOF); //extra everything from input(stdin) buffer

}


int strtolAndIntCheck(char *line, char *endPtr, long num_entered){

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

void getAndCheckPassword()
{
    char line[LINE_SIZE];

    //TODO

    //get pw

    //hash

    //write to file

    //ask for pw again

    //get hash from file

    //compare first versus second password

}