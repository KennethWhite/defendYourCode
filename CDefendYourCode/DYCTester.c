#include "DYCTester.h"


//Team: Abusement Park 3.0
//Members: Kenny White, Jordan Lambert, Daric Sage


int main() 
{
    char fName[LINE_SIZE+1];
    char lName[LINE_SIZE+1];
    long int num1, num2;
    long long added, multiplied;
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
	do{
		getOutputPath(outputPath);
	}while(!checkStrings(inputPath, outputPath));

    getAndCheckPassword();

    fout = openFileWrite(outputPath);
    fin = openFileRead(inputPath);
    fprintf(fout, "Name: %s %s\nNumbers entered: %ld, %ld\nNumbers added: %lld\nNumbers multiplied %lld\n"
                    "Input file to follow:\n\n", fName, lName, num1, num2, added, multiplied);
    writeInputToOutput(fin, fout);

    fclose(fin);
    fclose(fout);

    printf("\n\nProgram has finished.");

}

int checkStrings(char* first, char* second)
{
	int result = 0;
	size_t len1 = strlen(first);
	size_t len2 = strlen(second);
	
	if(len1 != len2)
		return 0;
	
	result = strncmp(first, second, len1);
	
	if(result == 0)
		return 0;
	
	return 1;	
	
}

long long add(long int num1, long int num2)
{
    return (long long)num1 + num2;
}
long long multiply(long int num1, long int num2)
{
    return (long long)num1 * num2;
}

