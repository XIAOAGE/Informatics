import java.util.LinkedList;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		while(true){
			
			String line = in.nextLine();
			if(line.equals("0")){break;}
			String[] arr = line.split(" ");
			int number = Integer.parseInt(arr[0]);
			String str = arr[1];
			LinkedList<Character> list = new LinkedList<Character>();
			LinkedList<Character> unsatisfy = new LinkedList<Character>();
			int ans = 0;

			for(int i=0; i<str.length(); i++){
				char current = str.charAt(i);
				if(list.contains((Character)current)){
					list.remove((Character)current);
				}else if(list.size()<number){
					list.add(current);
				}else if(!unsatisfy.contains(current)){
					unsatisfy.add(current);
					ans+=1;
				}
			}
			
			if(ans==0){
				System.out.println("All customers tanned successfully.");
			}else{
				System.out.printf("%d customer(s) walked away.\n", ans);
			}
			
		}
		
	}
	
}
