import java.util.Scanner;


public class Main{
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		double A = in.nextDouble();
		int L = in.nextInt();
		
		int v1 = -1;
		int v2 = -1;
		int m = 1;
		int n = 1;
		double min = A;
		double ans;
		
		while(m<=L && n<=L){
			ans = m*1.0/n*1.0;
			if(ans>=A){
				if(min>ans-A){
					min = ans-A;
					v1 = m;
					v2 = n;
				}
				n++;
			}else if(ans<A){
				if(min>A-ans){
					min = A-ans;
					v1 = m;
					v2 = n;
				}
				m++;
			}
		}
		System.out.println(v1+" "+v2);
		
	}
	
}
