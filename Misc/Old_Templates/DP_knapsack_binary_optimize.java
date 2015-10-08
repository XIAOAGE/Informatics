import java.util.Scanner;

/*
 * You have to use 1D array, otherwise, for the zeroone_knapsack part, it will be messed.
 */

/*
Problem is from poj 1742
 */

public class DP_knapsack_binary_optimize {

    static int[] n;
    static int[] v;
    static int high;
    static boolean[] dp;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        while(true){
            int num = in.nextInt();
            if(num==0){break;}
            high = in.nextInt();
            n = new int[num+1];         //n is the number of object
            v = new int[num+1];         //v is the value of each coin
            for(int i=0; i<num; i++){
                v[i+1] = in.nextInt();
            }
            for(int i=0; i<num; i++){
                n[i+1] = in.nextInt();
            }
            //code before is for input reading
            dp = new boolean[high+1];
            dp[0] = true;
            for(int i=1; i<=num; i++){
                multiple_knapsack(i);
            }
            int ans = 0;
            for(int i=1; i<=high; i++){
                if(dp[i]){
                    ans+=1;
                }
            }
            System.out.println(ans);
        }

    }

    public static void multiple_knapsack(int row){
        if(n[row]*v[row]>=high){
            complete_knapsack(row);
        }else{
            int k = 1;
            int M = n[row];
            //bellow is the key part
            while(k<M){
                zeroone_knapsack(k*v[row],row);
                M-=k;
                k*=2;
            }
            zeroone_knapsack(M*v[row],row);
        }
    }

    public static void zeroone_knapsack(int cost, int row){
        for(int i=high; i>=cost; i--){      //backward
            dp[i] = dp[i-cost] || dp[i];
        }
    }

    public static void complete_knapsack(int row){
        for(int i=v[row]; i<=high; i++){    //forward
            dp[i] = dp[i] || dp[i-v[row]];
        }
    }

}
