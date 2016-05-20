import java.util.Scanner;


public class Main{
	
	static final int INF = 1000000;
	static int N;
	static int[] pos;
	static int[] val;
	static int[] tree;
	static int[] ans;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			N = in.nextInt();
			pos = new int[N];
			val = new int[N];
			for(int i=0; i<N; i++){
				pos[i] = in.nextInt();
				val[i] = in.nextInt();
			}
			tree = new int[INF];
			ans = new int[N];
			build_tree(1,0,N-1);
			for(int i=N-1; i>=0; i--){
				update(1,0,N-1,pos[i],val[i]);
			}
			for(int x: ans){
				System.out.print(x+" ");
			}
			System.out.println();
		}
		
	}
	
	public static void update(int root, int left, int right, int number, int value){
		if(left==right){
			ans[left] = value;
			tree[root] -= 1;
			return;
		}
		if(tree[root*2]>=number+1){
			tree[root*2]-=1;
			update(root*2, left, (right+left)/2, number, value);
		}else{
			tree[root*2+1]-=1;
			update(root*2+1, (right+left)/2+1, right, number-tree[root*2], value);
		}
	}
	
	public static void build_tree(int root, int left, int right){
		if(left==right){
			tree[root] = 1;
			return;
		}else{
			int mid = (left+right)/2;
			build_tree(root*2, left, mid);
			build_tree(root*2+1, mid+1, right);
			tree[root] = tree[root*2]+tree[root*2+1];
		}
	}
	
}
