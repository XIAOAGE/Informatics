import java.util.Scanner;


public class Main {

	static int[][] C;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int test = in.nextInt();
		
		for(int i=0; i<test; i++){
			
			int M = in.nextInt();
			int N = in.nextInt();
			
			int[][] dp = new int[N+1][M+1];
			
			for(int m=0; m<=M; m++){
				dp[1][m] = 1;
			}
			
			for(int m=0; m<=N; m++){
				dp[m][1] = 1;
				dp[m][0] = 1;
			}
			
			for(int n=2; n<=N; n++){
				for(int m=0; m<=M; m++){
					if(n>m){
						dp[n][m] = dp[m][m];
					}else if(m>=n){
						dp[n][m] = dp[n-1][m]+dp[n][m-n];
					}
				}
			}
			
			System.out.println(dp[N][M]);
			
		}
		
	}
	
	
}
