package Password;

import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.Random;

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
        catch(Exception e)
        {
            //TODO: logger
            //TODO: exception handling
            return null;
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

        //Arrays.fill(password, '0');

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
