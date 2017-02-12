import java.util.PriorityQueue;
import java.util.Scanner;



public class Main {

	static class node implements Comparable<node>{

		private int key;
		private int number;

		public node(int a, int b){

			key = a;
			number = b;

		}

		public int compareTo(node o) {
			if(this.key<o.key){
				return -1;
			}else if(this.key>o.key){
				return 1;
			}
			return 0;
		}

	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(in.hasNext()){
			int N = in.nextInt();

			int[][] matrix = new int[N][N];
			for(int i=0; i<N; i++){
				for(int a=0; a<N; a++){
					matrix[i][a] = in.nextInt();
				}
			}

			PriorityQueue<node> pq = new PriorityQueue<node>();
			node start = new node(0, 0);
			pq.add(start);

			boolean[] visited = new boolean[N];
			int ans = 0;

			while(!pq.isEmpty()){
				node current = pq.poll();
				int number = current.number;
				int key = current.key;
				if(!visited[number]){
					ans+=key;
					visited[number]= true;
					for(int i=0; i<N; i++){
						if(!visited[i]){
							pq.add(new node(matrix[number][i], i));
						}
					}
				}
			}

			System.out.println(ans);
		}

	}

}
