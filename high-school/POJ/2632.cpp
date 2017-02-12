//Memory Time 
//348K   16MS 

#include<iostream>
using namespace std;

int main(void)
{
	int cases;
	int a,b;  //A列数B行数
	int n,m;  //n : robot数, m :  指令数
	int x,y;  //robots坐标
	char dire;  //robots方向
	int rob[101],rep[101];   //rob:编号,rep:指令重复次数
	char act[101];           //act:行动指令

	bool flag=false;
	int i,k;

	int post[101][101];      //记录robot初始方向
	int num[101][101];       //记录robot的编号
	int xx[101],yy[101];     //记录robot的编号

	cin>>cases;
	while(cases--)
	{
		memset(post,-1,sizeof(post));
		memset(num,0,sizeof(num));
		memset(xx,0,sizeof(xx));
		memset(yy,0,sizeof(yy));

		cin>>a>>b;
		cin>>n>>m;

		/*Input the postion and direction of each robot*/
		for(i=1;i<=n;i++)
		{
			cin>>y>>x>>dire;   //使用cin函数时，空字符不会作为字符输入到char
			xx[i]=x;
			yy[i]=y;                  //编号记录（编号作为下标，通过编号反搜坐标）
			num[x][y]=i;              //编号记录（坐标作为下标，通过坐标反搜编号）
			if(dire=='S')             //方向记录（坐标作为下标，通过坐标反搜方向）
			    post[x][y]=0;        //0 or 360     【由于坐标系改变，注意上下颠倒，即N为南，S为北，但WE不变】
			else if(dire=='E')
				post[x][y]=1;        //90
			else if(dire=='N')
				post[x][y]=2;        //180
			else if(dire=='W')
				post[x][y]=3;        //270
		}                            //用0~3代替是为了减少运算次数

		/*Input < robot #> < action> < repeat>*/
		for(k=1;k<=m;k++)
			cin>>rob[k]>>act[k]>>rep[k];

		bool flag=false;
		int row,col;
		for(k=1;k<=m;k++)
		{
			row=xx[rob[k]];
			col=yy[rob[k]];

			if(act[k]=='L')       //【由于坐标系改变，注意转向相反：L转右，R转左】
			{
				rep[k]%=4;   //角度每转4次（360度）回到原位
				post[row][col] = ( post[row][col] + rep[k] ) % 4;
			}
			else if(act[k]=='R')
			{
				rep[k]%=4;
				post[row][col] = ( post[row][col] - rep[k] ) % 4;
				if(post[row][col]<0)   //注意余数为负的情况
					post[row][col]+=4;
			}
			else if(act[k]=='F')
			{
				if(post[row][col]==0)      //N方向移动判断
					for(i=1;i<=rep[k];i++)
					{
						if(num[row-i][col]) //如果该格存在编号（即存在另外的robot）
						{
							cout<<"Robot "<<num[row][col]<<" crashes into robot "<<num[row-i][col]<<endl;
							flag=true;
							break;
						}
						if(row-i<1)  //判断是否撞墙
						{
							cout<<"Robot "<<num[row][col]<<" crashes into the wall"<<endl;
							flag=true;
							break;
						}
						if(i==rep[k])
						{   //移动中若无任何碰撞，则把robot原坐标记录的信息更新到新坐标
							post[row][col]=-1;   //原坐标方向重置
							num[row][col]=0;      //原坐标编号重置
							row-=rep[k];
							xx[rob[k]]-=rep[k];
							post[row][col]=0;    //新坐标方向更新
							num[row][col]=rob[k];   //新坐标编号更新
						}
					}
				else if(post[row][col]==1)  //E方向移动判断
					for(i=1;i<=rep[k];i++)
					{
						if(num[row][col+i])
						{
							cout<<"Robot "<<num[row][col]<<" crashes into robot "<<num[row][col+i]<<endl;
							flag=true;
							break;
						}
						if(col+i>a)
						{
							cout<<"Robot "<<num[row][col]<<" crashes into the wall"<<endl;
							flag=true;
							break;
						}
						if(i==rep[k])
						{
							post[row][col]=-1;
							num[row][col]=0;
							col+=rep[k];
							yy[rob[k]]+=rep[k];
							post[row][col]=1;
							num[row][col]=rob[k];
						}
					}
				else if(post[row][col]==2)  //S方向移动判断
					for(i=1;i<=rep[k];i++)
					{
						if(num[row+i][col])
						{
							cout<<"Robot "<<num[row][col]<<" crashes into robot "<<num[row+i][col]<<endl;
							flag=true;
							break;
						}
						if(row+i>b)
						{
							cout<<"Robot "<<num[row][col]<<" crashes into the wall"<<endl;
							flag=true;
							break;
						}
						if(i==rep[k])
						{
							post[row][col]=-1;
							num[row][col]=0;
							row+=rep[k];
							xx[rob[k]]+=rep[k];
							post[row][col]=2;
							num[row][col]=rob[k];
						}
					}
				else if(post[row][col]==3)  //W方向移动判断
					for(i=1;i<=rep[k];i++)
					{
						if(num[row][col-i])
						{
							cout<<"Robot "<<num[row][col]<<" crashes into robot "<<num[row][col-i]<<endl;
							flag=true;
							break;
						}
						if(col-i<1)
						{
							cout<<"Robot "<<num[row][col]<<" crashes into the wall"<<endl;
							flag=true;
							break;
						}
						if(i==rep[k])
						{
							post[row][col]=-1;
							num[row][col]=0;
							col-=rep[k];
							yy[rob[k]]-=rep[k];
							post[row][col]=3;
							num[row][col]=rob[k];
						}
					}
			}
			if(flag)break;
		}
		if(!flag)
			cout<<"OK"<<endl;
	}
	return 0;
}
