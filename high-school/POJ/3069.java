import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(true){
			int R = in.nextInt();
			int n = in.nextInt();
			if(R==-1&&n==-1){
				break;
			}
			
			int[] list = new int[n];
			for(int i=0; i<n; i++){
				list[i] = in.nextInt();
			}
			Arrays.sort(list);
			
			int answer = 0;
			
			int index = 0;
			label:
			while(index!=list.length){
				int position = list[index]+R;
				while(true){
					index++;
					if(index>=list.length){
						answer+=1;
						break label;
					}
					if(list[index]>position){
						answer+=1;
						index-=1;
						break;
					}
				}
			    position = list[index]+R;
			    while(true){
			    	index++;
			    	if(index>=list.length){
						break label;
					}
			    	if(list[index]>position){
			    		break;
			    	}
			    }
			}
			System.out.println(answer);
		}
		
	}
	
}
