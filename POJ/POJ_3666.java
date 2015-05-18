import java.util.Scanner;


public class POJ_3666 {

	static int[] dp;
	static int len;
	static int[] arr;
	static int number;
 	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		number = in.nextInt();
		arr = new int[number+1];
		for(int i=1; i<=number; i++){
			arr[i] = in.nextInt();
		}
		
		dp = new int[number+1];
        dp[1] = arr[1];
        dp[0] = -1000000;

        len = 1;
        for(int i=2; i<=number; i++){
            if(arr[i]>=dp[len]){
                dp[++len] = arr[i];
            }else{
                int pos = binary_search(i);
                dp[pos] = arr[i];
            }
        }

        for(int x: dp){
        	System.out.print(x+" ");
        }
        System.out.println();
        
        System.out.println(len);
		
	}
	
	public static int binary_search(int i){

        int left, right, mid;
        left = 0;
        right = len;

        while(left<right){
            mid = (right+left)/2;
            if(dp[mid]>=arr[i]) right=mid;
            else left=mid+1;
        }
        return left;

    }
	
}
