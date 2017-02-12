import java.util.Scanner;


public class Main{

	static int[] map;
	static long[][] dp;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(in.hasNext()){
			int M = in.nextInt();
			int N = in.nextInt();
			map = new int[M];
			for(int i=0; i<M; i++){
				for(int j=0; j<N; j++){
					map[i] += Math.pow(2, j)*in.nextInt();
				}
			}
			dp = new long[M][(int)Math.pow(2, N)];
			for(int i=0; i<(int)Math.pow(2, N); i++){
				boolean check = true;
				if((i&map[0])-i<0){
					continue;
				}
				for(int j=0; j<N-1; j++){
					if(((i>>j) & 3)==3){
						check = false;
						break;
					}
				}
				if(check){
					dp[0][i] = 1;
				}
			}

			for(int i=1; i<M; i++){
				for(int j=0; j<(int)Math.pow(2, N); j++){
					if((j&map[i])-j<0){
						continue;
					}
					boolean check=true;
					for(int t=0; t<N-1; t++){
						if(((j>>t) & 3)==3){
							check = false;
							break;
						}
					}
					if(check){
						for(int k=0; k<(int)Math.pow(2, N); k++){
							if((j&k) == 0){
								dp[i][j] = (dp[i-1][k]+dp[i][j])%100000000;
							}
						}
					}
				}
			}

			long ans = 0;
			for(int i=0; i<(int)Math.pow(2, N); i++){
				ans =(ans + dp[M-1][i])%100000000;
			}
			System.out.println(ans);
		}

	}

}
