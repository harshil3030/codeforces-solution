import java.io.*;
import java.util.*;

public class quester_013 {
	public static void main(String[] args) {
		try {
            InputReader in = new InputReader(System.in);
            PrintWriter out = new PrintWriter(System.out);
            int testCases=in.nextInt();
            while(testCases-- > 0) {
            Solver.solve(in, out);
            }
            out.close();
        } catch (Exception e) {
            return;
        }
	}
}

class Triple<A, B, C> {
    public A a;
    public B b;
    public C c;

    public Triple(A first, B second, C third) {
        a = first;
        b = second;
        c = third;
    }
}
class Pair<A, B> {
    public A a;
    public B b;

    public Pair(A a, B b) {
        this.a = a;
        this.b = b;
    }
}

class InputReader {
 
		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
 
		public InputReader(InputStream st) {
			this.stream = st;
		}
 
		public int read() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public int nextInt() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public long nextLong() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}
 
		public String readString() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}
 
		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}
 
		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}

class Solver {
	 static void solve (InputReader in, PrintWriter out) throws IOException {
		int n = in.nextInt();
		int k = in.nextInt();
		String s = in.readString();
		ArrayList <Integer> li = new ArrayList<>();
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'B') li.add(i);
			else cnt++;
		}
		if (cnt == s.length()) {
			out.println(0); return;
		}
		 cnt = 1;
		int temp = li.get(li.size() - 1);
		for (int i = li.size() - 2; i >= 0; i--) {
			if (temp - li.get(i) >= k) {
				cnt++; temp = li.get(i);
			}
		}
		out.println(cnt);
	 }
}
 