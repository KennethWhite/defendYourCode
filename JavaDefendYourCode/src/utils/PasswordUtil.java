package utils;

import Password.Password;
import logging.MyLogger;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PasswordUtil {

    public static void getAndVerifyPassword(Scanner kb){

        byte[] salt = Password.getSalt();
        byte[] hashedPW = Password.hash(getPassword(kb).toCharArray(), salt);
        writePasswordToFile(hashedPW);

        boolean samePassword = false;
        System.out.println("Please re-enter your password at the prompt.");
        while(!samePassword) {
            String pwAgain = getPassword(kb);
            byte[] existingHash = readPasswordFromFile();
            samePassword = Password.samePassword(pwAgain.toCharArray(), salt, existingHash);
            if(!samePassword){
                System.out.println("\nIncorrect password, please retry:");
            }
        }
        System.out.println("Password verified.");
    }

    private static String getPassword(Scanner kb){
        String pw = InputUtil.stringInput(kb, "Please enter a password (Minimum 8 characters,can contain a-Z, 0-9, !@#$%^&*?-+=): ");
        while(!passwordPassesRegex(pw)){
            System.out.println("That is not a valid password." +
                    "\nMust be 8 letters long, can contain a-Z, 0-9, !@#$%^&*?-+=");
            pw = InputUtil.stringInput(kb, "Please enter a password: ");
        }
        return pw;
    }



    private static void writePasswordToFile(byte[] hashedPW){
        try{
            File outputFH = new File("password");
            outputFH.setWritable(true);
            FileOutputStream out = new FileOutputStream(outputFH);
            out.write(hashedPW);
            out.close();
            outputFH.setReadOnly();
        }
        catch(Exception e){
            MyLogger.log(Level.SEVERE, "Failed to write password to file:  \n\t{0}", e.getMessage());
        }
    }

    private static byte[] readPasswordFromFile(){
        byte[] existingHash = new byte[32];
        try{
            FileInputStream in = new FileInputStream(new File("password"));
            in.read(existingHash);
            in.close();
        }
        catch(Exception e){
            MyLogger.log(Level.SEVERE, "Failed to read password from file:  \n\t{0}", e.getMessage());
        }
        return existingHash;
    }

    //TODO: change the way we check passwords?
    private static boolean passwordPassesRegex(String password)
    {
        //TODO: actual password regex
        String pwRegex = "^([A-Za-z0-9!@#$%^&*\\-=+?]){8,20}$";
        Pattern p = Pattern.compile(pwRegex);
        Matcher m = p.matcher(password);
        return m.find();
    }

}
