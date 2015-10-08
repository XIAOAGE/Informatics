import java.util.Scanner;


public class Line_Segment_Tree {

    static class node{
        int addMark;
        int val;
    }

    static int[] value = {-1,2,3,1,5,4,9};  //For convenience, 6 elements in the array
    static node[] tree;
    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        tree = new node[16];
        build_tree(1,1,6);
        System.out.println(query(1, 2, 6, 1, 6));

    }

    public static void build_tree(int root, int left, int right){
        tree[root] = new node();
        tree[root].addMark = 0;
        if(left==right){	//leaf
            tree[root].val = value[left];
            return;
        }else{
            int mid = (left+right)/2;
            build_tree(root*2, left, mid);
            build_tree(root*2+1, mid+1, right);
            tree[root].val = min(tree[root*2].val, tree[root*2+1].val);
        }
    }

    public static void push_down(int root){
        if(tree[root].addMark!=0){
            tree[root*2].addMark += tree[root].addMark;
            tree[root*2+1].addMark += tree[root].addMark;
            tree[root*2].val += tree[root].addMark;
            tree[root*2+1].val += tree[root].addMark;
            tree[root].addMark = 0;
        }
    }

    public static int query(int root, int start, int end, int left, int right){
        //no common set
        if(start>right || end<left){
            return INF;
        }
        if(start<=left && end>=right){
            return tree[root].val;
        }
        push_down(root);
        int mid = (left+right)/2;
        return min(query(root*2, start, end, left, mid),
                query(root*2+1, start, end, mid+1, right));
    }

    public static void update(int root, int start, int end, int left, int right, int addVal){
        if(start>right || end<left){
            return;
        }
        if(start<=left && end>=right){
            tree[root].addMark += addVal;
            tree[root].val += addVal;
            return;
        }
        push_down(root);
        int mid = (left+right)/2;
        update(root*2, start, end, left, mid, addVal);
        update(root*2+1, start, end, mid+1, right, addVal);
        tree[root].val = min(tree[root*2].val, tree[root*2+1].val);
    }

    public static int min(int a, int b){
        if(a<b){
            return a;
        }else{
            return b;
        }
    }

}
