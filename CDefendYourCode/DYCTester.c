#include "DYCTester.h"

int main() {
    char fName[LINE_SIZE+1];
    char lName[LINE_SIZE+1];
    long num1, num2;
    getAndCheckName(fName, "first");
    getAndCheckName(lName, "last");
    num1 = getAndCheckInts("first");
    num2 = getAndCheckInts("second");
}

