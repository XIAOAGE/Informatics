import java.util.Scanner;


public class POJ_1753 {

	static int[][] map;
	static int[][] flag;
	static int[][] flag2;

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		map = new int[4][4];
		for(int i=0; i<4; i++){
			String line = in.nextLine();
			for(int j=0; j<4; j++){
				if(line.charAt(j)=='b'){
					map[i][j] = 1;
				}else{
					map[i][j] = 0;
				}
			}
		}

		int ans = Integer.MAX_VALUE;

		for(int i=0; i<=15; i++){ 
			flag = new int[4][4];
			flag2 = new int[4][4];
			int start1 = 0;
			int start2 = 0;
			for(int j=0; j<4; j++){
				if(((i>>j)&1)==1){
					start1++;
					flag[0][j] +=1;
					if(j+1<4){flag[0][j+1] += 1;}
					flag[1][j] += 1;
					if(j-1>=0){flag[0][j-1] += 1;}
				}
				if(((i>>j)&1)==1){
					start2++;
					flag2[0][j] +=1;
					if(j+1<4){flag2[0][j+1] += 1;}
					flag2[1][j] += 1;
					if(j-1>=0){flag2[0][j-1] += 1;}
				}
			}
			ans = Math.min(ans,brute_force(start1));
			ans = Math.min(ans, brute_force2(start2));
		}
		if(ans!=Integer.MAX_VALUE){
			System.out.println(ans);
		}else{
			System.out.println("Impossible");
		}

	}

	public static int brute_force(int start){ //all change to white		
		int ans = start;
		for(int i=1; i<4; i++){
			for(int j=0; j<4; j++){
				if((map[i-1][j]+flag[i-1][j])%2!=0){
					ans++;
					flag[i][j] += 1;
					flag[i-1][j] += 1;
					if(i+1<=3){flag[i+1][j]+=1;}
					if(j-1>=0){flag[i][j-1]+=1;}
					if(j+1<=3){flag[i][j+1]+=1;}
				}
			}
		}
		if(all_same1()){
			return ans;
		}else{
			return Integer.MAX_VALUE;
		}	
	}

	public static int brute_force2(int start){
		int ans = start;
		for(int i=1; i<4; i++){
			for(int j=0; j<4; j++){
				if((map[i-1][j]+flag2[i-1][j])%2!=1){
					ans++;
					flag2[i][j] += 1;
					flag2[i-1][j] += 1;
					if(i+1<=3){flag2[i+1][j]+=1;}
					if(j-1>=0){flag2[i][j-1]+=1;}
					if(j+1<=3){flag2[i][j+1]+=1;}
				}
			}
		}
		if(all_same2()){
			return ans;
		}else{
			return Integer.MAX_VALUE;
		}
	}

	public static boolean all_same1(){
		for(int i=0; i<4; i++){
			if((map[3][i]+flag[3][i])%2!=0){
				return false;
			}
		}
		return true;
	}
	
	public static boolean all_same2(){
		for(int i=0; i<4; i++){
			if((map[3][i]+flag2[3][i])%2==0){
				return false;
			}
		}
		return true;
	}


}
