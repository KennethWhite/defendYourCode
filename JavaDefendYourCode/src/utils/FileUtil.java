package utils;

import logging.MyLogger;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;


public class FileUtil {

    public static boolean isValidInputFile(String fileName){
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
    public static boolean isValidOutputFile(String fileName){
        try {
            File fh = new File(fileName);
            boolean valid =!fh.isDirectory() && !fh.isAbsolute();
            if(fh.exists()){
                valid = valid && fh.canWrite();
            }
            return valid;
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
            MyLogger.log(Level.SEVERE, ex.getMessage());
        }
    }

    public static PrintWriter getPrintWriter(File outputFH) throws IOException{
        try{
            return new PrintWriter(outputFH);
        }
        catch (Exception ex){
            MyLogger.log(Level.SEVERE, "Cannot open output PrintWriter", outputFH, ex.getMessage());
            throw new IOException("Failed to open PrintWriter");
        }
    }

}
