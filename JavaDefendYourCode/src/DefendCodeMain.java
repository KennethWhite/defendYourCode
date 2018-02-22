import logging.MyLogger;
import utils.FileUtil;
import utils.InputUtil;
import utils.PasswordUtil;

import java.io.*;
import java.util.Scanner;
import java.util.logging.Level;

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

public class DefendCodeMain {

    public static void main(String ...args){
        new MyLogger();
        String fName = "", lName = "";
        File inputFH = null, outputFH = null;
        int num1= 0, num2 = 0;
        PrintWriter fout;
        Scanner kb = new Scanner(System.in);

        try {
            fName = getName(kb, "first");
            lName = getName(kb, "last");

            num1 = InputUtil.intInput(kb);
            num2 = InputUtil.intInput(kb);

            inputFH = FileUtil.getFile(kb, true);
            outputFH = FileUtil.getFile(kb, false);

            PasswordUtil.getAndVerifyPassword(kb);

            System.out.printf("Writing data to %s\n", outputFH.getName());
            fout = FileUtil.getPrintWriter(outputFH);
            fout.printf("%s %s\n", fName, lName);
            fout.printf("Numbers added = %d\n",addInts(num1,num2));
            fout.printf("Numbers multiplied = %d\n",multInts(num1,num2));
            FileUtil.writeInputToOutput(inputFH, fout);

            fout.close();
            System.out.println("\nProgram has completed successfully.");
        }
        catch (Exception e){
            System.out.println("Execution of main has failed.");
            MyLogger.log(Level.SEVERE, "Execution of main has failed. " +
                            "\n\tfName: {0} \n\tlName: {1} \n\tinputFH: {2} \n\toutputFH: {3} " +
                            "\n\tnum1: {4,number} \n\tnum2: {5,number}\n\t{6}",
                    fName,lName, inputFH, outputFH, num1, num2, e.getMessage());
        }
        finally {
            MyLogger.closeLogger();
        }
    }

    private static String getName(Scanner kb, String nameType){
        String display = "Please enter your " + nameType + " name\n" +
                "Must be 50 characters or less, cannot contain numbers or special characters except - and ': ";
        String name = InputUtil.stringInput(kb, display);

        while(!InputUtil.namePassesRegex(name) | name.length() > 50){
            System.out.println("That is not a valid name." +
                    "\nMust be 50 characters or less, cannot contain numbers or special characters");
            name = InputUtil.stringInput(kb, display);
        }

        return name;
    }



    private static long addInts(int num1, int num2){
        long res = 0;
        res += num1;
        res += num2;
        return res;
    }
    private static long multInts(int num1, int num2){
        long res = 1;
        res *= num1;
        res *= num2;
        return res;
    }


}
