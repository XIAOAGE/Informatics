import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		while(number--!=0){
			
			int pole = in.nextInt();
			int n = in.nextInt();
			
			int[] ant = new int[n];
			for(int i=0; i<n; i++){
				ant[i] = in.nextInt();
			}
			
			int min = -1;
			int max = -1;
			
			for(int x: ant){
				
				int time1 = pole-x;
				int time = time1>x?time1:x;
				int time2 = pole - time;
				max = time>max? time : max;
				min = time2>min? time2 : min;
				
			}
			System.out.printf("%d %d\n", min, max);
			
		}
		
	}
	
}
