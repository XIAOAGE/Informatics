import java.util.Scanner;


public class Main{

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			int s = in.nextInt();
			int d = in.nextInt();
			int ans = 0;
			if(s*4<d){
				ans = 10*s-2*d;
			}else if(s*3<2*d){
				ans = 8*s-4*d;
			}else if(s*2<3*d){
				ans = 6*s-6*d;
			}else if(s<4*d){
				ans = 3*s-9*d;
			}else{
				ans = -1;
			}
			if(ans<0){
				System.out.println("Deficit");
			}else{
				System.out.println(ans);
			}
		}
		
	}
	
}
