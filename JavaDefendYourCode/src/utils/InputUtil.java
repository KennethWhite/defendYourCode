package utils;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

public class InputUtil {

     public static String stringInput(final Scanner kb, final String display){
         String line;

         do {
             System.out.print(display);
             line = kb.nextLine();
         }while(line == null || line.length() == 0);

         return line;
    }

    public static int intInput(final Scanner kb){
        boolean validInt = false;
        int i = 0;

        while(!validInt){
            System.out.print("Please enter an integer: ");
            try{
                i = Integer.parseInt(kb.nextLine());
                validInt = true;
            }
            catch(Exception e)
            {
                System.out.println("Invalid integer input.");
                validInt = false;
            }
        }
        return i;
    }

    public static boolean namePassesRegex(String name){
        String nameRegex = "^([A-Za-z]-?'?){1,50}$";
        Pattern p = Pattern.compile(nameRegex);
        Matcher m = p.matcher(name);
        return m.find();
    }

}
