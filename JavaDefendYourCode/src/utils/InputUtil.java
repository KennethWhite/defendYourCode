package utils;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class InputUtil {

     public static String stringInput(final Scanner kb){
        try{
            String line = kb.nextLine();
            if(line == null || line.length() == 0){
                throw new NullPointerException();
            }
            return line;
        }
        catch (Exception ex){
            System.out.println("That is not valid input, please retry.");
            return stringInput(kb);
            //TODO: non-recursive
        }
    }

    public static int intInput(final Scanner kb){
        try{
            System.out.print("Please enter an integer: ");
            return Integer.parseInt(kb.nextLine());
        }
        catch(Exception ex){
            System.out.println("That is not a valid integer, please retry.");
            return intInput(kb);
            //TODO non-recursive
        }
    }

    public static boolean namePassesRegex(String name){
        String nameRegex = "^([A-Za-z]-?'?){1,50}$";
        Pattern p = Pattern.compile(nameRegex);
        Matcher m = p.matcher(name);
        return m.find();
    }

}
