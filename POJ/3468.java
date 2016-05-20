import java.util.Scanner;


public class Main {

	static int[] value;
	static node[] tree;
	
	static class node{
		long addMark;
		long sum;
	}
	
	public static void build_tree(int root, int left, int right){
		tree[root] = new node();
		tree[root].addMark = 0;
		if(left==right){	//leaf
			tree[root].sum = value[left];
			return;
		}else{
			int mid = (left+right)/2;
			build_tree(root*2, left, mid);
			build_tree(root*2+1, mid+1, right);
			tree[root].sum = tree[root*2].sum + tree[root*2+1].sum;
		}
	}
	
	public static void push_down(int root, int left, int right){
		if(tree[root].addMark!=0){
			int mid = (left+right)/2;
			tree[root*2].addMark += tree[root].addMark;
			tree[root*2+1].addMark += tree[root].addMark;
			tree[root*2].sum += tree[root].addMark * (mid-left+1);
			tree[root*2+1].sum += tree[root].addMark * (right-mid);
			tree[root].addMark = 0;
		}
	}
	
	public static long query(int root, int start, int end, int left, int right){
		//no common set
		if(start>right || end<left){
			return 0;
		}
		if(start<=left && end>=right){
			return tree[root].sum;
		}
		push_down(root, left, right);
		int mid = (left+right)/2;
		return query(root*2, start, end, left, mid) + query(root*2+1, start, end, mid+1, right);
	}
	
	public static void update(int root, int start, int end, int left, int right, int addVal){
		if(start>right || end<left){
			return;
		}
		if(start<=left && end>=right){
			tree[root].addMark += addVal;
			tree[root].sum += addVal*(right-left+1);
			return;
		}
		push_down(root, left, right);
		int mid = (left+right)/2;
		update(root*2, start, end, left, mid, addVal);
		update(root*2+1, start, end, mid+1, right, addVal);
		tree[root].sum = tree[root*2].sum + tree[root*2+1].sum;
	}
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int Q = in.nextInt();
		
		value = new int[N+1];
		tree = new node[(int)Math.pow(2, 18)*2-1];
		for(int i=1; i<=N; i++){
			value[i] = in.nextInt();
		}
		build_tree(1, 1, N);
		String skip_line = in.nextLine();
		while(Q--!=0){
			String line = in.nextLine();
			String[] arr = line.split(" ");
			if(arr[0].equals("Q")){
				int start = Integer.parseInt(arr[1]);
				int end = Integer.parseInt(arr[2]);
				System.out.println(query(1, start, end, 1, N));
			}else{
				int start = Integer.parseInt(arr[1]);
				int end = Integer.parseInt(arr[2]);
				int addVal = Integer.parseInt(arr[3]);
				update(1, start, end, 1, N, addVal);
			}
		}
		
	}
	
}
