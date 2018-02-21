
#include "fileUtil.h"



void getOutputPath(char* path){

    int go = 1;

    while(go)
    {
        printf("%s", "Please enter name of output file (file must be in current directory and you can only enter the file name. \nNot a direct path. Characters can be [a-zA-Z0-9\\-.] and must end in .txt)\n");
        fgets(path, LINE_SIZE, stdin);
        int result = checkOutputFile(path);
        if(result)
        {
            go = 0;
        } else
        {
            go = 1;
        }
    }

}

void getInputPath(char* path) {

    int go = 1;

    while(go){
        printf("%s", "Please enter name of input file (file must be in current directory and you can only enter the file name. \nNot a direct path. Characters can be [a-zA-Z0-9-.])\n");
        fgets(path, LINE_SIZE, stdin);
        int result = checkFile(path);
        if(result)
            go = 0;
        else
            go = 1;
    }

}

int checkOutputFile(char * filename)
{
    size_t i;
    size_t lenght = strlen(filename);
    for(i = 0 ; i < lenght ; i++)
    {
        if(filename[i] == '\n')
            filename[i] = '\0' ;
    }

    compileFileRegex();
    int isvalid = regexIsValid(filename);

    if(isvalid)
    {
        printf("passed regex\n");
        char resolvedpath[LINE_SIZE];
        realpath(filename, resolvedpath);
        FILE * fp;
        fp = fopen(resolvedpath,"a");
        if (fp != NULL)
        {
            fclose(fp);
            return 1;
        }
        else
        {
            printf("not a valid file\n");
            return 0;
        }
    }

    printf("failed regex\n");
    return 0;
}

int checkFile(char * filename)
{
    size_t i;
    size_t lenght = strlen(filename);
    for(i = 0 ; i < lenght ; i++)
    {
        if(filename[i] == '\n')
            filename[i] = '\0' ;
    }

    compileFileRegex();
    int isvalid = regexIsValid(filename);

    if(isvalid)
    {
        printf("passed regex\n");
        char resolvedpath[LINE_SIZE];
        realpath(filename, resolvedpath);
        FILE * fp;
        fp = fopen(resolvedpath,"r");
        if (fp != NULL)
        {
            fclose(fp);
            return 1;
        }
        else
        {
            printf("not a valid file\n");
            return 0;
        }
    }

    printf("failed regex\n");
    return 0;
}

FILE* openFileRead(const char *path) {
    FILE * fp;
    fp = fopen (path, "r");
    return fp;
}

FILE* openFileWrite(const char *path) {
    FILE * fp;
    fp = fopen (path, "w");
    return fp;
}
