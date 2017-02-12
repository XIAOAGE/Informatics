import java.util.Scanner;

public class Main {

	static int[] dir;
	static int[] f;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		int round = Integer.parseInt(in.nextLine());
		dir = new int[round];
		
		for(int i=0; i<round; i++){
			String next = in.nextLine();
			if(next.equals("B")){
				dir[i] = 1;
			}else if(next.equals("F")){
				dir[i] = 0;
			}
		}
		
		int M = round+1;
		int K = 0;
		
		for(int i=1; i<=round; i++){
			f = new int[round];
			int temp = solve(i);
			if(temp>0 && M>temp){
				M = temp;
				K = i;
			}
		}
		
		System.out.println(K+" "+M);
		
	}
	
	public static int solve(int k){

		int sum = 0;
		int res = 0;
		
		for(int i=0; i+k<=dir.length; i++){
			
			if((dir[i]+sum) % 2 != 0){
				f[i] = 1;
				res++;
			}
			
			sum+=f[i];
			
			if(i-k+1>=0){
				sum -= f[i-k+1];
			}
			
		}
		
		for(int i = dir.length-k+1; i<dir.length; i++){
			if((dir[i] + sum) % 2 != 0){
				return -1;
			}
			
			if(i-k+1>=0){
				sum -= f[i-k+1];
			}
			
		}
		
		return res;
		
	}
	
}
