import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;


public class LongestPath_withTopoSort {

    static edge[] e;
    static int[] w;
    static int[] indegree;
    static int[] outdegree;
    static int[] first_edge;   //This is the used to find the edge for any node.(explained specially below)
    static int[] save;   //This is used save the index of nodes that have outdegree of 0
    static int[] topo_array;    //used to keep the topological order
    static int[] d;
    static final int INF = -100000000;
    static int numOfNode;
    static int numOfEdge;
    static int cnt;
    static int count;
    static int count2;

    static class edge{
        int v;
        int w;
        int next;

        public edge(int a, int b){
            v = a;
            w = b;
        }
    }

    public static void init(){
        cnt = 0;
        count = 0;
        count2 = 0;
        d = new int[numOfNode+1];
        w = new int[numOfNode+1];
        topo_array = new int[numOfNode+1];
        save = new int[numOfNode+1];
        indegree = new int[numOfNode+1];
        outdegree = new int[numOfNode+1];
        e = new edge[1000010];
        first_edge = new int[numOfNode+1];
        Arrays.fill(first_edge, -1);
    }

    public static void read_edge(int x, int y, int w){
        edge current = new edge(y,w);
        current.next = first_edge[x];//because a node can have more than one edge pointing out from it. We need that array to record the next edge.
        e[cnt] = current;
        first_edge[x] = cnt++;    //cnt is the index of the current edge in the e array
    }

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        while(in.hasNext()){
            numOfNode = in.nextInt();
            numOfEdge = in.nextInt();

            init();
            for(int i=1; i<=numOfNode; i++){
                w[i] = in.nextInt();
            }

            for(int i=0; i<numOfEdge; i++){
                int x = in.nextInt();
                int y = in.nextInt();
                indegree[y]++;
                outdegree[x]++;
                read_edge(x,y,w[y]);
            }

            for(int i=1; i<=numOfNode; i++){
                if(indegree[i]==0){
                    read_edge(0,i,w[i]);  //把所有入度为0的点都归于一个虚拟点
                    indegree[i]++;
                }
                if(outdegree[i]==0){
                    save[count++] = i; //记录所有出度为0的点的index
                    //count只是用来记录出度为0的点的个数
                }
            }
            topo_sort();
            DAGShortestPath();
            //题目里入度为0的点是起点，出度为0的点是终点
            int ans = INF;
            for(int i=0; i<count; i++){
                ans = max(ans,d[save[i]]);
            }

            System.out.println(ans);
        }
    }

    public static void topo_sort(){
        Stack<Integer> sta = new Stack<Integer>();
        sta.push(0);
        while(!sta.isEmpty()){
            int current = sta.pop();
            topo_array[count2++] = current;
            for(int i = first_edge[current]; i!=-1; i = e[i].next){
                //对当前节点的所有边进行循环
                int v = e[i].v;
                if(--indegree[v]==0){
                    sta.push(v);
                }
            }
        }
    }

    public static void DAGShortestPath(){
        d[0] = 0;
        for(int i=1; i<=numOfNode; i++){
            d[i] = INF;
        }
        //count2只是topo_array的长度罢了
        for(int u = 0; u<count2; u++){
            int x = topo_array[u];
            for(int i=first_edge[x]; i!=-1; i=e[i].next){
                int v = e[i].v;
                int w = e[i].w;
                if(d[v]<d[x]+w){
                    d[v] = d[x]+w;
                }
            }
        }
    }

    public static int max(int a, int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }

} 
