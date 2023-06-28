import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class harshil {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        for (int i = 0; i < tt; i++){
            ArrayList <Long> li = new ArrayList<>();
            long sum = 0;

            int n = sc.nextInt();
            for (int j = 0; j < n; j++){
                li.add(sc.nextLong());
                sum += Math.abs(li.get(j));
            }
//            System.out.println(li);
//            for (int i = 0; i < n; i++)
//                System.out.println();
            int cnt = 0;
            int flag = 0;
            for (int k = 0; k < n; k++){
                if (li.get(k) <= 0){
                    if(li.get(k) == 0)
                        continue;
                    if(flag == 0)
                     cnt++;
                     flag = 1;
                }else{
                    flag = 0;
                }
            }
            System.out.println(sum + " " + cnt);
//            System.out.println(cnt);
        }
    }
}