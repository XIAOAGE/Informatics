import java.util.Scanner;

public class DP_Complete_KnapSack {

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int w = in.nextInt();

        int[] weight = new int[n];
        int[] value = new int[n];

        for(int i=0; i<n; i++){
            weight[i] = in.nextInt();
            value[i] = in.nextInt();
        }

        int[] dp = new int[w+1];

        for(int i=0; i<n; i++){
            for(int j=weight[i]; j<=w; j++){                   // start with weight[i]
                dp[j] = Integer.max(dp[j-weight[i]]+value[i],dp[j]);
            }
        }
        System.out.println(dp[w]);

    }

}
