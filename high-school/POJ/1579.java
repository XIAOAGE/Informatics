import java.util.Scanner;


public class Main {

	static int[][][] arr;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(true){

			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();

			if(a==-1 && b==-1 && c==-1){
				break;
			}
			arr = new int[21][21][21];
			int answer = recursion(a, b, c);
			System.out.printf("w(%d, %d, %d) = %d",a,b,c,answer);
			System.out.println();

		}

	}


	public static int recursion(int a, int b, int c){

		if(a<=0 || b<=0 || c<=0){
			return 1;
		}else if(a>20 || b>20 || c>20){
			if(arr[20][20][20]!=0){
				return arr[20][20][20];
			}
			arr[20][20][20] = recursion(20,20,20);
			return arr[20][20][20];
		}else if(a>=0 && b>=0 && c>=0){
			if(arr[a][b][c]!=0){
				return arr[a][b][c];
			}
		}else if(a<b && b<c){
			arr[a][b][c] = recursion(a,b,c-1)+recursion(a,b-1,c-1)-recursion(a,b-1,c);
			return arr[a][b][c];
		}
		
		arr[a][b][c] = recursion(a-1,b,c)+recursion(a-1,b-1,c)+recursion(a-1,b,c-1)-recursion(a-1,b-1,c-1);
		return arr[a][b][c];

	}

}
