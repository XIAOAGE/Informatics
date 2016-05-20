import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		
		Scanner keyboard = new Scanner(System.in);
		Double n;
		Double result;
		Double length;
		while(keyboard.hasNext()){
			length = keyboard.nextDouble();
			n = 2.0;
			result = 0.00;
			if(length==0.0){
				break;
			}
			while(result<=length){
				result = result + (1/n);
				n++;
			}
			System.out.println((int)(n-2) + " card(s)");
		}	
	}
	
}
