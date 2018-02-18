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
