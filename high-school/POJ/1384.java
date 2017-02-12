import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static class node{

		private int weight;
		private int cost;

		public node(int a, int b){	
			cost = a;
			weight = b;	
		}

	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int number = in.nextInt();

		for(int i=0; i<number; i++){    //do every cases

			int weight = Math.abs(in.nextInt()-in.nextInt());
			int type = in.nextInt();

			node[] table =  new node[type];
			for(int a=0; a<type; a++){
				node newNode = new node(in.nextInt(),in.nextInt());
				table[a] = newNode;
			}

			int[] dp = new int[weight+1];
			Arrays.fill(dp,1000000000);
			dp[0] = 0;

			for(int a=1; a<=weight; a++){	
				for(int b=0; b<type; b++){
					node current = table[b];
					int cost = current.cost;
					int weigh = current.weight;
					if(a-weigh>=0){
						if(dp[a-weigh]+cost<dp[a]){
							dp[a] = dp[a-weigh]+cost;
						}
					}
				}	
			}
			
			if(dp[weight]==1000000000){
				System.out.println("This is impossible.");
			}else{
				System.out.println("The minimum amount of money in the piggy-bank is "+dp[weight]+".");
			}
		}

	}

}
