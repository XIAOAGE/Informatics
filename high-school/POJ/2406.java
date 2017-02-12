import java.util.Scanner;


public class Main {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(true){

			String line = in.nextLine();
			if(line.equals(".")){
				break;
			}

			int answer = -1;
			boolean judge;
			for(int i=1; i<line.length()/2; i++){

				judge = false;
				if(line.length()%i==0){
					judge = true;
					String standard = line.substring(0,i);	
					for(int index=i; index<=line.length()-i; index+=i){
						String check = line.substring(index, index+i);
						if(!check.equals(standard)){
							judge = false;
							break;
						}
					}		
				}
				if(judge){
					answer = i;
					break;
				}

			}
			if(answer==-1){
				System.out.println("1");
			}else{
				System.out.println(line.length()/answer);
			}

		}

	}

}
