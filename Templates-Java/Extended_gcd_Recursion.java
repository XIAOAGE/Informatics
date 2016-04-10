import java.util.Scanner;

//The deduct formula: x1=y2; y1=x2-(a/b)*y2.
//Theorm: gcd（a，b)=ax+by.

public class Extended_gcd_Recursion {

    static int x;
    static int y;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        exgcd(4,11);
        System.out.println(x+" "+y);

    }

    public static int exgcd(int a, int b){

        if(b==0){
            x=1;
            y=0;
            return a;
        }

        int r = exgcd(b, a%b);
        int temp = x;
        x = y;
        y = temp-(a/b)*y;

        return r;

    }

}
