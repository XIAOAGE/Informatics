import java.util.Scanner;

/*
The main point in this algorithm is to transform word1 to word2
Notice: The cost for insertion, deletion and replace have to be equal.
 */

public class DP_Edit_Distance {

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the first string");
        String word1 = in.nextLine();
        System.out.println("Enter the second string");
        String word2 = in.nextLine();
        System.out.println("Enter the cost for insertion, deletion and replace");
        int insertion = in.nextInt();
        int deletion = in.nextInt();
        int replace = in.nextInt();

        int[][] dp = new int[word1.length()+1][word2.length()+1];

        for(int i=0; i<=word1.length(); i++){
            dp[i][0] = i*deletion;
        }

        for(int i=0; i<=word2.length(); i++){
            dp[0][i] = i*insertion;
        }

        for(int i=1; i<=word1.length(); i++){
            for(int j=1; j<=word2.length(); j++){
                dp[i][j] = 100000;
                if(word1.charAt(i-1)==word2.charAt(j-1)) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i - 1][j - 1]+replace;
                int temp1 = dp[i-1][j] + deletion;       //to delete
                int temp2 = dp[i][j-1] + insertion;      //to insert
                dp[i][j] = min(temp1, min(temp2,dp[i][j]));
            }
        }

        System.out.println("The minimum cost to edit is " + dp[word1.length()][word2.length()]);

    }

    public static int min(int a, int b){
        if(a<b){
            return a;
        }else{
            return b;
        }
    }

}
