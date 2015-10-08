import java.util.Scanner;

/*
If the problem wants to count the number of occurance of a string in the other string, watch that
u need expand the array to b.length+1;
 */

public class String_KMP {

    static int[] next;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        String a = in.nextLine();
        String b = in.nextLine();
        next = new int[b.length()];

        GetNext(b);
        if(KMP(a,b)){
            System.out.println("a contains b");
        }else{
            System.out.println("Nope");
        }

    }

    public static boolean KMP(String a, String b){
        int i=0,j=0;
        while(i<a.length() && j<b.length()){
            if(j==-1 || a.charAt(i)==b.charAt(j)){
                i++;
                j++;
            }else{
                j = next[j];
            }
        }

        if(j==b.length()){
            return true;
        }else{
            return false;
        }
    }

    public static void GetNext(String b){

        int i=0, j=-1;
        next[0] = -1;

        while(i<b.length()-1){
            if(j==-1 || b.charAt(i)==b.charAt(j)) {
                next[++i] = ++j;
            }else{
                j = next[j];
            }
        }

    }

}
