import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {

	static int N;
	static int P;
	static int K;
	static final int INF = 1000000;
	static int[][] matrix;
	static Map<Integer, LinkedList<Integer>> map;

	static class node implements Comparable<node>{
		int number;
		int distance;

		public node(int a, int b){
			number = a;
			distance = b;
		}

		@Override
		public int compareTo(node o) {
			if(this.distance<o.distance){
				return -1;
			}else{
				return 1;
			}
		}
	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		P = in.nextInt();
		K = in.nextInt();
		matrix = new int[N+1][N+1];
		map = new HashMap<Integer, LinkedList<Integer>>();
		for(int i=0; i<P; i++){
			int a = in.nextInt();
			int b = in.nextInt();
			int L = in.nextInt();
			if(map.get(a)==null){
				LinkedList<Integer> temp = new LinkedList<Integer>();
				temp.add(b);
				map.put(a, temp);
			}else{
				map.get(a).add(b);
			}
			if(map.get(b)==null){
				LinkedList<Integer> temp = new LinkedList<Integer>();
				temp.add(a);
				map.put(b, temp);
			}else{
				map.get(b).add(a);
			}
			matrix[a][b] = L;
			matrix[b][a] = L;
		}

		int ans = binary_search();
		System.out.println(ans);

	}

	public static int binary_search(){
		int low = 0;
		int high = INF;
		while(high-low>1){
			int mid = (high+low)/2;
			if(Dijkstra(mid)){
				high = mid;
			}else{
				low = mid;
			}
		}
		if(low==INF-1){
			return -1;
		}
		return low;
	}

	public static boolean Dijkstra(int x){
		int[] d = new int[N+1];
		Arrays.fill(d, INF);
		d[1] = 0;
		PriorityQueue<node> pq = new PriorityQueue<node>();
		node start = new node(1,0);
		pq.add(start);
		while(!pq.isEmpty()){
			node current = pq.poll();
			int number = current.number;
			LinkedList<Integer> kids = map.get(number);
			if(kids!=null){
				for(int i=0; i<kids.size(); i++){
					int v = kids.get(i);
					int cost = matrix[number][v];
					int new_dis = d[number] + (cost<x ? 0 : 1);
					if(new_dis<d[v]){
						d[v]  = new_dis;
						pq.add(new node(v,d[v]));
					}
				}
			}
		}
		return d[N] <= K;
	}

}
