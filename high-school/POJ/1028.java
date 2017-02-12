import java.util.Scanner;
import java.util.Stack;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		Stack<String> backward = new Stack<String>();
		Stack<String> forward = new Stack<String>();
		
		String current = "http://www.acm.org/";
		
		while(true){
			
			String line = in.nextLine();
			String[] arr = line.split(" ");
			
			if(arr.length==1){
				String command = arr[0];
				if(command.equals("QUIT")){
					break;
				}else if(command.equals("BACK") && !backward.isEmpty()){
					String temp = backward.pop();
					System.out.println(temp);
					forward.push(current);
					current = temp;
				}else if(command.equals("FORWARD") && !forward.isEmpty()){
					String temp = forward.pop();
					System.out.println(temp);
					backward.push(current);
					current = temp;
				}else{
					System.out.println("Ignored");
				}
			}else if(arr.length==2){
				backward.push(current);
				current = arr[1];
				forward.clear();
				System.out.println(current);
			}
			
		}
		
	}
	
}
