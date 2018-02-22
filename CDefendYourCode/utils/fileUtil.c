
#include "fileUtil.h"

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

void getOutputPath(char* path){

    int result = 0;

    while(!result)
    {
        printf("\n%s", "Please enter name of output file (file must be in current directory and you can only enter the file name."
                " \nNot a direct path. Characters can be [a-zA-Z0-9\\-.] 1 to 20 chars and must end in .txt)\n"
                "WARNING: Output file will be overwritten if it exists.\n");
        fgets(path, LINE_SIZE, stdin);
        result = checkFile(path, 1);
    }

}

void getInputPath(char* path) {

    int result= 0;

    while(!result){
        printf("\n%s", "Please enter name of input file (file must be in current directory and you can only enter the file name."
                " \nNot a direct path. Characters can be [a-zA-Z0-9-.]) 1 to 20 chars and must end in .txt)\n");
        fgets(path, LINE_SIZE, stdin);
        result = checkFile(path, 0);
    }

}



int checkFile(char * filename, int isOutput)
{
    size_t i;
    char flags[20] = "r";
    if(isOutput) {
        bzero(flags, 20);
        strncpy(flags, "w+\0", 3);
    }
    size_t length = strnlen(filename, LINE_SIZE);
    for(i = 0 ; i < length ; i++)
    {
        if(filename[i] == '\n' || i == (LINE_SIZE-1)) {
            filename[i] = '\0';
            break;
        }
    }

    compileFileRegex();
    int isvalid = regexIsValid(filename);
    if(isvalid)
    {
        char resolvedpath[LINE_SIZE];
        realpath(filename, resolvedpath);
        FILE * fp;
        fp = fopen(resolvedpath,flags);
        if (fp != NULL)
        {
            fclose(fp);
            return 1;
        }
        else
        {
            printf("Not a valid file, please retry.\n");
            return 0;
        }
    }

    printf("File validation failed, please retry.\n");
    return 0;
}


FILE* openFileRead(const char *path) {
    FILE * fp;
    fp = fopen (path, "r");
    return fp;
}

FILE* openFileWrite(const char *path) {
    FILE * fp;
    fp = fopen (path, "w+");
    return fp;
}

void writeToErrorFile(char message[]){
    FILE* fp = fopen("ErrorLog.txt", "aw+");
    if(fp != NULL){
        fprintf(fp, "\n%s", message );
        fclose(fp);
    }
    else{
        fprintf(stderr, "\nFailed to open ErrorLog.txt to record error:\n%s\n", message);
    }
}

void writeInputToOutput(FILE* fin, FILE* fout){
    char line[100];
    while(fgets(line, sizeof(line), fin) !=NULL){
        fputs(line, fout);
    }
    printf("\nWrote input to output file.\n");
}

off_t fileSize(int fd){

    struct stat st;
    fstat(fd, &st);
    return st.st_size;
}