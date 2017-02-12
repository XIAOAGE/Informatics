import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		int time = in.nextInt();
		int limit = in.nextInt();
		int[] distance = new int[time+1];
		
		for(int i=1; i<=time; i++){
			distance[i] = in.nextInt();
		}
		
		int[][] dp = new int[time+1][limit+1];
		
		for(int i=1; i<time+1; i++){
			for(int j=0; j<=limit; j++){
				if(j==0){
					dp[i][j] = dp[i-1][j];
					for(int k=1; k<=limit && k<=i; k++){
						dp[i][j] = max(dp[i][j], dp[i-k][k]);
					}
				}else{
					dp[i][j] = dp[i-1][j-1] + distance[i];
				}
			}
		}
		
		System.out.println(dp[time][0]);
		
	}
	
	public static int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	
}
