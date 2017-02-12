import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		for(int i=0; i<number; i++){
			
			int sum = in.nextInt();
			int difference = in.nextInt();
			
			double x=0;
			double y=0;
			
			x = (sum+difference)/2.0;
			y = x - difference;
			
			if(y<0){
				System.out.println("impossible");
			}else if(Math.floor(x+0.5)!=x){
				System.out.println("impossible");
			}else{
				System.out.printf("%d %d\n", (int)x, (int)y);
			}
			
		}
		
	}
	
}
