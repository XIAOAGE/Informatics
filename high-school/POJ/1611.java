import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class Main {

	static int[] par;
	static int[] rank;
	static int[] num;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(true){
			
			int n = in.nextInt();
			int m = in.nextInt();
			
			if(n==0 && m==0){
				break;
			}
			
			par = new int[n+1];
			rank = new int[n+1];
			num = new int[n+1];
			
			for(int i=0; i<n+1; i++){
				par[i] = i;
				rank[i] = 0;
				num[i]=1;
			}
			
			for(int i=0; i<m; i++){
				int k = in.nextInt();
				int first = in.nextInt();
				for(int a=0; a<k-1; a++){
					unite(first,in.nextInt());
				}
			}
			
			System.out.println(num[findRoot(0)]);
			
		}
		
	}
	
	public static int findRoot(int a){
        int b = a;
		while(a!=par[a]){
			a=par[a];
		}
	    while(b!=par[b]){
	    	int tempB = b;
	    	b = par[b];
	    	par[tempB] = a;
	    }
		return par[a];
	}
	
	public static void unite(int a, int b){
		a = findRoot(a);
		b = findRoot(b);
        
		if(a==b){
			return;
		}
		
		if(rank[a]<rank[b]){
			par[a] = b;
			num[b] += num[a];
		}else{
			par[b] = a;
			if(rank[a]==rank[b]){
				rank[a]++;
			}
			num[a]+=num[b];
		}
	}
	
}
