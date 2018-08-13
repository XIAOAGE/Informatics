import java.util.Arrays;
import java.util.Scanner;


public class Bellman_Ford {

    static final int INF = 1000000;

    static class edge{
        int start;
        int end;
        int dis;

        public edge(int a,int b, int c){
            start = a;
            end = b;
            dis = c;
        }
    }

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();                   //边的数量
        int N = in.nextInt();                   //顶点数量

        edge[] edge = new edge[T];
        for(int i=0; i<T; i++){
            int start = in.nextInt();
            int end = in.nextInt();
            int dis = in.nextInt();
            edge[i] = new edge(start, end, dis);
        }

        int[] d = new int[N+1];
        Arrays.fill(d, INF);
        d[N] = 0;

        for(int i=1; i<=N-1; i++){              //外层的次数是N-1次即可，因为这是简单的一条路能经过的最多顶点数
            for(int j=0; j<edge.length; j++){
                edge e = edge[j];
                int start = e.start;
                int end = e.end;
                int dis = e.dis;
                if(d[start]+dis<d[end]){
                    d[end] = d[start]+dis;
                }
                if(d[end]+dis<d[start]){      //该模板题中图是双向边， 单向去掉即可
                    d[start] = d[end]+dis;
                }
            }
        }
        System.out.println(d[1]);

        /* check for negative-weight cycles.
           *********************************
           for(int j=0; j<edge.length; j++){
                edge e = edge[j];
                int start = e.start;
                int end = e.end;
                int dis = e.dis;
                if(d[start]+dis<d[end]){
                    d[end] = d[start]+dis;
                    System.out.println("there's negative cycle")
                }
                if(d[end]+dis<d[start]){
                    d[start] = d[end]+dis;
                    System.out.println("there's negative cycle")
                }
            }
         */

    }

}
