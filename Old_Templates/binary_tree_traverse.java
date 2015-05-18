import java.util.Scanner;

public class Main {

	//prompt user to enter a list of integers, then build them in a complete binary tree using array to keep it.
	/*
	 * 1 output its pre-order traversing
	 * 2 output its post order
	 * 3 in order
	 * 4 output the hight of the tree
	 * 5 Given the ith number (in the list), and jth number is in the list
	 * please output its most near ancester
	 */
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		String line = in.nextLine();
		String[] tempnumber = line.split(" ");
		
		int[] number = new int[tempnumber.length];
		for(int i=0; i<number.length; i++){
			number[i] = Integer.parseInt(tempnumber[i]);
		}
		preOrder(0,number);
		System.out.println("##########");
		inOrder(0,number);
		System.out.println("##########");
		postOrder(0,number);
		System.out.println("##########");
		
		System.out.println(getHeight(number,0)+1);
		System.out.println("##########");
		
		int i = in.nextInt()-1;
		int j = in.nextInt()-1;
		System.out.println(getAnce(i,j));
	}
	
	public static void preOrder(int n, int[] number){
		if(n>(number.length-1)){
			return;
		}
		System.out.println(number[n]);
		preOrder(n*2+1,number);
		preOrder(n*2+2,number);
	}
	
	public static void inOrder(int n, int[] number){
		if(n>(number.length-1)){
			return;
		}
		inOrder(n*2+1,number);
		System.out.println(number[n]);
		inOrder(n*2+2,number);
	}
	
	public static void postOrder(int n, int[] number){
		if(n>(number.length-1)){
			return;
		}
		postOrder(n*2+1,number);
		postOrder(n*2+2,number);
		System.out.println(number[n]);
	}
	
	public static int getHeight(int[] number,int height){
		if(Math.pow(2, height)>=number.length){
			return height;
		}else{
		    return getHeight(number,height+1);
		}
	}
	
	public static int getAnce(int i, int j){
		if(i==j){
			return i;
		}else{
			return getAnce((i-1)/2,(j-1)/2);
		}
	}
	
}
