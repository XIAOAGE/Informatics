import java.util.Scanner;


public class Main {

	static int[] next;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		int count =1;
		while(true){
			int number = Integer.parseInt(in.nextLine());
			if(number==0){
				break;
			}
			System.out.printf("Test case #%d\n", count++);
			String line = in.nextLine();
			next = new int[line.length()+1];
			GetNext(line);
			
			for(int i=1; i<line.length(); i++){
				int j = i+1;
				int len = j-next[j];
				if(j%len==0 && j/len>1){
					System.out.println(j+" "+j/len);
				}
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
