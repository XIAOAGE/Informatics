import java.util.Scanner;


public class Main {
	
	static int[] arr;
	static int C = 0;
	static int N = 0;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		C = in.nextInt();
		
		arr = new int[N];
		for(int i=0; i<N; i++){
			arr[i] = in.nextInt();
		}
		
		for(int i=0; i<N-1; i++){
			if(arr[i]>arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
		
		int lb = 0;
		int ub = Integer.MAX_VALUE;
		
		while(ub-lb>1){
			int mid = (ub+lb)/2;
			if(c(mid)) lb = mid;
			else ub = mid;
		}
		System.out.println(lb);
	}
	
	public static boolean c(int d){
		int last = 0;
		for(int i=1; i<C; i++){
			int cur = last+1;
			while(cur<N && arr[cur]-arr[last]<d){
				cur++;
			}
			if(cur==N){return false;}
			last = cur;
		}
		return true;
	}
	
}
