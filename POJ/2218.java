import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			
			String start = in.nextLine();
			TreeMap<Integer, String> map = new TreeMap<Integer, String>();
			while(true){
				String line = in.nextLine();
				if(line.equals("END")){break;}
				String[] arr = line.split(" ");
				String name = arr[0];
				int weight = (Integer.parseInt(arr[2])-Integer.parseInt(arr[1]))*-1;
				map.put(weight, name);
			}
			Set<Integer> set = map.keySet();
			Iterator<Integer> itr = set.iterator();
			while(itr.hasNext()){
				System.out.println(map.get(itr.next()));
			}
			System.out.println();
		}
		
	}
	
}
