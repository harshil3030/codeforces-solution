import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class harshil{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        for (int i = 0; i < tt; i++){
            int n,m;
            n = sc.nextInt();
            m = sc.nextInt();
            ArrayList <Long> li1 = new ArrayList<>(n);
            ArrayList <Long> li2 = new ArrayList<>(m);
            long sum1 = 0;
            long sum2 = 0;
            for (int l1 = 0; l1 < n; l1++){
                li1.add(sc.nextLong());
                sum1 += li1.get(l1);
            }
            for (int l2 = 0; l2 < m; l2++){
                li2.add(sc.nextLong());
                sum2 += li2.get(l2);
            }

            if(sum1 > sum2) {
                System.out.println("Tsondu");
            }else if(sum1 < sum2){
                System.out.println("Tenzing");
            }else{
                System.out.println("Draw");
            }
        }
    }
}