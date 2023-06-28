import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class harshil{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        for (int i = 0; i < tt; i++){
            int n = sc.nextInt();
            ArrayList <Integer> li = new ArrayList<>();
            for (int j = 0; j < n; j++)
                li.add(sc.nextInt());
            Collections.sort(li);
//            System.out.println(li);
            long sum = 0;
            for (int l = 0; l < n/2; l++)
                sum += li.get(li.size() - l - 1) - li.get(l);
            System.out.println(sum);
        }
    }
}