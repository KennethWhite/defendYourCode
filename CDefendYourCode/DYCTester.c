#include "DYCTester.h"

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

int main() {
    char fName[LINE_SIZE+1];
    char lName[LINE_SIZE+1];
    long int num1, num2;
    long int added, multiplied;
    char inputPath[LINE_SIZE+1];
    char outputPath[LINE_SIZE+1];
    FILE* fout;
    FILE* fin;

    getAndCheckName(fName, "first");
    getAndCheckName(lName, "last");
    num1 = getAndCheckInts("first");
    num2 = getAndCheckInts("second");

    added = add(num1, num2);
    multiplied = multiply(num1, num2);

    getInputPath(inputPath);
    getOutputPath(outputPath);

    getAndCheckPassword();

    fout = openFileWrite(outputPath);
    fin = openFileRead(inputPath);
    fprintf(fout, "Name: %s %s\nNumbers entered: %ld, %ld\nNumbers added: %ld\nNumbers multiplied %ld\n"
                    "Input file to follow:\n\n", fName, lName, num1, num2, added, multiplied);
    writeInputToOutput(fin, fout);

    fclose(fin);
    fclose(fout);

    printf("\n\nProgram has finished.");

}



long int add(long int num1, long int num2)
{
    return num1 + num2;
}
long int multiply(long int num1, long int num2)
{
    return num1 * num2;
}

