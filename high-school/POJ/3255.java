import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {

	static class node implements Comparable<node>{
		
		private int number;
		private int length;
		private int interval;
		private int end;
		
		public node(int c, int d, int e){		
			interval = c;
			end = d;	
		}
		
		public node(int a, int b){
			number = a;
			length = b;
		}

		@Override
		public int compareTo(node o) {
			if(this.length>o.length){
				return 1;
			}else if(this.length<o.length){
				return -1;
			}
			return 0;
		}
		
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int R = in.nextInt();
		
		Map<Integer, LinkedList<node>> map = new HashMap<Integer, LinkedList<node>>();
		
		for(int i=0; i<R; i++){
			int start = in.nextInt();
			int end = in.nextInt();
			int distance = in.nextInt();
			LinkedList<node> temp;
			if(map.get(start)==null){
				temp= new LinkedList<node>();
				temp.add(new node(distance, end, 0));
				map.put(start, temp);
			}else{
				temp = map.get(start);
				temp.add(new node(distance, end, 0));
				map.put(start, temp);
			}
			if(map.get(end)==null){
				temp = new LinkedList<node>();
				temp.add(new node(distance, start, 0));
				map.put(end, temp);
			}else{
				temp = map.get(end);
				temp.add(new node(distance, start, 0));
				map.put(end, temp);
			}
		}
		
		int[] d = new int[N+1];
		int[] d2 = new int[N+1];
		for(int i=1; i<=N; i++){
			d[i] = 1000000000;
			d2[i] = 1000000000;
		}
		d[1] = 0;
		node crap = new node(1, 0);
		PriorityQueue<node> pq = new PriorityQueue<node>();
		pq.add(crap);

		while(!pq.isEmpty()){
			node newNode = pq.poll();
			int number = newNode.number;
			int cost = newNode.length;
			if(d2[number]<cost){continue;}
			
			LinkedList<node> travel = map.get(number);
			for(int i=0; i<travel.size(); i++){
				node get = travel.get(i);
				int to = get.end;
				int pending = cost + get.interval;
				if(pending<d[to]){
					d[to] = pending ^ d[to];
					pending = d[to] ^ pending;
					d[to] = d[to] ^ pending;
					pq.offer(new node(to, d[to]));
				}
				
				if(d2[to]>pending && pending>d[to]){
					d2[to] = pending;
					pq.offer(new node(to, pending));
				}
			}
		}

		System.out.println(d2[N]);
		
	}
	
}
