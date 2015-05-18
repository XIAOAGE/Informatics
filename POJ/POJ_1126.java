import java.util.Scanner;
import java.util.Stack;


public class POJ_1126 {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			String line = in.nextLine();
			Stack<Boolean> sta = new Stack<Boolean>();
			for(int i=line.length()-1; i>=0; i--){
				char a = line.charAt(i);
				if(a>=112 && a<=122){
					sta.push(true);
				}else if(a=='N'){
					if(sta.size()>=1){
						sta.push(sta.pop());
					}else{
						sta.clear();
						sta.push(false);
						break;
					}
				}else{
					if(sta.size()>=2){
						sta.push(sta.pop() && sta.pop());
					}else{
						sta.clear();
						sta.push(false);
						break;
					}
				}
			}
			if(sta.pop() && sta.size()==0){
				System.out.println("YES");
			}else{
				System.out.println("NO");
			}
		}

	}

}
