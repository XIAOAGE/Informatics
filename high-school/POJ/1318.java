import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		Map<String, LinkedList<String>> map = new HashMap<String, LinkedList<String>>();
		while(true){
			String line = in.nextLine();
			if(line.equals("XXXXXX")){break;}
			char[] arr = line.toCharArray();
			Arrays.sort(arr);
			String line2 = "";
			for(char x : arr){
				line2 += x;
			}
			if(map.get(line2)==null){
				LinkedList<String> newList = new LinkedList<String>();
				newList.add(line);
				map.put(line2, newList);
			}else{
				LinkedList<String> newList = map.get(line2);
				newList.add(line);
				map.put(line2, newList);
			}
		}

		while(true){

			String line = in.nextLine();
			if(line.equals("XXXXXX")){break;}
			char[] arr = line.toCharArray();
			Arrays.sort(arr);
			line = "";			
			for(char x: arr){
				line += x;
			}
			LinkedList<String> newList = map.get(line);
			if(newList==null){
				System.out.println("NOT A VALID WORD");
			}else{
				Collections.sort(newList);
				for(int x=0; x<newList.size(); x++){
					System.out.println(newList.get(x));
				}
			}
			System.out.println("******");

		}

	}

}
