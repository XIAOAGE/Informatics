import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static final int limit = 210000;
	static final int INF = 100000000;
	static int[] S;
	static int[] F;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		S = new int[N];
		F = new int[N];
		for(int i=0; i<N; i++){
			S[i] = in.nextInt();
			F[i] = in.nextInt();
		}

		int[] dp = new int[limit];
		Arrays.fill(dp, -1*INF);
		dp[100000] = 0;

		for(int i=0; i<N; i++){
			if(S[i]>0){
				for(int j=limit-1; j>=S[i]; j--){
					dp[j] = max(dp[j-S[i]]+F[i],dp[j]);
				}
			}else{
				for(int j=0; j<limit+S[i]; j++){
					dp[j] = max(dp[j-S[i]]+F[i], dp[j]);
				}
			}
		}

		int ans = -1;
		for(int i=100000; i<limit; i++){
			if(dp[i]>=0){
				ans = max(ans, dp[i]+i-100000);
			}
		}
		System.out.println(ans);

	}

	public static int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}

}
