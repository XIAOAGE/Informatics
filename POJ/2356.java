import java.util.Scanner;


public class Main {

	static boolean[] mark = new boolean[10001];
	static int[] mark2 = new int[10001];
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		int[] arr = new int[number];
		
		for(int i=0; i<number; i++){
			arr[i] = in.nextInt();
		}
		
		int sum = 0;
		int low = -1;
		int high = -1;
		for(int i=0; i<number; i++){
			sum += arr[i];
			if(sum%number==0){
				low = 0;
				high = i;
				break;
			}else if(mark[sum%number]){
				low = mark2[sum%number]+1;
				high = i;
				break;
			}else{
				mark[sum%number] = true;
				mark2[sum%number] = i;
			}
		}
		
		System.out.println(high-low+1);
		for(int i=low; i<=high; i++){
			System.out.println(arr[i]);
		}
		
		
	}
	
}
