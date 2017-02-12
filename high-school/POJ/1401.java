import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		for(int i=0; i<number; i++){
			
			int num = in.nextInt();
			int answer = 0;
			int count = 1;
			while(Math.pow(5, count)<=num){
				answer += num/Math.pow(5, count);
				count++;
			}
			System.out.println(answer);
			
		}
		
	}
	
}
