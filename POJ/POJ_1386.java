import java.util.Scanner;


public class POJ_1386 {

	static boolean[][] matrix;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		label:
		while(number--!=0){
			int num = in.nextInt();
			matrix = new boolean[27][27];
			int[] indegree = new int[27];
			int[] outdegree = new int[27];
			String skip_line = in.nextLine();
			for(int i=0; i<num; i++){
				String line = in.nextLine();
				char start = line.charAt(0);
				char end = line.charAt(line.length()-1);
				matrix[start-96][end-96] = true;
				outdegree[start-96]++;
				indegree[end-96]++;
			}
			int start = -1;
			boolean start_point = false;
			boolean end_point = false;
			for(int i=1; i<=26; i++){
				if(outdegree[i]==indegree[i]){
					continue;
				}else if(!start_point && outdegree[i]-indegree[i]==1){
					start = i;
					start_point = true;
				}else if(!end_point && indegree[i]-outdegree[i]==1){
					end_point = true;
				}else{
					System.out.println("The door cannot be opened.");
					continue label;
				}
			}
			
			if(start==-1){
				System.out.println("Ordering is possible.");
				continue label;
			}
			System.out.println("start is "+(char)(start+96));
			dfs(start);
			boolean result = true;
			for(int i=1; i<=26; i++){
				for(int j=1; j<=26; j++){
					if(matrix[i][j]){
						result = false;
					}
				}
			}
			if(result){
				System.out.println("Ordering is possible.");
			}else{
				System.out.println("The door cannot be opened.");
			}
			
		}
		
	}
	
	public static void dfs(int number){
		for(int i=1; i<=26; i++){
			if(matrix[number][i]){
				matrix[number][i] = false;
				dfs(i);
			}
		}
	}
	
	
}
