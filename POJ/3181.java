import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			int N = in.nextInt();
			int K = in.nextInt();

			BigInteger[][] dp = new BigInteger[N+1][K+1];

			for(int i=0; i<=K; i++){
				dp[0][i] = BigInteger.ONE;
			}
			for(int i=1; i<=N; i++){
				dp[i][0] = BigInteger.ZERO;
			}

			for(int i=1; i<=N; i++){
				for(int j=1; j<=K; j++){
					dp[i][j] = BigInteger.ZERO;
					dp[i][j] = dp[i][j].add(dp[i][j-1]);
					if(i>=j){
						dp[i][j] = dp[i][j].add(dp[i-j][j]);
					}
				}
			}
			System.out.println(dp[N][K]);
		}

	}

}
