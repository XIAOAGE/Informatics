import java.util.Arrays;
import java.util.Scanner;

public class Main{

	static int[][] graph;
	static int[] match;
	static int N;
	static int K;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		K = in.nextInt();
		graph = new int[N+1][N+1];
		for(int i=0; i<K; i++){
			int R = in.nextInt();
			int C = in.nextInt();
			graph[R][C] = 1;
		}
		System.out.println(Max_BPM());
		
	}
	
	//N is the number of rows (applicants)
	//K is the number of colmns (jobs)
	public static int Max_BPM(){
		match = new int[N+1];
		Arrays.fill(match, -1);
		int result = 0;
		for(int i=1; i<=N; i++){
			boolean[] visited = new boolean[N+1];
			
			if(dfs(i, visited)){
				result++;
			}
		}	
		return result;
	}
	
	public static boolean dfs(int current, boolean[] visited){
		for(int i=1; i<=N; i++){
			if(graph[current][i]==1 && !visited[i]){
				visited[i] = true;
				if(match[i]==-1 || dfs(match[i], visited)){
					match[i] = current;
					return true;
				}
			}
		}
		return false;
	}
	
}
