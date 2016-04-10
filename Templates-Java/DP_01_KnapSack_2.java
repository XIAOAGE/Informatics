import java.util.Arrays;
import java.util.Scanner;

//For this knapSack problem, the weight is up to 10^9. We cannot afford it here. O(nW).

public class DP_01_KnapSack_2 {

    static final int INF = 10000000;

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

        int[] dp = new int[INF];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for(int i=0; i<n; i++){
            for(int j=INF-1; j>=value[i]; j--){
                dp[j] = Integer.min(dp[j], dp[j-value[i]]+weight[i]);
            }
        }

        int ans = 0;
        for(int i=1; i<INF;i++){
            if(dp[i]<=w){
                ans = i;
            }
        }
        System.out.println(ans);

    }

}

