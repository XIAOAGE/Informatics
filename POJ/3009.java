import java.util.Scanner;


public class Main {

	static int[][] matrix;
	static int W = 0;
	static int H = 0;
	static int answer = Integer.MAX_VALUE;
	static int startX = 0;
	static int startY = 0;
	static int goalX = 0;
	static int goalY = 0;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		while(true){

			startX = 0;
			startY = 0;
			goalX = 0;
			goalY = 0;
			answer=Integer.MAX_VALUE;
			W = in.nextInt();
			if(W==0){break;}
			H = in.nextInt();

			matrix = new int[H][W];

			for(int i=0; i<H; i++){
				for(int a=0; a<W; a++){
					int temp = in.nextInt();
					matrix[i][a] = temp;
					if(temp==2){
						startX = i;
						startY = a;
					}else if(temp==3){
						goalX = i;
						goalY = a;
					}
				}
			}

			dfs(startX, startY, 0);
			if(answer == Integer.MAX_VALUE){
				System.out.println("-1");
			}else{
				System.out.println(answer);
			}

		}

	}

	public static void dfs(int x, int y, int step){
		
		if(step>10){
			return;
		}

		if(x==goalX && y == goalY){
			if(step<answer){answer = step;}
			return;
		}

		int tempX = x-1;
		while(tempX>=0){
			if(matrix[tempX][y]==1 && tempX == x-1){
				break;
			}
			if(matrix[tempX][y]==1){
				matrix[tempX][y] = 0;
				dfs(tempX+1, y, step+1);
				matrix[tempX][y] = 1;
				break;
			}else if(matrix[tempX][y]==3){
				dfs(tempX,y,step+1);
				return;
			}
			tempX--;
		}

		tempX = x+1;
		while(tempX<H){
			if(matrix[tempX][y]==1 && tempX == x+1){
				break;
			}
			if(matrix[tempX][y]==1){
				matrix[tempX][y] = 0;
				dfs(tempX-1, y, step+1);
				matrix[tempX][y] = 1;
				break;
			}else if(matrix[tempX][y]==3){
				dfs(tempX,y,step+1);
				return;
			}
			tempX++;
		}

		int tempY = y-1;
		while(tempY>=0){
			if(matrix[x][tempY]==1 && tempY == y-1){
				break;
			}
			if(matrix[x][tempY]==1){
				matrix[x][tempY] = 0;
				dfs(x, tempY+1, step+1);
				matrix[x][tempY] = 1;
				break;
			}else if(matrix[x][tempY]==3){
				dfs(x,tempY,step+1);
				return;
			}
			tempY--;
		}

		tempY = y+1;
		while(tempY<W){
			if(matrix[x][tempY]==1 && tempY == y+1){
				break;
			}
			if(matrix[x][tempY]==1){
				matrix[x][tempY] = 0;
				dfs(x, tempY-1, step+1);
				matrix[x][tempY] = 1;
				break;
			}else if(matrix[x][tempY]==3){
				dfs(x,tempY,step+1);
				return;
			}
			tempY++;
		}


	}

}
