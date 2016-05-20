import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		
		String crap = in.nextLine();

		Map<String, Integer> map = new HashMap<String, Integer>();

		for(int i=0; i<n; i++){

			String line = in.nextLine();
			String[] arr = line.split(" ");
			String word = arr[0];
			int val = Integer.parseInt(arr[1]);
			map.put(word, val);

		}

		for(int i=0; i<m; i++){

			int output = 0;

			while(true){
				String sentence = in.nextLine();
				if(sentence.equals(".")){
					break;
				}
				String[] arr = sentence.split(" ");
				for(String x: arr){
					if(map.get(x)!=null){
						output+= map.get(x);
					}
				}
			}
			System.out.println(output);
		}

	}

}
