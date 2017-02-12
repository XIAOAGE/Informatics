import java.util.Scanner;
import java.math.RoundingMode;
import java.text.DecimalFormat;

public class Main {

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		Double total=0.0;
		for(int i=0;i<12;i++){
			Double subBalance = in.nextDouble();
			total += subBalance;
		}
		DecimalFormat df = new DecimalFormat("0.00");
		df.setRoundingMode(RoundingMode.HALF_UP);
		df.setMinimumFractionDigits(2);
	    System.out.println("$"+df.format(total/12));
		
	}
}
