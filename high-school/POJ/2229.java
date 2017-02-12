import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		int[] dp = new int[number+1];
		dp[1] = 1;
		
		for(int i=2; i<=number; i++){
			if(i%2==0){
				dp[i] = dp[i-1]+dp[i/2];
			}else{
				dp[i] = dp[i-1];
			}
			dp[i] %= 1000000000;
		}

		System.out.println(dp[number]);
	}
	
}
