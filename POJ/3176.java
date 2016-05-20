import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int layer = in.nextInt();
		int[][] table = new int[layer][layer];
		int[][] value = new int[layer][layer];
		
		for(int i=0; i<layer; i++){
			for(int a=0; a<=i; a++){
				table[i][a] = in.nextInt();
			}
		}
		
		value[0][0] = table[0][0];
		
		for(int i=1; i<layer; i++){		
			for(int a=0; a<=i; a++){
				if(a==0){
					value[i][a] = table[i][a] + value[i-1][a];
				}else if(a==i){
					value[i][a] = table[i][a] + value[i-1][a-1];
				}else{
					value[i][a] = table[i][a] + max(value[i-1][a], value[i-1][a-1]);
				}
			}
		}
		
		int answer = 0;
		for(int i=0; i<layer; i++){
			int temp = value[layer-1][i];
			answer = temp>answer?temp:answer;
		}
		
		System.out.println(answer);
		
	}
	
	public static int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}
	
}
