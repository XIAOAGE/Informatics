import java.util.Scanner;


public class Main {

	static class edge{

		private int start;
		private int end;
		private int cost;

		public edge(int a, int b, int c){
			start = a;
			end = b;
			cost = c;
		}

	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int ML = in.nextInt();
		int MD = in.nextInt();

		edge[] L  = new edge[ML];
		edge[] D = new edge[MD];
		edge[] C = new edge[N-1];
		int[] d = new int[N+1];

		for(int i=1; i<=N; i++){
			d[i] = 1000000000;
		}
		d[1] = 0;
		int count = 1;

		for(int i=0; i<C.length; i++){
			edge e = new edge(count+1, count, 0);
			C[i] = e;
			count++;
		}

		for(int i=0; i<ML; i++){
			int A = in.nextInt();
			int B = in.nextInt();
			int length = in.nextInt();
			edge e = new edge(A, B, length);
			L[i] = e;
		}

		for(int i=0; i<MD; i++){
			int A = in.nextInt();
			int B = in.nextInt();
			int length = in.nextInt();
			edge e = new edge(B, A, -1*length);
			D[i] = e;
		}

		boolean judge = false;
		for(int i=0; i<N; i++){

			judge = false;

			for(int p=0; p<C.length; p++){
				edge e = C[p];
				int start = e.start;
				int end = e.end;
				int cost = e.cost;
				d[end] = d[end]>d[start]+cost ? d[start]+cost : d[end];
				judge = true;
			}

			for(int p=0; p<D.length; p++){
				edge e = D[p];
				int start = e.start;
				int end = e.end;
				int cost = e.cost;
				d[end] = d[end]>d[start]+cost ? d[start]+cost : d[end];
				judge = true;
			}

			for(int p=0; p<L.length; p++){
				edge e = L[p];
				int start = e.start;
				int end = e.end;
				int cost = e.cost;
				d[end] = d[end]>d[start]+cost ? d[start]+cost : d[end];
				judge = true;
			}

			if(!judge){
				break;
			}

		}

		if(d[1]<0){
			System.out.println("-1");
		}else if(d[N]==1000000000){
			System.out.println("-2");
		}else{
			System.out.println(d[N]);
		}

	}

}
