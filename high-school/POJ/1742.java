import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		while(true){
			int n = in.nextInt();
			int m = in.nextInt();	
			if(n==0){break;}
			int[] A = new int[n];
			int[] C = new int[n];
			for(int i=0; i<n; i++){
				A[i] = in.nextInt();
			}
			for(int i=0; i<n; i++){
				C[i] = in.nextInt();
			}
			int[] dp = new int[m+1];
			Arrays.fill(dp, -1);
			dp[0] = 0;
			for(int i=0; i<n; i++){
				for(int j=0; j<=m; j++){
					if(dp[j]>=0){
						dp[j] = C[i];
					}else if(j<A[i] || dp[j-A[i]]<=0){
						dp[j] = -1;
					}else{
						dp[j] = dp[j-A[i]]-1;
					}
				}
			}
			int ans = 0;
			for(int x: dp){
				if(x>=0){
					ans+=1;
				}
			}
			System.out.println(ans-1);
 		}
		
	}
	
}
