/*

This is the famous Longest Increasing Subsquence Problem.
We use a dp array to keep track the minimum ending number for sequence with different length.
we start with the first element, and it can be sequence with length of 1. Then the minimum number so
far for length 1 is the first element. obvious
Notice when are doing the binart search, we only search from 0 to len.
The reason for up to len is straight, but for 0 is implicit.
We need 0 because if the our current element happens to be the least number in the array. We just ditch
it there. So index 0 is a useful crap.

 */

import java.util.Scanner;

public class LIS_Problem_nlogn {

    static int number;
    static int[] dp;
    static int[] arr;
    static int len;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the length of sequence");
        number = in.nextInt();
        System.out.println("put the elements in the array below");
        arr = new int[number+1];
        for(int i=1; i<=number; i++){
            arr[i] = in.nextInt();
        }
        // above is input reading

        dp = new int[number+1];
        dp[1] = arr[1];

        len = 1;
        for(int i=2; i<=number; i++){
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
