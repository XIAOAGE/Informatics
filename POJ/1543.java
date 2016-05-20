import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		int[] table = new int[number+1];
		for(int i=1; i<=number; i++){
			table[i] = (int)Math.pow(i, 3);
		}
		
		for(int i=6; i<=number; i++){
			int left = table[i];
			for(int a=2; a<number; a++){
				for(int b=a; b<number; b++){
					for(int c=b; c<number; c++){
						if(left==table[a]+table[b]+table[c]){
							System.out.printf("Cube = %d, Triple = (%d,%d,%d)",i,a,b,c);
							System.out.println();
						}
					}
				}
			}
		}
		
	}
	
	
	
}
