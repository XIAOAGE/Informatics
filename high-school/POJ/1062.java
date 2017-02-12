import java.util.Scanner;


public class Main{

	static int M;
	static int N;
	static people[] obj;

	static class people{
		int[] num;
		int[] new_price;
		int P;
		int L;
		int X;

		public people(int a, int b, int c){
			P = a;
			L = b;
			X = c;
			num = new int[X];
			new_price = new int[X];
		}
	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			M = in.nextInt();
			N = in.nextInt();
			obj = new people[N+1];
			for(int i=1; i<=N; i++){
				int P = in.nextInt();
				int L = in.nextInt();
				int X = in.nextInt();
				obj[i] = new people(P,L,X);
				for(int j=0; j<X; j++){
					int to_find = in.nextInt();
					int new_price = in.nextInt();
					obj[i].num[j] = to_find;
					obj[i].new_price[j] = new_price;
				}
			}
			boolean[] visited = new boolean[N+1];
			visited[1] = true;
			int ans = solve(1,obj[1].L, obj[1].L, visited);
			System.out.println(ans);
		}

	}

	public static int solve(int index, int low_level, int high_level, boolean[] visited){
		int res = obj[index].P;
		int number = obj[index].X;
		int level = obj[index].L;
		for(int i=0; i<number; i++){
			int next = obj[index].num[i];
			int new_price = obj[index].new_price[i];
			if(!visited[next] && Math.abs(obj[next].L-low_level)<=M && Math.abs(obj[next].L-high_level)<=M){
				visited[index] = true;
				int tmp1 = low_level;
				int tmp2 = high_level; 
				low_level = Math.min(low_level, level);
				high_level = Math.max(high_level, level);
				res = Math.min(res, new_price+solve(next, low_level, high_level, visited));
				low_level = tmp1;
				high_level = tmp2;
				visited[index] = false;
			}
		}
		return res;
	}

}
