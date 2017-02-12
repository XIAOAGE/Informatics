import java.util.Scanner;


public class Main{
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		boolean[][] map = new boolean[4][4];
		for(int i=0; i<4; i++){
			String line = in.nextLine();
			for(int j=0; j<4; j++){
				if(line.charAt(j)=='+'){
					map[i][j] = !map[i][j];
					for(int k=0; k<4; k++){
						map[i][k] = !map[i][k];
						map[k][j] = !map[k][j];
					}
				}
			}
		}
		
		int result = 0;
		String output = "";
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(map[i][j]){
					result++;
					output += (i+1)+" "+(j+1)+"\n";
				}
			}
		}
		System.out.println(result);
		System.out.println(output);
		
	}
	
}
