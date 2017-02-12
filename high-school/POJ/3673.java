import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		String[] arr = line.split(" ");
		String A = arr[0];
		String B = arr[1];
		int ans = 0;
		
		for(int i=0; i<A.length(); i++){
			for(int j=0; j<B.length(); j++){
				int first = A.charAt(i)-48;
				int second = B.charAt(j)-48;
				ans += first*second;
			}
		}
		System.out.println(ans);
		
	}
	
}
