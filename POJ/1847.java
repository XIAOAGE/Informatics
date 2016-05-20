import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {

	static class node implements Comparable<Object>{

		private int nodeVal;
		private int node;
		
		public int compareTo(Object o) {
			node b = (node)o;
			if(this.nodeVal>b.nodeVal){
				return 1;
			}else if(this.nodeVal<b.nodeVal){
				return -1;
			}
			return 0;
		}
		
		public node(int a, int b){
			node = a;
			nodeVal = b;
		}
		
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int numOfTram = in.nextInt();
		int start = in.nextInt();
		int end = in.nextInt();
		
		int[] trams = new int[numOfTram+1];
		int[][] matrix = new int[numOfTram+1][numOfTram+1];
		Map<Integer, LinkedList<Integer>> map = new HashMap<Integer, LinkedList<Integer>>();
		
		for(int i=1; i<=numOfTram; i++){
			int round = in.nextInt();
			LinkedList<Integer> tempList = new LinkedList<Integer>();
			for(int a=0; a<round; a++){
				int temp = in.nextInt();
				tempList.add(temp);
				if(a==0){
					matrix[i][temp] = 0;
				}else{
					matrix[i][temp] = 1;
				}
			}
			map.put(i, tempList);
		}
		
		boolean[] used = new boolean[numOfTram+1];
	    node[] nodes = new node[numOfTram+1];
	    for(int i=1; i<=numOfTram; i++){
	    	node tempNode = new node(i,Integer.MAX_VALUE);
	    	nodes[i] = tempNode;
	    }
	    nodes[start].nodeVal = 0;
		PriorityQueue<node> pq = new PriorityQueue<node>();
	    pq.offer(nodes[start]);
	    
	    while(!pq.isEmpty()){
	    	
	    	node little = pq.poll();
	        for(int i=0; i<map.get(little.node).size(); i++){
	        	node current = nodes[map.get(little.node).get(i)];
	        	if(!used[current.node] && current.nodeVal>matrix[little.node][current.node]+little.nodeVal){
	        		current.nodeVal = matrix[little.node][current.node]+little.nodeVal;
	        		pq.offer(current);
	        	}
	        }
	    	used[little.node] = true;
	    	
	    }
		if(nodes[end].nodeVal == Integer.MAX_VALUE){
			System.out.println("-1");
		}else{
			System.out.println(nodes[end].nodeVal);
		}
	}
	
}
