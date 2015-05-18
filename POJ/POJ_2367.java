import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;


public class POJ_2367 {

	static int N;
	static int[] indegree;
	static boolean[][] matrix;
	static ArrayList<Integer> al;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		N = Integer.parseInt(in.nextLine());
		indegree = new int[N+1];
		matrix = new boolean[N+1][N+1];
		al = new ArrayList<Integer>();
		
		for(int i=1; i<=N; i++){
			String line = in.nextLine();
			String[] arr = line.split(" ");
			if(arr.length==1){
				continue;
			}
			for(int j=0; j<arr.length-1; j++){
				int kid = Integer.parseInt(arr[j]);
				indegree[kid]++;
				matrix[i][kid] = true;
			}
		}
		topo_sort();
		for(int i=0; i<al.size(); i++){
			System.out.print(al.get(i)+" ");
		}
		System.out.println();
			
	}
	
	public static void topo_sort(){
		
		Stack<Integer> sta = new Stack<Integer>();
		for(int i=1; i<=N; i++){
			if(indegree[i]==0){
				sta.push(i);
			}
		}
		while(!sta.isEmpty()){
			int number = sta.pop();
			al.add(number);
			for(int i=1; i<=N; i++){
				if(matrix[number][i] && --indegree[i]==0){
					sta.push(i);
				}
			}
		}
		
	}
	
}
