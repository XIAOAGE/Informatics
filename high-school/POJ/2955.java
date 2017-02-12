import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(true){
			String line = in.nextLine();
			if(line.equals("end")){
				break;
			}
			char[] arr = line.toCharArray();
			
			int[][] dp = new int[arr.length][arr.length];
			int ans = -1;
			for(int i=0; i<arr.length; i++){
				for(int j=0, k=i; k<arr.length; j++, k++){
					if(arr[j]=='(' && arr[k]==')' || arr[j]=='[' && arr[k]==']'){
						dp[j][k] = 2 + dp[j+1][k-1];
					}
					for(int p=j+1; p<k; p++){
						if(dp[j][p]+dp[p][k]>dp[j][k]){
							dp[j][k] = dp[j][p]+dp[p][k];
						}
					}
					if(dp[j][k]>ans){ans=dp[j][k];}
				}
			}
			System.out.println(ans);
		}
		
	}
	
}
