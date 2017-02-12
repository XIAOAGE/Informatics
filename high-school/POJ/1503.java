import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		BigInteger ans = BigInteger.ZERO;
		while(in.hasNextBigInteger()){
			ans = ans.add(in.nextBigInteger());
		}
		System.out.println(ans);
		
	}
	
}
