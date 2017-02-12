import java.util.Scanner;

class Main {
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int ncase = 0;
		while (true) {
			ncase++;
			int p = in.nextInt();
			int e = in.nextInt();
			int i = in.nextInt();
			int d = in.nextInt();
			if (p == -1)
				return;
			int ans = (5544 * p + 14421 * e + 1288 * i-d+21252) % 21252;
			if(ans==0)
				ans=21252;
			System.out.println("Case " + ncase + ": the next triple peak occurs in " + ans + " days.");
		}
	}
}
