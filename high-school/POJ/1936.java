import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			
			char[] s = in.next().toCharArray();
			char[] t = in.next().toCharArray();
			
			int[][] dp = new int[s.length+1][t.length+1];
			
			for(int i=1; i<=s.length; i++){
				for(int j=1; j<=t.length; j++){
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
					if(s[i-1]==t[j-1]){
						dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
					}
				}
			}
			if(dp[s.length][t.length]==s.length){
				System.out.println("Yes");
			}else{
				System.out.println("No");
			}
		}
		
	}
	
	public static int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	
}
