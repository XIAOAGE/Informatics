import java.util.Scanner;
import java.util.Stack;


public class Main {

	static int[] next;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			String line = in.nextLine();
			next = new int[line.length()+1];
			GetNext(line);
			Stack<Integer> sta = new Stack<Integer>();
			int i = line.length();
			sta.add(line.length());
			while(next[i]!=0){
				sta.add(next[i]);
				i = next[i];
			}
			while(!sta.isEmpty()){
				System.out.print(sta.pop()+" ");
			}
			System.out.println();
		}
		
	}

    public static void GetNext(String b){

        int i=0, j=-1;
        next[0] = -1;

        while(i<b.length()){
            if(j==-1 || b.charAt(i)==b.charAt(j)) {
                next[++i] = ++j;
            }else{
                j = next[j];
            }
        }

    }
	
}
