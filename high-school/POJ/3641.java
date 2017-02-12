import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		while(true){
			long p = in.nextLong();
			long a = in.nextLong();
			if(p==0){break;}
			if(mod_pow(a,p,p) && check_prime(p)){
				System.out.println("yes");
			}else{
				System.out.println("no");
			}
		}
		
	}
	
	public static boolean mod_pow(long x, long n, long mod){
		long begin = x;
		long res = 1;
		while(n>0){
			if((n&1)==1){res = res*x % mod;}
			x = x*x % mod;
			n>>=1;
		}
		if(res!=begin){
			return false;
		}
		return true;
	}
	
	public static boolean check_prime(long p){
		for(int i=2; i<=Math.sqrt(p); i++){
			if(p % i == 0){
				return true;
			}
		}
		return false;
	}
	
}
