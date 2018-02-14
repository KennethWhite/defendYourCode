import logging.MyLogger;
import utils.FileUtil;
import utils.InputUtil;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;

//Error
public class DefendCodeMain {

    public static void main(String ...args){
        new MyLogger();
        String fName = "", lName = "";
        File inputFH = null, outputFH = null;
        int num1= 0, num2 = 0;
        PrintWriter fout;
        Scanner kb = new Scanner(System.in);

        try {
            System.out.print("Please enter your first name: ");
            fName = getName(kb);
            System.out.print("Please enter your last name: ");
            lName = getName(kb);

            System.out.print("Please enter name of the input file(must be in local directory): ");
            inputFH = getFile(kb, true);
            System.out.print("Please enter name of the output file(must be in local directory): ");
            outputFH = getFile(kb, false);

            num1 = InputUtil.intInput(kb);
            num2 = InputUtil.intInput(kb);
            //getPassword(kb); //TODO

            fout = FileUtil.getPrintWriter(outputFH);
            fout.printf("%s %s\n", fName, lName);
            fout.printf("Numbers added = %d\n",addInts(num1,num2));
            fout.printf("Numbers multiplied = %d\n",multInts(num1,num2));
            FileUtil.writeInputToOurput(inputFH, fout);

            fout.close();
            System.out.println("\nProgram has completed successfully.");
        }
        catch (Exception e){
            System.out.println("Execution of main has failed.");
            MyLogger.log(Level.SEVERE, "Execution of main has failed. " +
                            "\n\tfName: {0} \n\tlName: {1} \n\tinputFH: {2} \n\toutputFH: {3} " +
                            "\n\tnum1: {4,number,long} \n\tnum2: [5,number,long}",
                    fName,lName, inputFH, outputFH, num1, num2);
        }
        finally {
            MyLogger.closeLogger();
        }
    }

    private static String getName(Scanner kb){
        String name = InputUtil.stringInput(kb);
        if(!InputUtil.namePassesRegex(name) | name.length() > 50){
            System.out.println("That is not a valid name." +
                    "\nMust be 50 characters or less, cannot contain numbers or special characters");
            MyLogger.log(Level.WARNING, "Invalid name entered: \n\tName:{0}", name);

            return getName(kb);
        }
        return name;
    }

    //should we restrict maximum filesize?
    private static File getFile(Scanner kb, boolean isInput){
        String fileName = InputUtil.stringInput(kb);
        boolean valid = (isInput) ? FileUtil.isValidInputFile(fileName) : FileUtil.isValidOutputFile(fileName);
        if(!valid){
            System.out.println("That is not a valid file name, or not in the local directory, please retry.");
            MyLogger.log(Level.WARNING, "Invalid file name: \n\tFile name:{0}\n\tisInput:{1}", fileName, isInput);
            return getFile(kb, isInput);
        }
        return new File(fileName);
    }

    private static void getPassword(Scanner kb){
        //TODO , salt and hash PW, double check pw, store hash
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
