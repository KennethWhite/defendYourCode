package utils;

import logging.MyLogger;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

public class FileUtil {

    public static File getFile(Scanner kb, boolean isInput){

        String fileType = (isInput) ? "input" : "output";
        String display = "Please enter name of the " + fileType + " file(must be in local directory): ";

        String fileName = InputUtil.stringInput(kb, display);

        boolean valid = (isInput) ? FileUtil.isValidInputFile(fileName) : FileUtil.isValidOutputFile(fileName);

        while(!valid){

            System.out.println("That is not a valid file name, or not in the local directory, or cannot be opened, please retry.");

            fileName = InputUtil.stringInput(kb, display);

            valid = (isInput) ? FileUtil.isValidInputFile(fileName) : FileUtil.isValidOutputFile(fileName);
        }
        return new File(fileName);
    }


    private static boolean isValidInputFile(String fileName){
        try {
            File fh = new File(fileName);
            return  fh.exists() &&
                    !fh.isDirectory() &&
                    !fh.isAbsolute() &&
                    fh.canRead();
        }
        catch (Exception ex){
            return false;
        }
    }
    private static boolean isValidOutputFile(String fileName){
        try {
            File fh = new File(fileName);
            boolean valid = true;
            if(fh.exists()){
                valid = fh.canWrite();
            }
            return valid && !fh.isDirectory() && !fh.isAbsolute();

        }
        catch (Exception ex){
            return false;
        }
    }


    public static void writeInputToOutput(File input, PrintWriter output){
        try{
            Scanner fin = new Scanner(input);
            while (fin.hasNextLine()){
                output.println(fin.nextLine());
            }
            fin.close();
        }
        catch (Exception ex){
            System.out.println("There was a problem writing from input to output file.");
            MyLogger.log(Level.SEVERE, "Failed to copy input file to output: \n\t{0}", ex.getMessage());
        }
    }

    public static PrintWriter getPrintWriter(File outputFH) throws IOException{
        try{
            return new PrintWriter(outputFH);
        }
        catch (Exception ex){
            MyLogger.log(Level.SEVERE, "Cannot open output PrintWriter\n\t{0}\n", outputFH, ex.getMessage());
            throw new IOException("Failed to open PrintWriter");
        }
    }

}
