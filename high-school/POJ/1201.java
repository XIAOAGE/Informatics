import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static final int INF = -100000000;

    static class edge{

        private int start;
        private int end;
        private int cost;

        public edge(int a, int b, int c){
            start = a;
            end = b;
            cost = c;
        }

    }

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        int number = in.nextInt();

        edge[] arr = new edge[number];
        int[] d = new int[60000];
        Arrays.fill(d, 0);
        
        int node = -1;
        int min = 10000000;
        for(int i=0; i<number; i++){
            int start = in.nextInt()-1;
            int end = in.nextInt();
            int cost = in.nextInt();
            node = node<end?end:node;
            min = min>start?start:min;
            edge input = new edge(start, end, cost);
            arr[i] = input;
        }
        
        for(int i=0; i<node; i++){
        	boolean update = false;
            for(int a=0; a<arr.length; a++){
                edge e = arr[a];
                int start = e.start;
                int end = e.end;
                int cost = e.cost;
                if(d[end]<d[start]+cost){
                    d[end] = d[start]+cost;
                    update = true;
                }
            }
            for(int a=1; a<=node; a++){
            	if(d[a-1]>d[a]){
            		d[a] = d[a-1];
            	}
            	if(d[a-1]<d[a]-1){
            		d[a-1] = d[a]-1;
            	}
            }
            
            if(!update){
            	break;
            }
        }
       
        System.out.println(d[node]-d[min]);
    }

}
