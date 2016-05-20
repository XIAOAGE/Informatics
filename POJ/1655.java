import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;
import java.util.ArrayList;

//notice this graph is an undirected graph, that's why this algorithm can be guaranteed.

public class Main {

	static Map<Integer, LinkedList<Integer>> map;
	static int[] max;
	static int[] sum;
	static int number;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		while(num--!=0){
			number = in.nextInt();
			max = new int[number+1];
			sum = new int[number+1];
			map = new HashMap<Integer, LinkedList<Integer>>();
			for(int i=0; i<number-1; i++){
				int a = in.nextInt();
				int b = in.nextInt();

				if(map.get(a)==null){
					LinkedList<Integer> temp = new LinkedList<Integer>();
					temp.add(b);
					map.put(a,temp);
				}else{
					map.get(a).add(b);
				}
				if(map.get(b)==null){
					LinkedList<Integer> temp = new LinkedList<Integer>();
					temp.add(a);
					map.put(b,temp);
				}else{
					map.get(b).add(a);
				}
			}
			dfs(1,0);
			solve();
		}
	}

	public static int dfs(int root, int pre){

		LinkedList<Integer> kid = map.get(root);

		sum[root] = 1;
		for(int i=0; i<kid.size(); i++){
			if(kid.get(i)==pre){
				continue;
			}
			int t = dfs(kid.get(i),root);
			sum[root] += t;
			max[root] = max(max[root],t);
		}

		return sum[root];

	}

	public static void solve(){

		int ans = 1000000;
		int index = -1;
		for(int i=1; i<=number; i++){
			max[i] = max(max[i], number-sum[i]);
			if(ans>max[i]){
				index = i;
				ans = max[i];
			}
		}
		System.out.printf("%d %d\n", index, ans);

	}

	public static int max(int a, int b){
		if(a>b){
			return a;
		}else{
			return b;
		}
	}

}
