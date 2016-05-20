import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class Main{

	static int[][] map;
	static Set<String> used;
	static Set<String> visited;
	static int ans;

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		map = new int[5][5];
		used = new TreeSet<String>();
		visited = new TreeSet<String>();
		ans = 0;
		for(int i=0; i<5; i++){
			String line = in.nextLine();
			String[] arr = line.split(" ");
			for(int j=0; j<5; j++){
				map[i][j] = Integer.parseInt(arr[j]);
			}
		}
		
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				dfs(i,j,i+""+j,map[i][j]+"");
			}
		}
		System.out.println(ans);
			
	}
	
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	
	public static void dfs(int x, int y, String route, String number){
		if(number.length()==6){
			if(!used.contains(number)){
				ans+=1;
				used.add(number);
			}
			return;
		}
		for(int i=0; i<4; i++){
			int nextX = x+dx[i];
			int nextY = y+dy[i];
			if(nextX>=0 && nextY>=0 && nextX<5 && nextY<5 && !visited.contains(route+nextX+""+nextY)){
				visited.add(route+nextX+""+nextY);
				dfs(nextX, nextY, route+nextX+""+nextY, number+map[nextX][nextY]);
			}
		}
	}
	
}
