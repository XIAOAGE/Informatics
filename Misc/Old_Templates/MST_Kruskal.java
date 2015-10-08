import java.util.PriorityQueue;
import java.util.Scanner;

/*
This is from poj 2421, a problem used to kruskal model
 */

public class MST_Kruskal {

    static class e implements Comparable<e>{

        private int start;
        private int end;
        private int cost;

        public e(int a, int b, int c){
            start = a;
            end = b;
            cost = c;
        }

        public int compareTo(e o) {
            if(this.cost<o.cost){
                return -1;
            }else if(this.cost>o.cost){
                return 1;
            }
            return 0;
        }

    }

    static int[] parent;
    static int[] rank;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        PriorityQueue<e> pq = new PriorityQueue<e>();

        int number = in.nextInt();
        parent = new int[number+1];
        rank = new int[number+1];

        int[][] matrix = new int[number+1][number+1];
        for(int i=1; i<=number; i++){
            for(int j=1; j<=number; j++){
                matrix[i][j] = in.nextInt();
            }
        }

        int number2 = in.nextInt();
        for(int i=0; i<number2; i++){
            int a = in.nextInt();
            int b = in.nextInt();
            matrix[a][b] = 0;
            matrix[b][a] = 0;
        }

        /*
        这上面的代码只是针对这个particular问题， 实质是读入了一个邻接矩阵。
        下面是kruskal的核心部分
         */

        for(int i=1; i<=number; i++){
            for(int j=1; j<=number; j++){
                if(i==j){continue;}
                pq.add(new e(i,j,matrix[i][j]));       //只是把边全部放入堆里面
            }
        }

        for(int i=1; i<=number; i++){
            parent[i] = i;              //make elements in parent array point to themself
        }

        int count = 0;
        int minCost = 0;
        while(count<number-1 && pq.size()!=0){  //只要边的数量到定点数-1时或者堆空，结束循环。实质堆空只是针对MST不存在的情况

            e nextE = pq.poll();
            int start = nextE.start;
            int end = nextE.end;

            int root1 = findRoot(start);
            int root2 = findRoot(end);

            if(root1!=root2){
                union(root1, root2);
                count++;
                minCost += nextE.cost;
            }

        }
        System.out.println(minCost);

    }

    public static int findRoot(int number){

        int num = number;
        while(parent[number]!=number){
            number = parent[number];
        }
        while(num!=parent[num]){
            int temp = num;
            num = parent[num];
            parent[temp] = number;
        }
        return number;

    }

    public static void union(int a, int b){

        if(rank[a]>rank[b]){
            parent[b] = a;
            rank[a]++;
        }else{
            parent[a] = b;
            rank[b]++;
        }

    }

}
