import java.util.LinkedList;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		label:
		while(true){
			
			LinkedList<Integer> guess = new LinkedList<Integer>();
			LinkedList<String> relation = new LinkedList<String>();
			int right = 0;
			while(true){
				
				int number = Integer.parseInt(in.nextLine());
				if(number==0){break label;}
				String line = in.nextLine();
				if(line.equals("right on")){
					right = number;
					break;
				}
				guess.add(number);
				relation.add(line);
				
			}
			
			boolean judge = true;
			for(int i=0; i<relation.size(); i++){
				String rela = relation.get(i);
				int num = guess.get(i);
				if(right<num && !rela.equals("too high")){
					judge = false;
					break;
				}else if(num<right && !rela.equals("too low")){
					judge = false;
					break;
				}else if(right==num){
					judge = false;
					break;
				}
			}
			
			if(judge){
				System.out.println("Stan may be honest");
			}else{
				System.out.println("Stan is dishonest");
			}
			
		}
		
	}
	
}
