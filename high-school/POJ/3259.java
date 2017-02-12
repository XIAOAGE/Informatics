import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static class edge{
		
		private int start;
		private int end;
		private int cost;
		private boolean isWormHole;
		
		public edge(int a, int b, int c, boolean d){
			start = a;
			end = b;
			cost = c;
			isWormHole = d;
		}
		
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		while(number!=0){
			number--;
			
			int N = in.nextInt();
			int M = in.nextInt();
			int W = in.nextInt();
			edge[] arr = new edge[M+W];
			int count = 0;
			for(int p=0; p<M; p++){
				int S = in.nextInt();
				int E = in.nextInt();
				int T = in.nextInt();
				arr[count++] = new edge(S, E, T, false);
			}
			for(int p=0; p<W; p++){
				int S = in.nextInt();
				int E = in.nextInt();
				int T = in.nextInt();
				arr[count++] = new edge(S, E, -1*T, true);
			}
			
			//Bellman-Ford Algorithm.....
			final int INF = 100000000;
			int[] d = new int[N];
			Arrays.fill(d, INF);
			d[0] = 0;
			for(int k=0; k<N; k++){
				for(int i=0; i<M+W; i++){
					edge e = arr[i];
					int start = e.start-1;
					int end = e.end-1;
					int cost = e.cost;
					boolean isWormHole = e.isWormHole;
					if(d[start]+cost<d[end]){
						d[end] = d[start]+cost;
					}
					if(!isWormHole){
						if(d[end]+cost<d[start]){
							d[start] = d[end] + cost;
						}
					}
				}
			}
			
			boolean YorN = false;
			
			for(int i=0; i<M+W; i++){
				edge e = arr[i];
				int start = e.start-1;
				int end = e.end-1;
				int cost = e.cost;
				if(d[start]+cost<d[end]){
					YorN = true;
				}
			}
			if(YorN){
				System.out.println("YES");
			}else{
				System.out.println("NO");
			}
			
		}
		
	}
	
}
