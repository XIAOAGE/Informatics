import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		while(number--!=0){
			long M = in.nextLong();
			long H = in.nextLong();
			
			long sum = 0;
			for(int i=0; i<H; i++){
				long A = in.nextInt();
				long B = in.nextInt();
				sum += mod_pow(A,B,M);
			}
			System.out.println(sum%M);
		}
		
	}
	
	public static long mod_pow(long x, long a, long M){
		long res = 1;
		while(a>0){
			if((a&1)==1){res = res * x % M;}
			x = x * x % M;
			a>>=1;
		}
		return res;
	}
	
}
