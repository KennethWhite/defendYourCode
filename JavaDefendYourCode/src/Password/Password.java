package Password;

import logging.MyLogger;

import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.Random;
import java.util.logging.Level;

/*
Team: Abusement Park 3.0
Members: Kenny White, Jordan Lambert, Daric Sage
 */

/**
 *
 * Credit to: https://stackoverflow.com/questions/18142745/how-do-i-generate-a-salt-in-java-for-salted-hash
 * Used for both the knowledge and implementation of password salting and hashing
 *
 * This is a 'static' class used for its capabilities of salting and hashing a given password.
 *
 */
public class Password {

    private static final Random RANDOM = new SecureRandom();
    private static final int ITERATIONS = 100;
    private static final int KEY_LENGTH = 256;

    private Password(){}

    /*
    Generates a random 'salt' byte[]
     */
    public static byte[] getSalt()
    {
        byte[] salt = new byte[32];
        RANDOM.nextBytes(salt);
        return salt;
    }

    /*
    Hashes the given char[] password given the provided 'salt' byte[]
     */
    public static byte[] hash(char[] password, byte[] salt)
    {
        PBEKeySpec pbe = null;

        try {
            pbe = new PBEKeySpec(password, salt, ITERATIONS, KEY_LENGTH);

            //Clear password array
            Arrays.fill(password, '0');

            SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
            return keyFactory.generateSecret(pbe).getEncoded();
        }
        catch(Exception ex)
        {
            System.out.println("Hashing failed");
            MyLogger.log(Level.SEVERE, "Failed to hash password: \n\t{0}", ex.getMessage());
            return new byte[0];
        }
        finally {
            pbe.clearPassword();
        }
    }

    /*
    Checks the given char[] password against the expected byte[] hash
     */
    public static boolean samePassword(char[] givenPassword, byte[] salt, byte[] expectedHash)
    {
        byte[] givenHash = hash(givenPassword, salt);

        if(givenHash.length != expectedHash.length)
        {
            return false;
        }

        for(int x = 0; x < givenHash.length; x++)
        {
            if(givenHash[x] != expectedHash[x])
            {
                return false;
            }
        }

        return true;
    }

}
