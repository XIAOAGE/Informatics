import java.util.Scanner;

/*
n!/[k!(n-k)!]=n * (n – 1)…*(n – k + 1) / k!
 */

public class Combination {

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        System.out.println(c(n,k));
    }

    public static int c(int n, int k){
        int result = 1;
        for(int i=0; i<k; i++){
            result = result * (n-i) / (i+1);
        }
        return result;
    }

}
