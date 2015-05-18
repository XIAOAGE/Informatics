import java.util.Arrays;
import java.util.Scanner;

//In this problem the sort has to happen. Cuz, if u start with the one with the high altitude, the lower one can't pile on that.

public class POJ_2392 {
	
	static boolean[] dp;
	static int high = 400000;
	static brick[] arr;
	
	static class brick implements Comparable<brick>{
		int height;
		int altitude;
		int quantity;
		
		public brick(int a, int b, int c){
			height = a;
			altitude = b;
			quantity = c;
		}

		@Override
		public int compareTo(brick o) {
			if(o.altitude<this.altitude){
				return 1;
			}else{
				return -1;
			}
		}
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int K = in.nextInt();
		arr = new brick[K];
		for(int i=0; i<K; i++){
			brick temp = new brick(in.nextInt(), in.nextInt(), in.nextInt());
			arr[i] = temp;
		}
	
		Arrays.sort(arr);
		dp = new boolean[400001];
		dp[0] = true;
		
		for(int i=0; i<K; i++){
			multiple_knapsack(i);
		}
		
		int ans = 0;
		for(int i=1; i<=400000; i++){
			if(dp[i]){
				ans = i;
			}
		}
		System.out.println(ans);
		
	}
	
	public static void multiple_knapsack(int row){
        if(arr[row].height*arr[row].quantity>=high){
            complete_knapsack(row);
        }else{
            int k = 1;
            int M = arr[row].quantity;
            //bellow is the key part
            while(k<M){
                zeroone_knapsack(k*arr[row].height,row);
                M-=k;
                k*=2;
            }
            zeroone_knapsack(M*arr[row].height,row);
        }
    }

    public static void zeroone_knapsack(int cost, int row){
        for(int i=arr[row].altitude; i>=cost; i--){      //backward
            dp[i] = dp[i-cost] || dp[i];
        }
    }

    public static void complete_knapsack(int row){
        for(int i=arr[row].height; i<=arr[row].altitude; i++){    //forward
            dp[i] = dp[i] || dp[i-arr[row].height];
        }
    }
	
}
