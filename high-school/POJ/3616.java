import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static class interval implements Comparable<interval>{
		
		private int start;
		private int end;
		private int efficient;
		
		public interval(int a, int b, int c){
			start = a;
			end = b;
			efficient = c;
		}

		@Override
		public int compareTo(interval o) {
			if(this.start<o.start){
				return -1;
			}else if(this.start>o.start){
				return 1;
			}
			return 0;
		}
		
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		int R = in.nextInt();
		
		interval[] arr = new interval[M];
		for(int i=0; i<M; i++){
			int start = in.nextInt();
			int end = in.nextInt();
			int efficient = in.nextInt();
			interval temp = new interval(start, end+R, efficient);
			arr[i] = temp;
 		}
		
		int[] dp = new int[M];
		Arrays.sort(arr);
		
		for(int i=0; i<M; i++){
			dp[i] = arr[i].efficient;
			for(int j=0; j<i; j++){
				if (arr[j].end <= arr[i].start)
	            {
	                dp[i] = max(dp[i], dp[j] + arr[i].efficient);
	            }
			}
		}
		Arrays.sort(dp);
		System.out.println(dp[M-1]);
		
	}
	
	public static int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	
}
