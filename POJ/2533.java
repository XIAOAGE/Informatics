import java.util.Scanner;

public class Main {

    static int[] dp;
    static int[] arr;
    static int N;
    static int len;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        N = in.nextInt();

        arr = new int[N+1];

        for(int i=1; i<=N; i++){
            arr[i] = in.nextInt();
        }

        dp = new int[N+1];
        dp[1] = arr[1];
        len = 1;

        for(int i=2; i<=N; i++){
            if(arr[i]>dp[len]){
                dp[++len] = arr[i];
            }else{
                int pos = binary_search(i);
                dp[pos] = arr[i];
            }
        }
        System.out.println(len);

    }

    public static int binary_search(int i){

        int left=0, right=len, mid;
        while(left<right){
            mid = (left+right)/2;
            if(dp[mid]>=arr[i]){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        return left;

    }

}
