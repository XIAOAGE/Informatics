import java.util.Scanner;


public class Main {

	static String[] arr;
	static int ans;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			String line = in.nextLine();
			arr = line.split(" ");
			String status = to_string();
			ans = Integer.MAX_VALUE;
			recursion(status, 0, 0);
			System.out.println(ans);
		}

	}

	public static String to_string(){
		String res = "";
		for(String x: arr){
			res += x;
		}
		return res;
	}

	public static String to_string2(int a, int b, int c, char[] arr2){
		String res = "";
		for(int i=0; i<arr2.length; i++){
			if(i==a || i==b || i==c){
				int num = arr2[i]-48;
				if(num==1){
					res += "0";
				}else{
					res += "1";
				}
			}else{
				res += arr2[i];
			}
		}
		return res;
	}

	public static String to_string3(int a, int b,char[] arr2){
		String res = "";
		for(int i=0; i<arr2.length; i++){
			if(i==a || i==b){
				int num = arr2[i]-48;
				if(num==1){
					res += "0";
				}else{
					res += "1";
				}
			}else{
				res += arr2[i];
			}
		}
		return res;
	}

	public static void recursion(String status, int index, int time){
		if(index==20){
			if(status.equals("00000000000000000000")){
				ans = Math.min(time, ans);
			}
			return;
		}
		if(index!=0 && index!=19){
			if(status.charAt(index-1)-48==1){
				status = to_string2(index-1, index, index+1, status.toCharArray());
				recursion(status, index+1, time+1);
			}else{
				recursion(status, index+1, time);
				status = to_string2(index-1, index, index+1, status.toCharArray());
				recursion(status, index+1, time+1);
			}
		}else if(index==0){
			recursion(status, index+1, time);
			status = to_string3(index, index+1, status.toCharArray());
			recursion(status, index+1, time+1);
		}else if(index==19){
			if(status.charAt(index-1)-48==1){
				status = to_string3(index-1, index, status.toCharArray());
				recursion(status, index+1, time+1);
			}else{
				recursion(status, index+1, time);
				status = to_string3(index-1, index, status.toCharArray());
				recursion(status, index+1, time+1);
			}
		}
	}

}
