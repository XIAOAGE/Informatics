import java.util.Scanner;


public class Main {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(true){

			int[] packet = new int[6];
			int numOfZero = 0;
			for(int i=0; i<6; i++){
				int temp = in.nextInt();
				packet[i] = temp;
				if(temp==0){
					numOfZero+=1;
				}
			}
			if(numOfZero==6){
				break;
			}

			int answer = 0;
			answer+=packet[5];
			answer+=packet[4];
			packet[0] -= 11*packet[4];
			answer+=packet[3];
			if(packet[3]!=0){
				if(packet[1]<packet[3]*5){
					packet[0] -= (packet[3]*5-packet[1])*4;
					packet[1] = 0;
				}else{
					packet[1] -=packet[3]*5;
				}
			}
			answer+= packet[2]/4;
			int rest = 4-packet[2] % 4;
			if(rest==3){

				answer+=1;
				if(packet[1]<5){
					int temp = 5-packet[1];
					packet[1] = 0;
					packet[0] -= 7+temp*4;
				}else{
					packet[1]-=5;
					packet[0]-=7;
				}

			}else if(rest==2){

				answer+=1;
				if(packet[1]<3){
					int temp = 3-packet[1];
					packet[1] = 0;
					packet[0] -= 6+temp*4;
				}else{
					packet[1]-=3;
					packet[0]-=6;
				}

			}else if(rest==1){

				answer+=1;
				if(packet[1]<1){
					packet[0] -= 9;
				}else{
					packet[1]-=1;
					packet[0]-=5;
				}

			}

			if(packet[1]>0){

				answer += packet[1]/9;
				int Rest = 9-packet[1]%9;
				if(Rest!=9){
					answer+=1;
					packet[0] -= Rest*4;
				}

			}

			if(packet[0]>0){

				answer += packet[0]/36+1;
				int Rest = 36 -packet[0]%36;
				if(Rest==36){
					answer-=1;
				}

			}

			System.out.println(answer);

		}

	}

}
