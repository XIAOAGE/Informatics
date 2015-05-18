import java.math.BigInteger;
import java.util.Scanner;


public class POJ_2109 {

	static BigInteger bi;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(in.hasNext()){
			long n = in.nextLong();
			bi = in.nextBigInteger();
			long low = 1;
			long high = 1000000000;
			long ans = -1;
			while(high>=low){
				long mid = (high+low)/2;
				BigInteger res = cal(mid, n);
				if(res.compareTo(bi)==0){
					ans = mid;
					break;
				}else if(res.compareTo(bi)==-1){
					low = mid+1;
				}else{
					high = mid-1;
				}
			}
			System.out.println(ans);
		}

	}

	public static BigInteger cal(long a, long time){
		BigInteger ans = BigInteger.valueOf(a);
		for(int i=0; i<time-1; i++){
			ans = ans.multiply(BigInteger.valueOf(a));
		}
		return ans;
	}


}
