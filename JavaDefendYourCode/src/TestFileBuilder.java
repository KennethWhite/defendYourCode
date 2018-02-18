
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.Random;


public class TestFileBuilder {
//https://stackoverflow.com/questions/37621025/how-to-deal-with-a-huge-one-line-file-in-java
        public static void main(String[] argv) {

            try {
                long time = System.currentTimeMillis();
                File from = new File("input.txt");
                createTestFile(from, StandardCharsets.UTF_8, 1_000_000_000);
                System.out.println("Created file in: " + (System.currentTimeMillis() - time) + "ms");

            } catch (IOException e) {
                throw new RuntimeException(e.getMessage(), e);
            }
        }

        private static void createTestFile(File file, Charset encoding, long size) throws IOException {
            Random r = new Random(12345);
            try (OutputStream fout = new FileOutputStream(file);
                 BufferedOutputStream bout = new BufferedOutputStream(fout);
                 Writer writer = new OutputStreamWriter(bout, encoding)) {
                for (long i=0; i<size; ++i) {
                    int c = r.nextInt(26);
                    if (c == 0)
                        writer.write('}');
                    else
                        writer.write('a' + c);
                }
            }
        }


}
