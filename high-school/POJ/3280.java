import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		
		int[] cost = new int[26];
		String crap = in.nextLine();
		String tag = in.nextLine();
		for(int i=0; i<N; i++){
			String[] line = in.nextLine().split(" ");
			char cha = line[0].charAt(0);
			int adding = Integer.parseInt(line[1]);
			int deleting = Integer.parseInt(line[2]);
			cost[cha-'a'] = min(adding, deleting);
		}
		
		int[][] dp = new int[M][M];
		for(int i=0; i<M; i++){
			for(int a=0; a<M; a++){
				dp[i][a] = 0;
			}
		}
		
		for(int s=M-1; s>=0; s--){
			for(int e=s; e<M; e++){
				if(s==e){
					continue;
				}
				dp[s][e] = min(dp[s+1][e]+cost[tag.charAt(s)-'a'], dp[s][e-1]+cost[tag.charAt(e)-'a']);
				if(tag.charAt(s)==tag.charAt(e)){
					dp[s][e] = min(dp[s][e], dp[s+1][e-1]);
				}
			}
		}
		
		System.out.println(dp[0][M-1]);
				
	}
	
	public static int min(int a, int b){
		if(a<b){
			return a;
		}else{
			return b;
		}
	}
	
}
