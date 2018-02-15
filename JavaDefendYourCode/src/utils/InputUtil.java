package utils;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class InputUtil {

     public static String stringInput(final Scanner kb, final String display){
         String line = "";

         do {

             System.out.print(display);

             line = kb.nextLine();

         }while(line == null || line.length() == 0);

         return line;
    }

    //TODO: cleanup / make better?
    public static int intInput(final Scanner kb){
        boolean validInt = false;
        int i = 0;

        System.out.print("Please enter an integer: ");
        try{
            i = Integer.parseInt(kb.nextLine());
            validInt = true;
        }
        catch(Exception e)
        {
            //TODO
            validInt = false;
        }

        while(!validInt){
            System.out.println("Invalid integer input.");
            System.out.print("Please enter an integer: ");
            try{
                i = Integer.parseInt(kb.nextLine());
                validInt = true;
            }
            catch(Exception e)
            {
                //TODO
                validInt = false;
            }
        }

        return i;
//        try {
//            int i = Integer.parseInt(kb.nextLine());
//        }
//        catch(Exception e)
//        {
//            //
//            validInt = false;
//        }
//
//        return validInt;
    }

    public static boolean namePassesRegex(String name){
        String nameRegex = "^([A-Za-z]-?'?){1,50}$";
        Pattern p = Pattern.compile(nameRegex);
        Matcher m = p.matcher(name);
        return m.find();
    }

    //TODO: change the way we check passwords?
    public static boolean passwordPassesRegex(String password)
    {
        //TODO: actual password regex
        String pwRegex = "^([A-Za-z0-9]){6,8}$";
        Pattern p = Pattern.compile(pwRegex);
        Matcher m = p.matcher(password);
        return m.find();
    }

}
