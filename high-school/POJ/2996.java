import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Main {
	
	static ArrayList<chess> white;
	static ArrayList<black_chess> black;
	static int[] val;
	
	static class chess implements Comparable<chess>{
		String pos;
		public chess(String a){
			pos = a;
		}
	
		public int compareTo(chess o) {
			String tmp1 = this.pos;
			String tmp2 = o.pos;
			if(tmp1.length()==2 && tmp2.length()==3){
				return 1;
			}else if(tmp1.length()==3 && tmp2.length()==2){
				return -1;
			}else if(tmp1.length()==2 && tmp2.length()==2){
				if(tmp1.charAt(1)<tmp2.charAt(1)){
					return -1;
				}else if(tmp1.charAt(1)>tmp2.charAt(1)){
					return 1;
				}else{
					if(tmp1.charAt(0)<tmp2.charAt(0)){
						return -1;
					}else{
						return 1;
					}
				}
			}else{
				if(val[tmp1.charAt(0)]<val[tmp2.charAt(0)]){
					return -1;
				}else if(val[tmp1.charAt(0)]>val[tmp2.charAt(0)]){
					return 1;
				}else{
					if(tmp1.charAt(2)<tmp2.charAt(2)){
						return -1;
					}else if(tmp1.charAt(2)>tmp2.charAt(2)){
						return 1;
					}else{
						if(tmp1.charAt(1)<tmp2.charAt(1)){
							return -1;
						}else if(tmp1.charAt(1)>tmp2.charAt(1)){
							return 1;
						}
					}
				}
			}
			return 0;
		}
	}
	
	static class black_chess implements Comparable<black_chess>{

		String pos;
		
		public black_chess(String a){
			pos = a;
		}
		
		public int compareTo(black_chess o) {
			String tmp1 = this.pos;
			String tmp2 = o.pos;
			if(tmp1.length()==2 && tmp2.length()==3){
				return 1;
			}else if(tmp1.length()==3 && tmp2.length()==2){
				return -1;
			}else if(tmp1.length()==2 && tmp2.length()==2){
				if(tmp1.charAt(1)>tmp2.charAt(1)){
					return -1;
				}else if(tmp1.charAt(1)<tmp2.charAt(1)){
					return 1;
				}else{
					if(tmp1.charAt(0)<tmp2.charAt(0)){
						return -1;
					}else{
						return 1;
					}
				}
			}else{
				if(val[tmp1.charAt(0)]<val[tmp2.charAt(0)]){
					return -1;
				}else if(val[tmp1.charAt(0)]>val[tmp2.charAt(0)]){
					return 1;
				}else{
					if(tmp1.charAt(2)>tmp2.charAt(2)){
						return -1;
					}else if(tmp1.charAt(2)<tmp2.charAt(2)){
						return 1;
					}else{
						if(tmp1.charAt(1)<tmp2.charAt(1)){
							return -1;
						}else if(tmp1.charAt(1)>tmp2.charAt(1)){
							return 1;
						}
					}
				}
			}
			return 0;
		}
		
	}

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		white = new ArrayList<chess>();
		black = new ArrayList<black_chess>();
		val = new int[100];
		val[75] = 1;
		val[81] = 2;
		val[82] = 3;
		val[66] = 4;
		val[78] = 5;
		int row = 8;
		int col = 97;
		for(int i=1; i<=8; i++, row--){
			String trash = in.nextLine();
			String line = in.nextLine();
			line = line.substring(2,line.length()-2);
			for(int j=0; j<line.length(); j+=4, col++){
				if(line.charAt(j)==80){
					white.add(new chess((char)col+""+row));
				}else if(line.charAt(j)==112){
					black.add(new black_chess((char)col+""+row));
				}else if(line.charAt(j)>=97 && line.charAt(j)<=122){
					String pos = (line.charAt(j)+"").toUpperCase()+""+(char)col+""+row;
					black.add(new black_chess(pos));
				}else if(line.charAt(j)>=65 && line.charAt(j)<=90){
					String pos = (line.charAt(j)+"").toUpperCase()+""+(char)col+""+row;
					white.add(new chess(pos));
				}
			}
			col = 97;
		}
		String trash = in.nextLine();
		String white_ans = "White: ";
		String black_ans = "Black: ";
		Collections.sort(white);
		Collections.sort(black);
		for(chess x: white){
			white_ans = white_ans + x.pos+",";
		}
		for(black_chess x: black){
			black_ans = black_ans + x.pos+",";
		}
		System.out.println(white_ans.substring(0,white_ans.length()-1));
		System.out.println(black_ans.substring(0,black_ans.length()-1));
	}
	
}
