

public class floyd_warshall {

    static int V;
    static int[][] parent;  //这个数组是用来做路径还原的。

    public static void main(String[] args){

        final int INF = 1000000000;

        int[][] graph = {
                {0,   5,  INF, 10},
                {INF, 0,   3, INF},
                {INF, INF, 0,   1},
                {INF, INF, INF, 0},
        };
        V = 4;
        parent = new int[4][4];
        //初始化记录路径的数组
        for(int i=0; i<4; i++){
            for(int a=0; a<4; a++){
                if(i==a){parent[i][a] = i;}
                else if(graph[i][a]!=0 && graph[i][a] != INF){parent[i][a] = i;}
                else{parent[i][a] = -1;}
            }
        }
        floydwarshall(graph);
    }

    public static void floydwarshall(int[][] graph){

        for(int a=0; a<V; a++){
            for(int b=0; b<V; b++){
                for(int c=0; c<V; c++){
                    if(graph[b][a]+graph[a][c]<graph[b][c]){
                        graph[b][c] = graph[b][a]+graph[a][c];
                        parent[b][c] = a;
                    }
                }
            }
        }

        for(int[] x: parent){
            for(int y: x){
                System.out.print(y+" ");
            }
            System.out.println();
        }

    }

}
