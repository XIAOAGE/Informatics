import java.util.Scanner;
import java.util.Stack;


public class POJ_3295{
	
	static Stack<Boolean> sta;
	static boolean p;
	static boolean q;
	static boolean r;
	static boolean s;
	static boolean t;
	static String line;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(true){
			line = in.nextLine();
			if(line.equals("0")){
				break;
			}
			boolean judge = true;
			for(int i=0; i<32; i++){
				sta = new Stack<Boolean>();
				p = (i>>0 & 1)==1? true : false;
				q = (i>>1 & 1)==1? true : false;
				r = (i>>2 & 1)==1? true : false;
				s = (i>>3 & 1)==1? true : false;
				t = (i>>4 & 1)==1? true : false;
				if(!solve()){
					judge = false;
					break;
				}
			}
			if(judge){
				System.out.println("tautology");
			}else{
				System.out.println("not");
			}
		}
		
	}
	
	public static boolean solve(){
		for(int i=line.length()-1; i>=0; i--){
			char a = line.charAt(i);
			if(a=='q'){
				sta.push(q);
			}else if(a=='p'){
				sta.push(p);
			}else if(a=='r'){
				sta.push(r);
			}else if(a=='s'){
				sta.push(s);
			}else if(a=='t'){
				sta.push(t);
			}else if(a=='N'){
				sta.push(!sta.pop());
			}else if(a=='K'){
				sta.push(sta.pop() & sta.pop());
			}else if(a=='A'){
				sta.push(sta.pop() | sta.pop());
			}else if(a=='C'){
				sta.push(!sta.pop() | sta.pop());
			}else if(a=='E'){
				sta.push(!(sta.pop() ^ sta.pop()));
			}
		}
		return sta.pop();
	}
	
}