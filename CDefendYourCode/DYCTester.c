#include "DYCTester.h"


int main() {
    char fName[LINE_SIZE+1];
    char lName[LINE_SIZE+1];
    long int num1, num2;
    long int added, multiplied;

    getAndCheckName(fName, "first");
    getAndCheckName(lName, "last");
    num1 = getAndCheckInts("first");
    num2 = getAndCheckInts("second");

    added = add(num1, num2);
    multiplied = multiply(num1, num2);

    //TODO: input file
//    if(file_isReg(path))
//        openFileRead(path)    //check if null

    //TODO: output file
   // openFileWrite(write())  //check if null

    getAndCheckPassword();

    //TODO: write to the output

}



long int add(long int num1, long int num2)
{
    return num1 + num2;
}
long int multiply(long int num1, long int num2)
{
    return num1 * num2;
}

