import java.util.Scanner;

public class Main {

    static int[] memory;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        memory = new int[1000000];

        while(in.hasNext()){
        	int k = in.nextInt();
        	int j = in.nextInt();
        	int high = max(j,k);
        	int low = (k+j)-high;
        	int ans = -1;
        	for(int i=low; i<=high; i++){
        		int temp = recursion(i);
        		ans = max(ans, temp);
        	}
        	System.out.printf("%d %d %d\n", k, j, ans);
        }

    }

    public static int max(int a, int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }

    public static int recursion(int number){
        if(number==1){return 1;}
        if(number<memory.length && memory[number]!=0){
            return memory[number];
        }
        if(number%2!=0){
        	int temp = 1+recursion(3*number+1);
        	if(number<memory.length){
        		memory[number] = temp;
        	}
        	return temp;
        }else{
        	int temp = 1+recursion(number/2);
        	if(number<memory.length){
        		memory[number] = temp;
        	}
        	return temp;
        }
    }

}
