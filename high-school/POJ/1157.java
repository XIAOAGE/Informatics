import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int F = in.nextInt();
		int V = in.nextInt();
		
		int[][] map = new int[F+1][V+1];
		for(int i=1; i<=F; i++){
			for(int j=1; j<=V; j++){
				map[i][j] = in.nextInt();
			}
		}
		
		int[][] dp = new int[F+1][V+1];
		
		for(int i=1; i<=F; i++){
			for(int j=i; j<=V; j++){
				if(j==i){
					dp[i][j] = dp[i-1][j-1]+map[i][j];
				}else{
					dp[i][j] = max(dp[i][j-1]-map[i][j-1]+map[i][j], dp[i-1][j-1]+map[i][j]);
				}
			}
		}
		
		int ans = -1;
		for(int i=F; i<=V; i++){
			ans = max(ans,dp[F][i]);
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
