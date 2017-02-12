//* @author 
/*贪心算法
 *思想就是先按排序,从前向后一点一点找,如果第一个牛不能到1则返回-1,中间出了断档也返回-1,最后不能到t也要返回-1.
 */

import java.util.Arrays;
import java.util.Scanner;

//贪心加排序,用到了comparable接口

public class Main {
	Scanner cin = new Scanner(System.in);
	int n;
	int t;
	Cows[] cows;

	public void inPut() {
		n = cin.nextInt();
		t = cin.nextInt();
		cows = new Cows[n];
		for (int i = 0; i < n; i++) {
			cows[i] = new Cows();
			cows[i].a = cin.nextInt();
			cows[i].b = cin.nextInt();
		}
		calculate();
	}

	private void calculate() {
		int result = 0;
		Arrays.sort(cows);
		// System.out.println(Arrays.toString(cows));
		if(cows[0].a > 1) {
			System.out.println(-1);
			return;
		}
		int temp = cows[0].b;
		int i = 0;

		while (temp < t && i < n) {
			int temp2 = 0;
			int flag = 0;
			while (i < n && cows[i].a <= temp + 1) {
				flag = 1;
				if (cows[i].b > temp2) {
					temp2 = cows[i].b;
				}
				i++;
			}

			if (flag == 0) {
				System.out.println("-1");
				return; 
			}
			temp = temp2;
			result++;
		}

		if(temp < t) {
			System.out.println("-1");
			return;
		}
		System.out.println(result + 1);
	}

	public static void main(String[] args) {
		new Main().inPut();
	}
}

class Cows implements Comparable< Cows> {
	int a;
	int b;

	public int compareTo(Cows o) {
		return this.a - o.a;
	}

	public String toString() {
		return this.a + " " + this.b;
	}
}
