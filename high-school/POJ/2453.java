import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(true){
			
			int number = in.nextInt();
			if(number==0){
				break;
			}
			int oneNumber = checkOne(number);
			
			while(checkOne(++number)!=oneNumber){	
			}
			
			System.out.println(number);
			
		}
		
	}
	
	public static int checkOne(int number){
		int oneNumber = 0;
		for(int i=0; i<=20; i++){
			if(((number>>i) & 1) == 1){
				oneNumber+=1;
			}
		}
		return oneNumber;
	}
	
}
