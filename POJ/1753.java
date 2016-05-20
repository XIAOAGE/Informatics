import java.util.Scanner;

public  class Main{
   static  int steps=Integer.MAX_VALUE; 
 //(x,y)坐标合起来就是中心点及上下左右坐标啦！
      static  int[] dx={0,0,0,1,-1}; 
      static  int[] dy={0,1,-1,0,0};  

     /* 
      * 把每一行的状态和整个状态都以2进制表示，四个2进制数排成一行，组成整个状态。
      * 1010
      * 0000
      * 1101
      * 1001
      *如图的状态表示为：1010000011011001
      * @param x横坐标点(注意：坐标系右下为(0,0)左上为（3,3））
      * @param y纵坐标点
      * @param source(整个状态如上面的1010000011011001）
      * @return 改变确定位置的状态，如1变成0或者0变成1 
      * */  

   public static int flip(int x, int y, int source){ 
          if(x >= 0 && x < 4 && y >= 0 && y < 4)  
            source ^= 1 << (x * 4 + y);
          return source; 
     }  


     /* 
      * @param current当前行
      * @param num 回合数
      * @param source 原数据，比如：1010000011011001
      * @param flag 标志 如果数据源当前位的状态不为flag，则翻动
      * */

     public static void dfs(int current,int num,int source,int flag){
          //如果最后一行已经翻完
          if(current==4){
              if(source==0xffff||source==0){
                  //已经完成了任务
                  steps=num< steps?num:steps;
              } 
             return; 
         }   

       //把当前行都翻成同种颜色 
         int x,y; 
         for (int i = current-1,j=0; j < 4; j++) {//每行有四个，翻或者不翻，所以需要四次 
             if( (((source& (1<< (i*4+j) ))>>(i*4+j)) ^ flag)==1 ){
                  /*source& (1<< (i*4+j) )>>(i*4+j) :把source中的(i,j)的状态取出来*/ 
                for (int k = 0; k <5; k++) {//当前，上下左右都得翻动 
                     x=current+dx[k]; 
                     y=j+dy[k];
                      source=flip(x, y, source); 
                 } 
                 num++; 
             }  
        }  

           //翻下一行 
         dfs(current+1, num, source, flag); 
      }  
 

     /*  第一行共有16种翻法（翻，翻，翻，翻）（翻，翻，翻，不翻）。。。（不翻，不翻，不翻，不翻）
      * */ 
     public static int solve(int source){  
         for (int i = 0; i < 16; i++) {  
             int num=0,temp=source,x,y;  
             for (int j = 0; j < 4; j++) { // 这个循环是翻第一行
                 if((i&(1<< j))>0){  
                     for (int k = 0; k <5; k++) {//当前，上下左右都得翻动  
                         x=0+dx[k];  
                         y=j+dy[k];  
                         temp=flip(x, y, temp);  
                     }  
                     num++;  
                 }  
             }  
  
             dfs(1, num, temp, 0);  //全部翻成白色
 
            dfs(1, num, temp, 1);  //全部翻成黑色
         }  
         return steps==Integer.MAX_VALUE?-1:steps;  
     }  

 public static void main(String[] args) {  
         Scanner scanner=new Scanner(System.in);  
         int source=0;  
         String string="";  
         for (int i = 0; i < 4; i++) {  
             string+=scanner.nextLine().trim();  
         }  

        // System.out.println(string);
         for (int i = 0; i < string.length(); i++) {  
                 source=(source<<1)+(string.substring(i, i+1).equals("b")?1:0);  
         }  
       //  System.out.println(Integer.toBinaryString(source));
         if(solve(source)!=-1){  
             System.out.println(steps);  
         }else {  
             System.out.println("Impossible");  
  
         }  
     }  
 }  
