import java.io.*;
import java.util.*;

public class quester_013 {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int tt = sc.nextInt();
		while (tt-- > 0) {
		int n = sc.nextInt();
		int k = sc.nextInt();
		String s = sc.next();
		ArrayList <Integer> li = new ArrayList<>();
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'B') li.add(i);
			else cnt++;
		}
		if (cnt == s.length()) {
			System.out.println(0);
			continue;
		}
		 cnt = 1;
		int temp = li.get(li.size() - 1);
		for (int i = li.size() - 2; i >= 0; i--) {
			if (temp - li.get(i) >= k) {
				cnt++; temp = li.get(i);
			}
		}
		System.out.println(cnt);
		}
	}
}