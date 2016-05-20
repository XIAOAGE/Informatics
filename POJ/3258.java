import java.util.Scanner;


public class Main {

	static int[] rock;
	static int L;
	static int N;
	static int M;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			L = in.nextInt();
			N = in.nextInt();
			M = in.nextInt();

			rock = new int[N];

			for(int i=0; i<N; i++){
				rock[i] = in.nextInt();
			}

			quicksort(0, N-1);
			System.out.println(binary_search());
		}

	}

	public static int binary_search(){

		int low = 0;
		int high = Integer.MAX_VALUE;
		while(high-low>1){		
			int mid = (low+high)/2;
			if(check(mid)){
				low = mid;
			}else{
				high = mid;
			}	
		}
		return low;

	}

	public static boolean check(int minimum){
		int removed = 0;
		int previous = 0;
		for(int i=0; i<rock.length; i++){
			if(rock[i]-previous<minimum){
				if(removed==M){
					return false;
				}
				removed++;
			}else{
				previous = rock[i];
			}
		}
		if(L-previous<minimum){
			if(removed==M){
				return false;
			}
			removed++;
		}
		return true;
	}

	public static void quicksort(int left, int right){

		if(right-left<=0){
			return;
		}else{
			int partition = partition(left, right, rock[left]);
			quicksort(left, partition-1);
			quicksort(partition+1, right);
		}

	}

	public static int partition(int left, int right, int pivot){

		int leftMark = left;
		int rightMark = right+1;

		while(true){
			while(leftMark<right && rock[++leftMark]<pivot){}
			while(rightMark>left && rock[--rightMark]>pivot){}
			if(leftMark>=rightMark){
				break;
			}else{
				swap(leftMark, rightMark);
			}
		}
		swap(rightMark,left);
		return rightMark;

	}

	public static void swap(int a, int b){
		int temp = rock[a];
		rock[a] = rock[b];
		rock[b] = temp;
	}

}
