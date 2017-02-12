import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static String[] arr;
	static int[][] cost;
	static int N;
	static int[] P;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while(T--!=0){
			N = in.nextInt();
			String skip = in.nextLine();
			cost = new int[N][N];
			arr = new String[N];
			for(int i=0; i<N; i++){
				arr[i] = in.nextLine();
			}
			cal();
			P = new int[N];
			for(int i=0; i<N; i++){
				P[i] = i;
			}
			int ans = Integer.MAX_VALUE;
			for(int i=1; i<=cal_permutation(N); i++){
				nextPermutation(P);
				int tmp = arr[P[0]].length();
				for(int k=1; k<P.length; k++){
					tmp += cost[P[k-1]][P[k]];
				}
				ans = Math.min(tmp, ans);
			}
			System.out.println(ans);
		}

	}
	
	public static int cal_permutation(int number){
		int res = 1;
		while(number>1){
			res *= number;
			number--;
		}
		return res;
	}
	
	public static void cal(){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(i==j){continue;}
				cost[i][j] = cal_length(arr[i], arr[j]);
			}
		}
	}
	
	public static int cal_length(String first, String second){
		int start = 0;
		int end = first.length()-1;
		int length = 1;
		int res = second.length();
		int MAX_L = 0;
		while(length<=first.length() && length<=second.length()){
			if(first.substring(end, end+length).equals(second.substring(start, start+length))){
				MAX_L = length;
			}
			length++;
			end--;
		}
		return res-MAX_L;
	}
	
	public static void nextPermutation(int[] num)
    {
        if(num.length <= 1)
            return ;
        for(int i = num.length - 2; i >= 0; i--)
        {
            if(num[i] < num[i+1])
            {
                int j;
                for(j = num.length - 1; j >= i; j--)
                    if(num[i] < num[j])
                        break;
                // swap the two numbers.
                num[i] = num[i] ^ num[j];
                num[j] = num[i] ^ num[j];
                num[i] = num[i] ^ num[j];
                //sort the rest of arrays after the swap point.
                Arrays.sort(num, i+1, num.length);
                return ;
            }
        }
        //reverse the arrays.
        for(int i = 0; i < num.length / 2; i++)
        {
            int tmp = num[i];
            num[i] = num[num.length - i - 1];
            num[num.length - i - 1] = tmp;
        }
        return ;
    }

}
