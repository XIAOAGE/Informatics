import java.util.Scanner;


public class POJ_2632 {

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int K = in.nextInt();

			while(K--!=0){
				int len = in.nextInt();
				int width = in.nextInt();
				int[][] map = new int[width+1][len+1];
				int N = in.nextInt();
				int M = in.nextInt();
				int[] direction = new int[N+1];
				int[] x = new int[N+1];
				int[] y = new int[N+1];
				String skip = in.nextLine();
				for(int i=1; i<=N; i++){
					String line = in.nextLine();
					String[] temp2 = line.split(" ");
					int y1 = Integer.parseInt(temp2[0]);
					int x1 = width-Integer.parseInt(temp2[1])+1;
					String z = temp2[2];
					x[i] = x1;
					y[i] = y1;
					if(z.equals("E")){
						direction[i] = 1;
					}else if(z.equals("S")){
						direction[i] = 2;
					}else if(z.equals("W")){
						direction[i] = 3;
					}else if(z.equals("N")){
						direction[i] = 4;
					}
					map[x1][y1] = i;
				}
				boolean result = false;
				label:
				for(int i=0; i<M; i++){
					String line = in.nextLine();
					String[] temp2 = line.split(" ");
					int number = Integer.parseInt(temp2[0]);
					String action = temp2[1];
					int distance = Integer.parseInt(temp2[2]);
					if(result){
						continue;
					}
					if(action.equals("F")){
						if(direction[number]==1){
							for(int k=y[number]+1; k<=y[number]+distance && k<=len; k++){
								if(map[x[number]][k]!=0){
									System.out.printf("Robot %d crashes into robot %d\n", number, map[x[number]][k]);
									result = true;
									continue label;
								}
							}
							if(y[number]+distance>len){
								System.out.printf("Robot %d crashes into the wall\n", number);
								result = true;
							}else{
								map[x[number]][y[number]] = 0;
								y[number] += distance;
								map[x[number]][y[number]]=number;	
							}
						}else if(direction[number]==2){
							for(int k=x[number]+1; k<=x[number]+distance && k<=width; k++){
								if(map[k][y[number]]!=0){
									System.out.printf("Robot %d crashes into robot %d\n", number, map[k][y[number]]);
									result = true;
									continue label;
								}
							}
							if(x[number]+distance>width){
								System.out.printf("Robot %d crashes into the wall\n", number);
								result = true;
							}else{
								map[x[number]][y[number]] = 0;
								x[number] += distance;
								map[x[number]][y[number]]=number;	
							}
						}else if(direction[number]==3){
							for(int k=y[number]-1; k>=y[number]-distance && k>=1; k--){
								if(map[x[number]][k]!=0){
									System.out.printf("Robot %d crashes into robot %d\n", number, map[x[number]][k]);
									result = true;
									continue label;
								}
							}
							if(y[number]-distance<1){
								System.out.printf("Robot %d crashes into the wall\n", number);
								result = true;
							}else{
								map[x[number]][y[number]] = 0;
								y[number] -= distance;
								map[x[number]][y[number]]=number;	
							}
						}else if(direction[number]==4){
							for(int k=x[number]-1; k>=x[number]-distance && k>=1; k--){
								if(map[k][y[number]]!=0){
									System.out.printf("Robot %d crashes into robot %d\n", number, map[k][y[number]]);
									result = true;
									continue label;
								}
							}
							if(x[number]-distance<1){
								System.out.printf("Robot %d crashes into the wall\n", number);
								result = true;
							}else{
								map[x[number]][y[number]] = 0;
								x[number] -= distance;
								map[x[number]][y[number]]=number;	
							}
						}
					}else if(action.equals("R")){
						distance %= 4;
						direction[number] = (direction[number]+distance) % 4;
						direction[number] = direction[number]==0?4:direction[number];
					}else if(action.equals("L")){
						int temp = distance%4;
						direction[number] = (4+number-temp) %4;
						//direction[number] = direction[number]==0?4:direction[number];
					}
				}
				if(!result){
					System.out.println("OK");
				}
			}

	}

}
