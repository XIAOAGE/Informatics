import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static long[] a;
	static long[] b;
	static int n;
	static int k;
	static final double INF = 1.1;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		while(true){
			n = in.nextInt();
			k = in.nextInt();
			if(n==0){
				break;
			}
			
			a = new long[n];
			b = new long[n];
			for(int i=0; i<n; i++){
				a[i] = in.nextLong();
			}
			for(int i=0; i<n; i++){
				b[i] = in.nextLong();
			}
			double ans = binary_search()*100;
			System.out.println(Math.round(ans));
		}
		
	}
	
	public static double binary_search(){
		double high = INF;
		double low = 0;
		
		while(high-low>0.00001){
			double mid = (high+low)/2.0;
			if(check(mid)){
				low = mid;
			}else{
				high = mid;
			}
		}
		return low;
	}
	
	public static boolean check(double x){
		double[] y = new double[n];
		for(int i=0; i<n; i++){
			y[i] = a[i]*1.0-x*b[i];
		}
		Arrays.sort(y);
		double res = 0;
		for(int i=n-1; i>k-1; i--){
			res += y[i];
		}
		return res>=0;
	}
	
}
