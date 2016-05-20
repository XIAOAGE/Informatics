import java.util.Scanner;


public class Main {

	static int[] arr;
	
	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int number = in.nextInt();

		arr = new int[number];
		for(int i=0; i<number; i++){
			arr[i] = in.nextInt();
		}
		MergeSort(0, arr.length-1);
		
		if(arr.length%2==0){
			System.out.println(arr[arr.length/2]-1);
		}else{
			System.out.println(arr[arr.length/2]);
		}

	}

	public static void MergeSort(int left, int right){

		if(left==right){
			return;
		}

		int mid = (left+right)/2;

		MergeSort(left, mid);
		MergeSort(mid+1, right);

		Merge(left, mid, right);

	}

	public static void Merge(int left, int mid, int right){

		int[] after = new int[right-left+1];
		int lb = left;
		int rb = mid+1;
		int count = 0;

		while(lb<=mid && rb<=right){
			if(arr[lb]<=arr[rb]){
				after[count++] = arr[lb++];
			}else{
				after[count++] = arr[rb++];
			}
		}

		while(lb<=mid){
			after[count++] = arr[lb++];
		}

		while(rb<=right){
			after[count++] = arr[rb++];
		}

		for(int i=0; i<after.length; i++){
			arr[left++] = after[i];
		}

	}

}
