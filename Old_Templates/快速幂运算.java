
/*
The Math equation needs to be prove: x^n mod n = x
usually, the data type is long(for convenience, using int here)
For more information, can go view POJ 3641
It's just a quicker way to compute x^n mod n
 */

import java.util.Scanner;

public class 快速幂运算 {

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int n = in.nextInt();
        int mod = in.nextInt();

        mod_pow(x, n, mod);

    }

    public static int mod_pow(int x, int n, int mod){
        int res = 1;
        while(n>0)
        {
            if((n&1)==1){res = res * x % mod;}
            x =  x * x % mod;
            n >>= 1;
        }
        return res;
    }

}
