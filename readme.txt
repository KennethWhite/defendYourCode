Team Members:
Kenny White
Jordan Lambert
Daric Sage

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Shortcomings:
none

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Java what we defended against:
-First and Last name only contain 1-50 characters
-First and Last name only contain alphabetic characters and "'" and "-"
-Only integer values can be entered
-Protect against integer overflow
-Password can be 8 to 20 characters: AlphaNumeric and special symbols [!@#$%^&*\-=+?]
-Input and Output file have to have correct permissions
-Input and Output file have to be in current directory
-Empty lines do not crash the program

Any exceptions thrown will be written to ErrorLog.txt

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

C what we defended against:
-First and Last name only contain 1-50 characters
-First and Last name only contain Alpha characters and "'" and "-"
-Only integer values can be entered
-Password Protection:
Protects attackers from getting the password by hashing with a crypto hash with added salt and store that in a file. As soon as the password is stored its memory is freed to keep the 
password in memory for as little time as possible. 
Protects against buffer overflow by only allowing the user to enter in so many characters. 
-Input File Protection: 
Protects against attackers gaining access to important files by forcing the user to only access files in the current directory, with read only permissions, and only text files. 
Protects against buffer overflow by only allowing the user to enter in so many characters. 
-Output File Protection: 
Protects against attackers gaining access to important files by forcing the user to only access text files to write to. 
Protects against buffer overflow by only allowing the user to enter in so many characters. 
-Empty lines do not crash the program

Any exceptions thrown will be written to ErrorLog.txt

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Java Instructions:
-We used javac with no additional flags
-We used Windows 8/10 64 bit OS

terminal instructions:
javac DefendCodeMain.javac		-> compiles
java DefendCodeMain				-> runs the program

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

C Instructions:
-We use gcc version 5.4.0 or later with the following flags: -pedantic -Wall -Wextra -Werror -lcrypt
-We used Ubuntu 16.x 64 bit OS

command line instructions:
make							-> compiles with necessary flags
./dyc							-> runs the program
