import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;


public class Main {

	static class node{

		int end;
		int dis;

		public node(int a, int b){
			end = a;
			dis = b;
		}

	}

	static boolean[][] visited;
	static int[][] count;
	static int[][] dist;
	static final int INF = 100000009; 

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int numOfCase = in.nextInt();

		while(numOfCase--!=0){

			int N = in.nextInt();
			int M = in.nextInt();

			visited = new boolean[N+1][2];
			count = new int[N+1][2];
			dist = new int[N+1][2];

			Map<Integer, LinkedList<node>> map = new HashMap<Integer, LinkedList<node>>();
			for(int i=0; i<M; i++){
				int A = in.nextInt();
				int B = in.nextInt();
				int L = in.nextInt();

				node temp = new node(B, L);
				if(map.get(A)==null){
					LinkedList<node> list = new LinkedList<node>();
					list.add(temp);
					map.put(A, list);
				}else{
					map.get(A).add(temp);
				}
			}

			int S = in.nextInt();
			int F = in.nextInt();
			count[S][0] = 1;
			for(int i=1; i<=N; i++){
				for(int j=0; j<2; j++){
					dist[i][j] = INF;
				}
			}
			dist[S][0] = 0;

			for(int i=1; i<=2*N-1; i++){
				
				int min = INF;
				int x = -1;
				int y = -1;
				for(int j=1; j<=N; j++){
					if(!visited[j][0] && min>dist[j][0]){
						min = dist[j][0];
						x=j;
						y = 0;
					}else if(!visited[j][1] && min>dist[j][1]){
						min = dist[j][1];
						x = j;
						y = 1;
					}
				}
				
				if(min==INF){break;}
				visited[x][y]  =true;
				LinkedList<node> kids = map.get(x);
				if(kids==null){continue;}
				
				for(int j=0; j<kids.size(); j++){
					node now = kids.get(j);
					int end = now.end;
					int distance = now.dis + min;
					if(distance<dist[end][0]){
						dist[end][1] = dist[end][0];
						count[end][1] = count[end][0];
						dist[end][0] = distance;
						count[end][0] = count[x][y];
					}else if(distance==dist[end][0]){
						count[end][0] += count[x][y];
					}else if(distance<dist[end][1]){
						dist[end][1] = distance;
						count[end][1] = count[x][y];
					}else if(distance==dist[end][1]){
						count[end][1] += count[x][y];
					}
				}
				
			}

			if(dist[F][0]+1==dist[F][1]){
				System.out.println(count[F][0]+count[F][1]);
			}else{
				System.out.println(count[F][0]);
			}

		}

	}

}
