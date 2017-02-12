//* @author: <strong>
import java.util.*;
public class Main
{
	private int t;
	private int b[];

	public Main(int t){
		this.t=t;
		b=new int[1000000];
	}

	private void doIt(){
		int st=0;
		while(true){
			t/=10;
			t%=10000;//取t的中间四位
			t*=t;//平方
			t%=1000000;//取t的后六位
			if (b[t]!=0){//如果t出现过,发现循环数
				st++;
				System.out.println(t+" "+(st-b[t])+" "+st);//循环节的第一个数，循环节大小和需要几次发现循环节
				break;
			}
			b[t]=++st;//记录计算的次数
		}
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int t=sc.nextInt();
			Main m=new Main(t);
			m.doIt();
		}

	}
}
