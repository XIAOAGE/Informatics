import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static final int INF = 1000000;
	
	static class edge{
		int start;
		int end;
		int dis;
		
		public edge(int a,int b, int c){
			start = a;
			end = b;
			dis = c;
		}
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int N = in.nextInt();
		
		edge[] edge = new edge[T];
		for(int i=0; i<T; i++){
			int start = in.nextInt();
			int end = in.nextInt();
			int dis = in.nextInt();
			edge[i] = new edge(start, end, dis);
		}
		
		int[] d = new int[N+1];
		Arrays.fill(d, INF);
		d[N] = 0;
		
		for(int i=1; i<=N-1; i++){
			for(int j=0; j<edge.length; j++){
				edge e = edge[j];
				int start = e.start;
				int end = e.end;
				int dis = e.dis;
				if(d[start]+dis<d[end]){
					d[end] = d[start]+dis;
				}
				if(d[end]+dis<d[start]){
					d[start] = d[end]+dis;
				}
			}
		}
		System.out.println(d[1]);
		
	}
	
}
