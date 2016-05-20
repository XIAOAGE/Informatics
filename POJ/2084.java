import java.math.BigInteger;
import java.util.Scanner;

public class Main {	
	
	static int n;
	static BigInteger[] dp = new BigInteger[110];
	
	public static void main(String[] args){
		solve();
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		while(n!=-1){
			System.out.println(dp[n]);
			n = in.nextInt();
		}
	}
	
	public static void solve()
	{
		dp[1] = BigInteger.valueOf(1);
		dp[0] = BigInteger.valueOf(1);
		int left, right;
		for(int i=2; i<=100; i++){
			left = 0; right = 2*i-2-left;
			dp[i] = BigInteger.ZERO;
			while(right>=0 && left<=i*2-2)
			{
				dp[i] = dp[i].add(dp[(int)right/2].multiply(dp[(int)left/2]));
				left+=2; right-=2;
			}
		}
	}

}
