import java.util.Scanner;
import java.util.Hashtable;

public class Main {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int length = in.nextInt();
		int row = in.nextInt();
		int score = 0;     // The score is bigger, the unsortness is more serious;
		Hashtable<String,Integer> map = new Hashtable<String,Integer>();
		String[] board = new String[row];
		
		for(int i=0; i<row; i++){
			//注意这里用nextline的话会得到一个空的string。
			String line = in.next();
			board[i] = line;
			score = 0;
			for(int a=0; a<length-1; a++){
				for(int c=a+1; c<length; c++){
					if((line.charAt(a)-line.charAt(c))>0){
						score += 1;
					}
				}
			}
			map.put(line, score);
		}
		
		int minIndex;
		for(int t=0; t<row-1; t++){
			minIndex = t;
			for(int v= t+1; v<row; v++){
				if(map.get(board[minIndex])>map.get(board[v])){
					minIndex = v;
				}
			}
			String temp = board[minIndex];
			board[minIndex] = board[t];
			board[t] = temp;
		}
		
		for(String s: board){
			System.out.println(s);
		}
	}
}
