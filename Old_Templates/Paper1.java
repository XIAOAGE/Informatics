import java.util.LinkedList;


public class Paper1 {

	static class node{
		int num;
		LinkedList<Integer> kids = new LinkedList<Integer>();
		
		public node(int a){
			num = a;
		}
	}
	
	static node[] arr;
	
	public static void main(String[] args){
		
		arr = new node[10];
		arr[0] = new node(5);
		arr[1] = new node(3);
		arr[2] = new node(4);
		arr[3] = new node(6);
		arr[4] = new node(7);
		arr[5] = new node(19);
		arr[6] = new node(1);
		arr[7] = new node(2);
		arr[8] = new node(3);
		arr[9] = new node(4);
		
		arr[0].kids.add(1);
		arr[0].kids.add(2);
		arr[0].kids.add(3);
		arr[0].kids.add(4);
		arr[1].kids.add(5);
		arr[2].kids.add(6);
		arr[3].kids.add(7);
		arr[4].kids.add(8);
		arr[4].kids.add(9);
		
		//以上只是输入部分，可以根据实际情况改动
		int ans = dfs(0);
		System.out.println(ans-arr[0].num); //因为root的值不算，所以剪掉
	}
	
	public static int dfs(int index){
		LinkedList<Integer> kids = arr[index].kids;
		int val = arr[index].num;
		for(int i=0; i<kids.size(); i++){	//遍历所有的子节点
			node next = arr[kids.get(i)];
			val = Math.max(val, dfs(kids.get(i))+arr[index].num);	//提取最大值
		}
		return val;
	}
	
}
