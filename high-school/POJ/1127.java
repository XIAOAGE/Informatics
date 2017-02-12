import java.util.Scanner;


public class Main{

	static class straw{
		int x1;
		int y1;
		int x2;
		int y2;
		
		public straw(int a, int b, int c, int d){
			x1 = a;
			y1 = b;
			x2 = c;
			y2 = d;
		}
	}
	
	static class P{
		int x;
		int y;
		
		public P(int a, int b){
			x = a;
			y = b;
		}
	}
	
	static straw[] arr;
	static int straw_num;
	static int[] parent;
	static int[] rank;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		while(true){
			straw_num = in.nextInt();
			if(straw_num==0){
				break;
			}
			arr = new straw[straw_num+1];
			for(int i=1; i<=straw_num; i++){
				int x1 = in.nextInt();
				int y1 = in.nextInt();
				int x2 = in.nextInt();
				int y2 = in.nextInt();
				arr[i] = new straw(x1, y1, x2, y2);
			}		
			
			union_set();
			while(true){
				int num1 = in.nextInt();
				int num2 = in.nextInt();
				if(num1==0 && num2==0){
					break;
				}
				if(find_root(num1) == find_root(num2)){
					System.out.println("CONNECTED");
				}else{
					System.out.println("NOT CONNECTED");
				}
			}
		}
		
	}
	
	public static double direction(P p1, P p2, P p3){
		P tmp1 = new P(p2.x-p1.x, p2.y-p1.y);
		P tmp2 = new P(p3.x-p1.x, p3.y-p1.y);
		return tmp1.x*tmp2.y-1*tmp1.y*tmp2.x;
	}
	
	public static boolean on_segment(P p1, P p2, P p3){
		double x_min, x_max, y_min, y_max;
		if(p1.x<p2.x){
			x_min = p1.x;
			x_max = p2.x;
		}else{
			x_min = p2.x;
			x_max = p1.x;
		}
		if(p1.y<p2.y){
			y_min = p1.y;
			y_max = p2.y;
		}else{
			y_max = p1.y;
			y_min = p2.y;
		}
		
		if(p3.x<x_min || p3.x>x_max || p3.y<y_min || p3.y>y_max){
			return false;
		}else{
			return true;
		}
	}
	
	public static boolean segment_intersect(P p1, P p2, P p3, P p4){
		double d1 = direction(p3,p4,p1);
		double d2 = direction(p3,p4,p2);
		double d3 = direction(p1,p2,p3);
		double d4 = direction(p1,p2,p4);
		
		if(d1*d2<0 && d3*d4<0){
			return true;
		}else if(d1==0 && on_segment(p3,p4,p1)){
			return true;
		}else if(d2==0 && on_segment(p3,p4,p2)){
			return true;
		}else if(d3==0 && on_segment(p1,p2,p3)){
			return true;
		}else if(d4==0 && on_segment(p1,p2,p4)){
			return true;
		}else{
			return false;
		}
	}
	
	public static void union_set(){
		
		parent = new int[straw_num+1];
		rank = new int[straw_num+1];
		for(int i=1; i<=straw_num; i++){
			parent[i] =i;
			rank[i] = 1;
		}
		for(int i=2; i<=straw_num; i++){
			for(int j=i-1; j>=1; j--){
				P p1 = new P(arr[i].x1, arr[i].y1);
				P p2 = new P(arr[i].x2, arr[i].y2);
				P p3 = new P(arr[j].x1, arr[j].y1);
				P p4 = new P(arr[j].x2, arr[j].y2);
				if(segment_intersect(p1,p2,p3,p4)){
					unite(i,j);
				}
			}
		}
	}
	
	public static void unite(int a, int b){
		a = find_root(a);
		b = find_root(b);
		
		if(a==b){
			return;
		}
		
		if(rank[a]<rank[b]){
            parent[a] = b;
        }else{
            parent[b] = a;
            if(rank[a]==rank[b]){
                rank[a]++;
            }
        }
	}
	
	public static int find_root(int a){
		int b = a;
        while(a!=parent[a]){
            a=parent[a];
        }
        while(b!=parent[b]){
            int tempB = b;
            b = parent[b];
            parent[tempB] = a;
        }
        return parent[a];
	}
	
}
