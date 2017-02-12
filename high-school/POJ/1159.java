import java.util.Scanner;


public class Main {
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int len = Integer.parseInt(in.nextLine());
		String word = in.nextLine();
		short[][] dp = new short[len][len];
		
		for(int i=1; i<len; i++){
			for(int j=0; j+i<len; j++){
				dp[j][j+i] = min((short)(dp[j][j+i-1]+1), (short)(dp[j+1][j+i]+1));
				if(word.charAt(j)==word.charAt(j+i)){
					dp[j][j+i] = min(dp[j+1][j+i-1], dp[j][j+i]);
				}
			}
		}
		System.out.println(dp[0][len-1]);
		
	}
	
	public static short min(short a, short b){
		if(a<b){
			return a;
		}else{
			return b;
		}
	}
	
}
