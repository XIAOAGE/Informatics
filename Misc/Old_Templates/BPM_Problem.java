import java.util.Arrays;

/*
Try to maximize the job distribution so that everyone can get the job he interests in.

bpGraph: 1 means interest, 0 means not
match: elements mean applicants, index means job number. Match them

 */

public class BPM_Problem {

    static int N = 6; //The number of the job
    static int M = 6; //The number of the applicant
    static int[] match;
    static int[][] bpGraph ={
                                {0, 1, 1, 0, 0, 0},
                                {1, 0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0, 0},
                                {0, 0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 1}
                            };

    public static void main(String[] args){

        int ans = maxBPM(bpGraph);
        System.out.println(ans);

    }

    public static int maxBPM(int[][] graph){

        match = new int[N];
        Arrays.fill(match, -1);

        int result = 0;

        for(int u=0; u<M; u++){
            boolean[] visited = new boolean[N];

            if(dfs(u, visited)){
                result+=1;
            }
        }
        return result;

    }

    public static boolean dfs(int current, boolean[] visited){

        for(int v=0; v<N; v++){

            if(bpGraph[current][v]==1 && !visited[v]){
                visited[v] = true;

                if(match[v]==-1 || dfs(match[v], visited)){
                    match[v] = current;
                    return true;
                }
            }

        }
        return false;

    }

}
