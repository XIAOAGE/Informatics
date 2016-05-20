import java.util.Scanner;


public class Main {

	static int M;
	static int N;
	static int[][] tile;
	static int[][] opt;
	static int[][] flip;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		M = in.nextInt();
		N = in.nextInt();
		tile = new int[M][N];
		opt = new int[M][N];
		
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				tile[i][j] = in.nextInt();
			}
		}
		solve();
		
	}
	
	public static void solve(){
		
		int res = Integer.MAX_VALUE;
		for(int i=0; i< 1<<N; i++){
			flip = new int[M][N];
			for(int j=0; j<N; j++){
				flip[0][N-j-1] = i >> j & 1;
			}
			int num = calc();
			if(num!=-1 && res>num){
				res = num;
				for(int p=0; p<M; p++){
					for(int j=0; j<N; j++){
						opt[p][j] = flip[p][j];
					}
				}
			}
		}
		
		if(res==Integer.MAX_VALUE){
			System.out.println("IMPOSSIBLE");
		}else{
			for(int i=0; i<M; i++){
				for(int j=0; j<N; j++){
					System.out.print(opt[i][j]+" ");
				}
				System.out.println();
			}
		}
		
	}
	
	public static int calc(){
		
		for(int i=1; i<M; i++){
			for(int j=0; j<N; j++){
				if(get(i-1,j)==1){
					flip[i][j] = 1;
				}
			}
		}
		
		for(int i=0; i<N; i++){
			if(get(M-1,i)==1){
				return -1;
			}
		}
		
		int output = 0;
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				output += flip[i][j];
			}
		}
		
		return output;
		
	}
	
	static int[] dx = {1,-1,0,0,0};
	static int[] dy = {0,0,1,-1,0};
	
	public static int get(int x, int y){
		
		int ans = tile[x][y];
		for(int i=0; i<5; i++){
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if(nextX>=0 && nextX<M && nextY>=0 && nextY<N){
				ans += flip[nextX][nextY];
			}
		}
		
		return ans % 2;
		
	}
	
}
