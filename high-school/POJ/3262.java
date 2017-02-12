import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {

	static class cow implements Comparable<cow>{
		int time;
		int destroy;
		
		public cow(int a, int b){
			time = a;
			destroy = b;
		}

		@Override
		public int compareTo(cow o) {
			int a = this.time;
			int b = this.destroy;
			int c = o.time;
			int d = o.destroy;
			if(a*d>c*b){
				return 1;
			}else{
				return -1;
			}
		}
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		PriorityQueue<cow> pq = new PriorityQueue<cow>();
		for(int i=0; i<N; i++){
			cow current = new cow(in.nextInt(), in.nextInt());
			pq.add(current);
		}
		long ans = 0;
		long acu = 0;
		while(!pq.isEmpty()){
			cow current = pq.poll();
			ans += current.destroy*acu;
			acu += current.time*2;
		}
		System.out.println(ans);
		
	}
	
}
