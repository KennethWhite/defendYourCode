#include "pass.h"

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

int hashAndStore(char * password)
{
    size_t i;
    size_t lenght = strlen(password);
    for(i = 0 ; i < lenght ; i++)
    {
        if(password[i] == '\n')
            password[i] = '\0' ;
    }

    compilePasswordRegex();
    int isvalid = regexIsValid(password);

    if(isvalid)
    {
        char * salt = "$1$........";
        char * hashPass = crypt(password, salt);
        FILE * fp = fopen("password.txt", "w");
        fprintf(fp, "%s\n", hashPass);
        fclose(fp);
        return 1;
    }
    else
        printf("Failed regex\n");

    return 0;
}

int getAndCheckPass(char * password)
{
    int valid = 0;
    size_t i;
    size_t lenght = strlen(password);
    for(i = 0 ; i < lenght ; i++)
    {
        if(password[i] == '\n')
            password[i] = '\0' ;
    }

    compilePasswordRegex();
    int isvalid = regexIsValid(password);

    if(isvalid)
    {
        char * salt = "$1$........";
        char * passEntered = crypt(password, salt);
        char * passFromFile = calloc(LINE_SIZE, sizeof(char));
        FILE * fp = fopen("password.txt", "r");
        fgets(passFromFile,LINE_SIZE,fp);
        size_t i;
        size_t length = strlen(passEntered);
        int isSame = 1;
        for(i = 0 ; i < length; i++)
        {
            if(passFromFile[i] != passEntered[i])
            {
                isSame = 0;
            }
        }
        if(isSame)
        {
            printf("passwords match\n");
            valid = 1;
        }
        fclose(fp);
        free(passFromFile);
        return valid;
    }
    else
        printf("Failed regex, passwords won't match\n");

    return valid;
}