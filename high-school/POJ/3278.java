import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Main {

	static class node{

		private int number;
		private int move;

		public node(int a, int b){
			number = a;
			move = b;
		}

	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();

		boolean[] visited = new boolean[200000];
		Queue<node> qu = new LinkedList<node>();
		node start = new node(N, 0);
		qu.add(start);

		int answer = 0;

		while(!qu.isEmpty()){

			node current = qu.poll();
			int move = current.move;
			int location = current.number;
			if(location==K){
				answer = move;
				break;
			}

			visited[location] = true;

			int next1 = location-1;
			int next2 = location+1;
			int next3 = location*2;

			if(next1>=0 && !visited[next1]){				
				qu.offer(new node(location-1, move+1));
			}

			if(next2<=100000 && !visited[next2]){
				qu.offer(new node(location+1, move+1));				
			}

			if(next3<=100000 && !visited[next3]){
				qu.offer(new node(location*2, move+1));
			}

		}

		System.out.println(answer);

	}

}
