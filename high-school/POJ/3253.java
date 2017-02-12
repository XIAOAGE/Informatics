import java.math.BigInteger;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		PriorityQueue<BigInteger> pq = new PriorityQueue<BigInteger>();
		for(int i=0; i<num; i++){
			pq.add(in.nextBigInteger());
		}
		BigInteger sum = new BigInteger("0");
		while(pq.size()!=1){
			BigInteger num1 = pq.poll();
			BigInteger num2 = pq.poll();
			sum = sum.add(num1.add(num2));
			pq.add(num1.add(num2));
		}
		System.out.println(sum);
	}
	
}
