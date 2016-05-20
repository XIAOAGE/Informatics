import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Main {

	static class node{
		
		private int x;
		private int y;
		private int move;
		
		public node(int a, int b, int c){
			x = a;
			y = b;
			move = c;
		}
		
	}
	
	static int[] dx = {2,2,1,1,-1,-1,-2,-2};
	static int[] dy = {1,-1,2,-2,2,-2,1,-1};
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			
			String line = in.nextLine();
			int startY = line.charAt(0)-'a';
			int startX = line.charAt(1)-49;
			int endY = line.charAt(3)-'a';
			int endX = line.charAt(4)-49;
			
			Queue<node> qu = new LinkedList<node>();
			node start = new node(startX, startY, 0);
			qu.offer(start);
			
			int move = 0;
			
			label:
			while(!qu.isEmpty()){
				
				node current = qu.poll();
				int x = current.x;
				int y = current.y;
				
				if(x==endX && y==endY){
					break;
				}
				
				for(int i=0; i<8; i++){
					
					int nextX = x+dx[i];
					int nextY = y+dy[i];
				
					if(nextX==endX && nextY==endY){
						move = current.move+1;
						break label;
					}
					
					if(nextX>=0 && nextX <=7 && nextY>=0 && nextY<=7){
						node next = new node(nextX, nextY, current.move+1);
						qu.add(next);
					}
					
				}
				
			}
			
			System.out.printf("To get from %s to %s takes %d knight moves.\n", line.substring(0, 2), line.substring(3,5), move);
			
		}
		
	}
	
}
