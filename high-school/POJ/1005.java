import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {

	public static void main(String[] args){
		int temp =1;
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		for(int i=0;i<num;i++){		
				Double x = in.nextDouble();
				Double y = in.nextDouble();
				Double distance = Math.pow(x*x+y*y, 0.5);
				Double year = distance*distance*Math.PI*0.5/50;
				BigDecimal bd = new BigDecimal(year);
				int realYear = bd.setScale(0, RoundingMode.UP).intValue();
				System.out.println("Property " + temp+": This property will begin eroding in year "+realYear+".");
				temp++;
			}
		System.out.println("END OF OUTPUT.");
		}
}

