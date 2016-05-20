import java.io.BufferedReader;
 import java.io.InputStreamReader;
 import java.util.Arrays;
 import java.util.StringTokenizer;

 public class Main {

     static boolean[] used;
     static int len;
     static int[] s;
     static int sum;
     static int max;
     static int parts;

     public static void main(String[] args) throws Exception {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         while ((len = Integer.parseInt(read.readLine())) != 0) {
             s = new int[len];
             StringTokenizer take = new StringTokenizer(read.readLine());
             int index = 0;
             sum = 0;
             used = new boolean[len];
             while (take.hasMoreTokens()) {
                 s[index] = Integer.parseInt(take.nextToken());
                 sum += s[index++];
             }
             Arrays.sort(s);
             max = s[len - 1];
             for (; max <= sum; max++) {
                 if (sum % max == 0) {
                     parts = sum / max;
                     if (search(0, len - 1, 0)) {
                         System.out.println(max);
                         break;
                     }
                 }
             }
         }
     }

     public static boolean search(int res, int next, int cpl) {
         if (res == max) {
             res = 0;
             next = len - 2;
             cpl++;
         }
         if (cpl == parts) {
             return true;
         }
         while (next >= 0) {
             if (used[next] == false) {
                 if (res + s[next] <= max) {
                     used[next] = true;
                     if (search(res + s[next], next - 1, cpl)) {
                         return true;
                     }
                     used[next] = false;
                     if (res == 0) {
                         break;
                     }
                     if (res + s[next] == max) {
                         break;
                     }
                 }
                 int i = next - 1;
                 while (i >= 0 && s[i] == s[next]) {
                     i--;
                 }
                 next = i;
                 int l_s = 0;
                 for (int j = next; j >= 0; j--) {
                     if (!used[j]) {
                         l_s += s[j];
                     }
                 }
                 if (l_s < max - res) {
                     break;
                 }
                 continue;
             }
             next--;
         }
         return false;
     } 
}
