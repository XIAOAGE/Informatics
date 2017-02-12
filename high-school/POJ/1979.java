import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Main {

	static int[] dx = {0,0,-1,1};
	static int[] dy = {1,-1,0,0};

	static class node{

		private int x;
		private int y;

		public node(int a, int b){
			x = a;
			y = b;
		}

	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(true){

			int answer = 0;

			int W = in.nextInt();
			if(W==0){break;}
			int H = in.nextInt();

			int startX = 0;
			int startY = 0;

			int[][] arr = new int[H][W];
			boolean[][] used = new boolean[H][W];

			String crap = in.nextLine();

			for(int i=0; i<H; i++){
				String line = in.nextLine();
				for(int a=0; a<line.length(); a++){
					char temp = line.charAt(a);
					if(temp=='.'){
						arr[i][a] = 1;
					}else if(temp=='@'){
						answer+=1;
						used[i][a] = true;
						startX = i;
						startY = a;
					}
				}
			}

			Queue<node> qu = new LinkedList<node>();
			node start = new node(startX,startY);
			qu.offer(start);

			while(!qu.isEmpty()){
				node current = qu.poll();
				int curX = current.x;
				int curY = current.y;
				for(int p=0; p<4; p++){
					int x = curX + dx[p];
					int y = curY + dy[p]; 
					if(x>=0 && x<=H-1 && y>=0 && y<=W-1 && arr[x][y]==1 && !used[x][y]){
						used[x][y] = true;
						answer+=1;
						node add = new node(x,y);
						qu.offer(add);
					}
				}
			}
			System.out.println(answer);
		}

	}

}
