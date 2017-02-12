import java.io.*;
import java.util.*;
class Point{
	
	private int firstVal;
	private int secondVal;
	
	public Point(int firstVal,int secondVal)
	{
		this.firstVal=firstVal;
		this.secondVal=secondVal;
	}
	
	public int getFirstVal() {
		return firstVal;
	}
	public void setFirstVal(int firstVal) {
		this.firstVal = firstVal;
	}
	public int getSecondVal() {
		return secondVal;
	}
	public void setSecondVal(int secondVal) {
		this.secondVal = secondVal;
	}
}
public class Main {

	//代表读入的pair
	private ArrayList<Point> pair=null;
	//代表结果图
	private ArrayList<Point> vMap=null;
	//代表图的宽度
	private int iWidth;
	//代表读入的值
	private int iParam;
	//代表读入的数量
	private int iCount;
	//代表总数目
	private int iNum;
	//代表当前位置
	private int iPos;
	
	public Main()
	{
		this.pair=new ArrayList<Point>();
		this.vMap=new ArrayList<Point>();
		init();
	}
	//进行初始化
	public void init()
	{
		this.pair.clear();
		this.vMap.clear();
		this.iPos=1;
		this.iCount=0;
		this.iParam=0;
		this.iWidth=0;
		this.iNum=0;
	}
	
	public void acm1009()
	{
		Scanner scan=new Scanner(System.in);
		iNum=0;
		while(true){
			
			iWidth=scan.nextInt();
			if(iWidth==0)
			{
				break;
			}
			iParam=scan.nextInt();
			iCount=scan.nextInt();
			while(iParam!=0||iCount!=0)
			{
				this.pair.add(new Point(iParam,iCount));
				iNum+=iCount;
				iParam=scan.nextInt();
				iCount=scan.nextInt();
			}
			calPixel();
			
			
			//对于vMap按照iPos从小到大进行排序
			sort();
			//输出结果
			System.out.println(iWidth);
			int iCur=0;
			
			int i;
			
			for(i=0;i<this.vMap.size();i++)
			{
				if(this.vMap.get(i).getSecondVal()==this.vMap.get(iCur).getSecondVal())
				{
					continue;
				}
				System.out.println(this.vMap.get(iCur).getSecondVal()+" "+(this.vMap.get(i).getFirstVal()-this.vMap.get(iCur).getFirstVal()));
				
				iCur=i;
			}
			System.out.println(this.vMap.get(iCur).getSecondVal()+" "+(iNum-this.vMap.get(iCur).getFirstVal()+1));
			System.out.println(iParam+" "+iCount);
			//清空，并重新开始进行计算
			init();
		}
		System.out.println(iWidth);
	}
	//冒泡排序
	public void sort()
	{
		for(int i=0;i<this.vMap.size()-1;i++)
		{
			for(int j=0;j<this.vMap.size()-i-1;j++)
			{
				if(this.vMap.get(j).getFirstVal()>this.vMap.get(j+1).getFirstVal())
				{
					int temp=this.vMap.get(j).getFirstVal();
					int temp1=this.vMap.get(j).getSecondVal();
					
					this.vMap.get(j).setFirstVal(this.vMap.get(j+1).getFirstVal());
					this.vMap.get(j).setSecondVal(this.vMap.get(j+1).getSecondVal());
					this.vMap.get(j+1).setFirstVal(temp);
					this.vMap.get(j+1).setSecondVal(temp1);
				}
			}
		}
	}
	//计算像素
	public void calPixel()
	{
		//初始时，位置为1
		iPos=1;
		
		//遍历pair，当有一个新的pair时，就证明有值改变了
		//我们只计算改变的值影响的周围的节点
		//还需要判断终点，终点即iPos到了最后一个位置时，这时循环i=this.pair.size(),且iPos不用增加
		for(int i=0;i<=this.pair.size();i++)
		{
			//计算出iPos位置所对应的节点所处的行和列
			//行和列均从0开始
			int row=(iPos-1)/iWidth;
			int col=(iPos-1)%iWidth;
			
			// 此处处理1号点问题
			if (col == iWidth - 1)
			{
				if ((row + 2)*iWidth < iNum)
				{
					Point tmpPix=new Point(iPos + iWidth+1, calNode(iPos + iWidth + 1, row + 2, 0));
					vMap.add(tmpPix);
				}
			}

			
			//计算被改变的节点所影响的节点 
			for(int m=row-1;m<=row+1;m++)
			{
				for(int n=col-1;n<=col+1;n++)
				{
					int myPos=m*iWidth+n+1;
					
					if(m>=0&&n>=0&&n<iWidth&&myPos<=iNum)
					{
						Point myPoint=new Point(myPos,calNode(myPos,m,n));
						this.vMap.add(myPoint);
					}
				}
			}
			
			if(i!=this.pair.size())
			{
				iPos+=this.pair.get(i).getSecondVal();
			}
		}
	}
	//计算节点中所应该填的值的方法，形式参数为iPos、row、col
	//计算节点
	//此方法也是准确无误的
	public int calNode(int iPos,int row,int col)
	{
		//初始化参数值为0
		int result=0;
		
		//扫描iPos节点的八个方向
		for(int i=row-1;i<=row+1;i++)
		{
			for(int j=col-1;j<=col+1;j++)
			{
				int temp=iWidth*i+j+1;
				if(temp==iPos)
				{
					continue;
				}
				if(i>=0&&j>=0&&j<iWidth&&temp<=iNum)
				{
					if(Math.abs(getValue(temp)-getValue(iPos))>result)
					{
						result=Math.abs(getValue(temp)-getValue(iPos));
					}
				}
			}
		}
		
		return result;
	}//calNode
	
	//获得值
	//举个例子，比如图为1 1 1，那么取iPos=3点的值
	//开始时iN=0,i=0,iN+=3;后iN变为了3，i++,i变为了1，这时iN<3不符合条件，退出循环
	//返回值为this.pair.get(0).getFirstVal()返回的值为1
	//证明此取值的方法准确无误！
	public int getValue(int iPos)
	{
		int i=0;
		int iN=0;
		for(i=0;iN<iPos;i++)
		{
			iN+=this.pair.get(i).getSecondVal();
		}
		return this.pair.get(i-1).getFirstVal();
	}
	public static void main(String[] args) throws Exception
	{
		Main mainf=new Main();
		mainf.acm1009();
	}
}
