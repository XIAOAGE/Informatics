import java.util.Scanner;


public class Main {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(in.hasNext()){
			String line1 = in.nextLine();
			String line2 = in.nextLine();

			String[] arr = line1.split(" ");
			String[] arr2 = line2.split(" ");
			String word1 = arr[1];
			String word2 = arr2[1];

			int[] dp = new int[word2.length()+1];
			for(int i=0; i<dp.length; i++){
				dp[i] = i;
			}

			for(int i=1; i<=word1.length(); i++){
				int temp = dp[0];
				int temp2 = -1;
				dp[0] = i;
				for(int j=0; j<dp.length-1; j++){
					temp2 = dp[j+1];
					dp[j+1] = min(dp[j+1]+1, dp[j]+1);
					if(word1.charAt(i-1)==word2.charAt(j)){
						dp[j+1] = min(dp[j+1], temp);
					}else{
						dp[j+1] = min(dp[j+1], temp+1);
					}
					temp = temp2;
				}
			}

			System.out.println(dp[word2.length()]);
		}

	}

	public static int min(int a, int b){
		if(a<b){
			return a;
		}else{
			return b;
		}
	}

}
