import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		long[] arr = new long[number];
		for(int i=0; i<number; i++){
			arr[i] = in.nextLong();
		}
		
		Arrays.sort(arr);
		long ans = 0;
		for(int i=0; i<number; i++){
			for(int j=i+1; j<number; j++){
				ans += arr[j]-arr[i];
			}
		}
		System.out.println(ans*2);
		
	}
	
	
}
