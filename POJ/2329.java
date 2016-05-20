import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Main{

	static int[][] map;
	static int[][] result;

	static class node{
		int x;
		int y;
		int distance;

		public node(int a, int b, int c){
			x = a;
			y = b;
			distance = c;
		}
	}

	static int N;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			N = in.nextInt();
			map = new int[N][N];
			result = new int[N][N];

			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					int number = in.nextInt();
					map[i][j] = number;
					result[i][j] = number;
				}
			}

			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					if(map[i][j]==0){
						result[i][j] = bfs(i,j);
					}
				}
			}

			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					System.out.print(result[i][j]+" ");
				}
				System.out.println();
			}
		}

	}

	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,1,-1};

	public static int bfs(int x, int y){
		Queue<node> qu = new LinkedList<node>();
		node start = new node(x, y, 0);
		qu.add(start);
		boolean[][] visited = new boolean[N][N];
		visited[x][y] = true;

		int number = 0;
		int current_distance = 0;
		while(!qu.isEmpty()){
			node current = qu.poll();
			int distance = current.distance;
			int X = current.x;
			int Y = current.y;
			if(distance!=current_distance && number!=0){
				return number;
			}else if(distance!=current_distance){
				current_distance = distance;
			}
			if(number==0 && map[X][Y]!=0){
				number = map[X][Y];
			}else if(number!=0 && map[X][Y]!=0){
				return 0;
			}
			for(int i=0; i<4; i++){
				int nextX = X+dx[i];
				int nextY = Y+dy[i];
				if(nextX>=0 && nextX<N && nextY>=0 && nextY<N && !visited[nextX][nextY]){
					visited[nextX][nextY] = true;
					qu.add(new node(nextX, nextY, distance+1));
				}
			}
		}
		return number;
	}

}
