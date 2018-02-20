#include <stdio.h>
#include "fileUtil.h"




int file_isReg(const char *path) {
    struct stat st;

    if (stat(path, &st) < 0)
        return -1;

    return S_ISREG(st.st_mode);
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
