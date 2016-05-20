#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
//toposort的三种情况
//188K 0MS
const int N=27;
int n,m;
int graph[N][N],indegree[N],list[N];

int toposort(int n)
{
    int in[N];
    memcpy(in,indegree,sizeof(indegree)); //复制入度数组，以免对主函数中的indegree有影响
    stack<int> s;
    int i;
    for(i=0;i<n;i++)
        if(!in[i])
            s.push(i);//所有入度为0的点入栈，如果这些点多于1的话，序列不确定
    int flag=0;
    int t,j=0;
    while(!s.empty())
    {
        if(s.size()>1)
            flag=1;    //序列不确定
        t=s.top();
        s.pop();
        list[j++]=t;   //记录出栈的数字
        for(i=0;i<n;i++)
            if(graph[t][i])
                if(--in[i]==0)
                    s.push(i);//入度为0的点入栈
    }
    if(j!=n)//不能拓扑排序，即有环
        return 1;
    else if(flag==1)//有多种排序方式，不能唯一确定
        return 2;
    return 0;//序列能够被唯一确定
}

int main()
{
    int determined,inconsistency;
    int i,j,res;
    char a,b;
    while(scanf("%d%d",&n,&m) && n!=0 && m!=0)
    {
        getchar();
        determined=0;
        inconsistency=0;
        memset(graph,0,sizeof(graph));
        memset(indegree,0,sizeof(indegree));
        for(i=1;i<=m;i++)
        {
            scanf("%c<%c",&a,&b);
            getchar();
            if(!determined && !inconsistency)
            {
                if(graph[b-'A'][a-'A']==1)//存在反向边，则发现矛盾
                {
                    inconsistency=1;
                    printf("Inconsistency found after %d relations.\n",i);
                    continue;
                }
                if(graph[a-'A'][b-'A']==0)
                {
                    graph[a-'A'][b-'A']=1;
                    indegree[b-'A']++;
                }
                res=toposort(n);//toposort
                if(res==0)//序列能够被唯一确定
                {
                    printf("Sorted sequence determined after %d relations: ",i);
                    for(j=0;j<n;j++)
                        printf("%c",list[j]+'A');
                    printf(".\n");
                    determined=1;
                }
                else if(res==1)//不能拓扑排序，即有环，发现矛盾
                {
                    printf("Inconsistency found after %d relations.\n",i);
                    inconsistency=1;
                }
            }

        }
        if(!determined && !inconsistency)//既没有唯一确定，也没发现矛盾（有环），即不能确定
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
