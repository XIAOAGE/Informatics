import java.util.Scanner;

public class DP_LIS_Problem_n2 {

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array");
        int number = in.nextInt();
        int[] arr = new int[number+1];
        System.out.println("Enter the elements in the array on the following line");
        for(int i=1; i<=number; i++){
            arr[i] = in.nextInt();
        }

        int[] dp = new int[number+1];
        dp[1] = 1;
        int ans = 1;  //here has to be 1 notice

        for(int i=2; i<=number; i++){
            dp[i] = 1;
            for(int j=i; j>=1; j--){
                if(arr[i]>arr[j]){
                    dp[i] = Integer.max(dp[i], dp[j]+1);
                }
            }
            ans = Integer.max(ans, dp[i]);
        }
        System.out.println(ans);

    }

}
