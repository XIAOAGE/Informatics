import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	static public char returnValue(char c) {
		if (c <= 67 && c >= 65) {
			return '2';
		} else if (c <= 70 && c >= 68) {
			return '3';
		} else if (c <= 73 && c >= 71) {
			return '4';
		} else if (c <= 76 && c >= 74) {
			return '5';
		} else if (c <= 79 && c >= 77) {
			return '6';
		} else if (c <= 83 && c >= 80) {
			return '7';
		} else if (c <= 86 && c >= 84) {
			return '8';
		} else if (c <= 89 && c >= 87) {
			return '9';
		} else {
			return '0';
		}
	}

	public static String parse(String str) {
		String temp = "";
		for (int j = 0; j < str.length(); j++) {
			if (str.charAt(j) == '-') {
				continue;
			} else {
				char t = str.charAt(j);
				if (t >= '0' && t <= '9') {
					temp += t;
				} else {
					temp += returnValue(t);
				}
			}
		}
		return temp;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Map<String, Integer> m = new HashMap<String, Integer>();
		int ncase = Integer.parseInt(in.readLine());
		while (ncase-- != 0) {
			String str = in.readLine();
			/*此方法太耗时，不可用
			 * str = str.replaceAll("-", "").replaceAll("[ABC]", "2")
			 * .replaceAll("[DEF]", "3").replaceAll("[GHI]", "4")
			 * .replaceAll("[JKL]", "5").replaceAll("[MNO]", "6")
			 * .replaceAll("[PRS]", "7").replaceAll("[TUV]", "8")
			 * .replaceAll("[WXY]", "9");
			 */
			str = parse(str);
			Integer times = m.get(str);
			m.put(str, times == null ? 1 : times + 1);
		}
		Set<String> keys = new TreeSet<String>(m.keySet());
		boolean hasOutput = false;
		for (Iterator<String> it = keys.iterator(); it.hasNext();) {
			String key = it.next();
			if (m.get(key) > 1) {
				hasOutput = true;
				System.out.println(key.substring(0, 3) + "-"
						+ key.substring(3, 7) + " " + m.get(key));
			}
		}
		if (!hasOutput) {
			System.out.println("No duplicates.");
		}
	}
}
