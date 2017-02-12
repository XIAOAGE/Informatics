import java.util.Scanner;


public class Main{

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int[] X = new int[16];
		int[] Y = new int[16];
		int[] Z = new int[16];
		for(int i=0; i<16; i++){
			X[i] = in.nextInt();
			Y[i] = in.nextInt();
			Z[i] = in.nextInt();
		}

		while(in.hasNext()){
			int x = in.nextInt();
			if(x==-1){
				break;
			}
			int y = in.nextInt();
			int z = in.nextInt();
			double min = Double.MAX_VALUE;
			int x3 = -1;
			int y3 = -1;
			int z3 = -1;
			for(int i=0; i<16; i++){
				if(min>cal_dis(X[i],Y[i],Z[i],x,y,z)){
					x3 = X[i];
					y3 = Y[i];
					z3 = Z[i];
					min = cal_dis(X[i],Y[i],Z[i],x,y,z);
				}
			}
			System.out.printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x,y,z,x3,y3,z3);
		}

	}

	public static double cal_dis(int x1, int y1, int z1, int x2, int y2, int z2){
		return Math.sqrt(Math.pow(x2-x1, 2)+Math.pow(y2-y1, 2)+Math.pow(z2-z1, 2));
	}

}
