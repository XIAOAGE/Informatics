import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int W = in.nextInt();
		
		int[][] dp = new int[T+1][W+1];
		
		for(int i=1; i<=T; i++){
			int apple = in.nextInt();
			for(int a=0; a<=W; a++){
				if((W-a) % 2==0){
					
					if(apple==1){
						if(a==0){
							dp[i][a] = dp[i-1][a]+1;
						}else{
							dp[i][a] = max(dp[i-1][a], dp[i-1][a-1])+1;
						}
					}else{
						if(a==0){
							dp[i][a] = dp[i-1][a];
						}else{
							dp[i][a] = max(dp[i-1][a], dp[i-1][a-1]);
						}
					}
					
				}else{
					
					if(apple==2){
						if(a==0){
							dp[i][a] = dp[i-1][a]+1;
						}else{
							dp[i][a] = max(dp[i-1][a], dp[i-1][a-1])+1;
						}
					}else{
						if(a==0){
							dp[i][a] = dp[i-1][a];
						}else{
							dp[i][a] = max(dp[i-1][a], dp[i-1][a-1]);
						}
					}
					
				}
			}
		}
		
		int answer = 0;
		for(int i=0; i<=W; i++){
			if(dp[T][i]>answer){
				answer = dp[T][i];
			}
		}
		
		System.out.println(answer);
		
	}
	
	public static int max(int a,int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	
}
