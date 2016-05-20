import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {

	static Map<String, String> map = new HashMap<String, String>();

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(true){
			String line = in.nextLine();
			if(line.length()==0){break;}
			String[] words = line.split(" ");
			map.put(words[1], words[0]);
		}

		while(true){
			String word = in.nextLine();
			if(word.charAt(0)==' '){break;}
			if(map.get(word)!=null){
				System.out.println(map.get(word));
			}else{
				System.out.println("eh");
			}
		}

	}


}
