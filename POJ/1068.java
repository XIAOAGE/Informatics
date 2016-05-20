import java.util.Arrays;
import java.util.Scanner;


public class Main{

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		
		while(t--!=0){
			int n = in.nextInt();
			String skip_line = in.nextLine();
			String line = in.nextLine();
			String[] temp = line.split(" ");
			int[] arr= new int[n];
			for(int i=0; i<n; i++){
				arr[i] = Integer.parseInt(temp[i]);
			}
			int[] ans = new int[n];
			Arrays.fill(ans, 1);
			for(int i=0; i<arr.length; i++){
				int val = arr[i]-i-1;
				int temp2 = val;
				for(int j=i+1; j<arr.length; j++){
					val += arr[j]-arr[j-1];
					if(val==temp2){
						ans[j]++;
					}else{
						val-=1;
					}
				}
			}
			for(int i=0; i<ans.length; i++){
				System.out.print(ans[i]+" ");
			}
			System.out.println();
		}
		
	}
	
}
