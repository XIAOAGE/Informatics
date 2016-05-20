import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Main {

	static class node{
		int L;
		int R;
		int C;
		int time;

		public node(int a, int b, int c, int d){
			L = a;
			R = b;
			C = c;
			time = d;
		}
	}

	static int[] dx = {-1,1,0,0,0,0};
	static int[] dy = {0,0,1,-1,0,0};
	static int[] dz = {0,0,0,0,1,-1};

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(true){
			int L = in.nextInt();
			if(L==0){
				break;
			}
			int R = in.nextInt();
			int C = in.nextInt();
			String blank = in.nextLine();
			String[][][] map = new String[L][R][C];
			boolean[][][] visited = new boolean[L][R][C];

			int startL = -1;
			int startR = -1;
			int startC = -1;
			int endL = -1;
			int endR = -1;
			int endC = -1;

			for(int i=0; i<L; i++){
				for(int j=0; j<R; j++){
					String line = in.nextLine();
					for(int k=0; k<C; k++){
						map[i][j][k] = line.charAt(k)+"";
						if(line.charAt(k)=='S'){
							startL = i;
							startR = j;
							startC = k;
						}else if(line.charAt(k)=='E'){
							endL = i;
							endR = j;
							endC = k;
						}
					}
				}
				String blank2 = in.nextLine();
			}
			int ans = -1;
			node start = new node(startL , startR, startC,0);
			Queue<node> qu = new LinkedList<node>();
			qu.add(start);
			label:
				while(!qu.isEmpty()){
					node current = qu.poll();
					int z = current.L;
					int x = current.R;
					int y = current.C;
					int time = current.time;

					for(int i=0; i<6; i++){
						int nextL = z + dz[i];
						int nextX = x + dx[i];
						int nextY = y + dy[i];
						if(nextL>=0 && nextL<L && nextX>=0 && nextX<R && nextY>=0 && nextY<C){
							if(map[nextL][nextX][nextY].equals("E")){
								ans = time+1;
								break label;
							}else if(!visited[nextL][nextX][nextY] && map[nextL][nextX][nextY].equals(".")){
								qu.add(new node(nextL, nextX, nextY, time+1));
								visited[nextL][nextX][nextY] = true;    //mark visited should be here!!!
							}
						}
					}
				}
			if(ans==-1){
				System.out.println("Trapped!");
			}else{
				System.out.printf("Escaped in %d minute(s).\n", ans);
			}
		}

	}

}
