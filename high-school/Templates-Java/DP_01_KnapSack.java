import java.util.Scanner;

public class DP_01_KnapSack {

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
            for(int j=w; j>=weight[i]; j--){           // we need to end weight[i] here.
                dp[j] =  Integer.max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
        System.out.println(dp[w]);

    }

}
