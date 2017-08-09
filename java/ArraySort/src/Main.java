import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 06.11.13
 * Time: 22:50
 * To change this template use File | Settings | File Templates.
 */
public class Main {

    public static void main(String [] arg) {
        ArrayList<String> arrayList = new ArrayList<String>();
        BufferedReader br = new BufferedReader(new InputStreamReader (System.in));

        String s;

        do {
            s = null;
            try {
                System.out.println("¬ведите строку: ");
                s = br.readLine();
                if (!s.isEmpty()) {
                    arrayList.add(s);
                }
            } catch (IOException e) {
                e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }

        } while (!s.isEmpty());

        Object[] array = arrayList.toArray();
        Arrays.sort(array);
        for(Object s1: array){
            System.out.println(s1);
        }
    }
}
