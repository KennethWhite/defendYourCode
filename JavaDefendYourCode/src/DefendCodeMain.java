import logging.MyLogger;
import utils.FileUtil;
import utils.InputUtil;
import Password.Password;

import java.io.*;
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
            fName = getName(kb, "first");
            lName = getName(kb, "last");

            num1 = InputUtil.intInput(kb);
            num2 = InputUtil.intInput(kb);

            inputFH = getFile(kb, true, "input");
            outputFH = getFile(kb, false, "output");

            passwordWork(kb);

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
                            "\n\tnum1: {4,number,long} \n\tnum2: [5,number,long}",
                    fName,lName, inputFH, outputFH, num1, num2);
        }
        finally {
            MyLogger.closeLogger();
        }
    }

    private static String getName(Scanner kb, String nameType){
        String display = "Please enter your " + nameType + " name: ";
        String name = InputUtil.stringInput(kb, display);

        while(!InputUtil.namePassesRegex(name) | name.length() > 50){
            System.out.println("That is not a valid name." +
                    "\nMust be 50 characters or less, cannot contain numbers or special characters");
            MyLogger.log(Level.WARNING, "Invalid name entered: \n\tName:{0}", name);

            name = InputUtil.stringInput(kb, display);
        }

        return name;
    }

    //should we restrict maximum filesize?
    private static File getFile(Scanner kb, boolean isInput, String fileType){
        String display = "Please enter name of the " + fileType + " file(must be in local directory): ";
        String fileName = InputUtil.stringInput(kb, display);
        boolean valid = (isInput) ? FileUtil.isValidInputFile(fileName) : FileUtil.isValidOutputFile(fileName);
        while(!valid){
            System.out.println("That is not a valid file name, or not in the local directory, please retry.");
            MyLogger.log(Level.WARNING, "Invalid file name: \n\tFile name:{0}\n\tisInput:{1}", fileName, isInput);

            fileName = InputUtil.stringInput(kb, display);
            valid = (isInput) ? FileUtil.isValidInputFile(fileName) : FileUtil.isValidOutputFile(fileName);
        }

        return new File(fileName);
    }

    //TODO: organize (i was just testing things so I didnt make it pretty)
    private static void passwordWork(Scanner kb){

        //TODO: finish

        //get salt
        byte[] salt = Password.getSalt();

        //get password
        String pw = InputUtil.stringInput(kb, "Please enter a password: ");
        while(!InputUtil.passwordPassesRegex(pw)){
            System.out.println("That is not a valid password." +
                    "\nMust be ________");//TODO
            MyLogger.log(Level.WARNING, "Invalid password entered: \n\tPassword:{0}", pw);

            pw = InputUtil.stringInput(kb, "Please enter a password: ");
        }

        //get hash
        byte[] hashedPW = Password.hash(pw.toCharArray(), salt);

        //store hash
        try{
            FileOutputStream out = new FileOutputStream(new File("password"));

            out.write(hashedPW);

            out.close();

        }
        catch(Exception e){
            //TODO: log and handle
        }


        //get password again
        String pwAgain = InputUtil.stringInput(kb, "Please enter the password again: ");
        while(!InputUtil.passwordPassesRegex(pwAgain)){
            System.out.println("That is not a valid password." +
                    "\nMust be ________");//TODO
            MyLogger.log(Level.WARNING, "Invalid password entered: \n\tPassword:{0}", pwAgain);

            pwAgain = InputUtil.stringInput(kb, "Please enter the password again: ");
        }

        //retrieve hash
        byte[] existingHash = new byte[32];
        try{
            FileInputStream in = new FileInputStream(new File("password"));

            in.read(existingHash);

            in.close();

        }
        catch(Exception e){
            //TODO: log and handle
        }

        //compare hash
        boolean samePassword = Password.samePassword(pwAgain.toCharArray(), salt, existingHash);

        System.out.println(samePassword);
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
