import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		double[] arr = new double[N];

		for(int i=0; i<N; i++){
			arr[i] = in.nextDouble();
		}

		Arrays.sort(arr);
		if(arr.length==1){
			System.out.printf("%.3f\n", arr[0]);
		}else{
			double start = formula(arr[arr.length-1], arr[arr.length-2]);
			for(int i=arr.length-3; i>=0; i--){
				start = formula(start, arr[i]);
			}
			System.out.printf("%.3f\n", start);
		}

	}

	public static double formula(double a, double b){
		double ans = 2.0 * Math.sqrt(a*b);
		return	ans;
	}

}
