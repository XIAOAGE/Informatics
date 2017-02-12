import java.math.BigInteger;
import java.util.Scanner;


public class Main{

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		BigInteger check = new BigInteger("0");

		while (in.hasNext()) {   
			BigInteger a = in.nextBigInteger();   
			BigInteger b = in.nextBigInteger();   
			if (a.compareTo(BigInteger.ONE) == -1 && b.compareTo(BigInteger.ONE) == -1) {   
				break;   
			}   
			int count = 0;   
			BigInteger[] f = new BigInteger[1000000];   
			f[0] = BigInteger.ONE;   
			f[1] = BigInteger.ONE.add(BigInteger.ONE);   
			for (int i = 0; i < f.length; i++) {   
				if (i >= 2) {   
					f[i] = f[i - 1].add(f[i - 2]);   
				}   
				if (f[i].compareTo(b)==1) {   
					break;   
				}   
				if (!(f[i].compareTo(a)==-1)) {   
					count++;   
				}   
			}   
			System.out.println(count);   
		}     

	}


}
