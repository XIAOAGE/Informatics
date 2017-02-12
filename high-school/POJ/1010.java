import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
   while(in.hasNext())
   {
	int[] arr=new int[100];
	int n=0;
	while(true)
	{
		int a=in.nextInt();
		if(a==0)break;
		arr[n++]=a;
	}
	Arrays.sort(arr,0,n);
	while(true)
	{
	 int a=in.nextInt();
	 if(a==0)break;
	 int ser=0,num=0,max=0,a1=0,a2=0,a3=0,a4=0;			
	 boolean tie=false;
	 for(int i=0;i< n;i++)
	 {
	  if(arr[i]>a)break;
	  if(arr[i]==a)
	  {
		if(ser==0)
		{
			ser=1;num=1;max=i;a1=i;tie=false;
		}
		else if(ser==1&&num>1)
		{
			ser=1;num=1;max=i;a1=i;tie=false;
		}
	    }
	    for(int j=i;j< n;j++)
	    {
		if(arr[i]+arr[j]>a)break;
		if(arr[i]+arr[j]==a)
		{
			int ser1=1;
			if(i!=j)ser1++;
			if(ser1>ser)
			{
				ser=ser1;max=j;num=2;a1=i;a2=j;tie=false;
			}
			else if(ser1==ser)
			{
				if(num>2||(num==2&&arr[max]< arr[j]))
				{
					ser=ser1;max=j;num=2;a1=i;a2=j;tie=false;
				}
				else if(num==2&&arr[max]==arr[j])
					tie=true;
			}
		}
		for(int k=j;k< n;k++)
		{
			if(arr[i]+arr[j]+arr[k]>a)break;
			if(arr[i]+arr[j]+arr[k]==a)
			{
				int ser1=1;
				if(i!=j)ser1++;if(j!=k)ser1++;
				if(ser1>ser)
				{
					ser=ser1;max=k;num=3;a1=i;a2=j;a3=k;tie=false;
				}
				else if(ser1==ser)
				{
					if(num>3||(num==3&&arr[max]< arr[k]))
					{
						ser=ser1;max=k;num=3;a1=i;a2=j;a3=k;tie=false;
					}
					else if(num==3&&arr[max]==arr[k])tie=true;
				}
			}
			for(int w=k;w< n;w++)
			{
				if(arr[i]+arr[j]+arr[k]+arr[w]>a)break;
				if(arr[i]+arr[j]+arr[k]+arr[w]==a)
				{
					int ser1=1;
					if(i!=j)ser1++;if(j!=k)ser1++;if(k!=w)ser1++;
					if(ser1>ser)
					{
						ser=ser1;max=w;num=4;
						a1=i;a2=j;a3=k;a4=w;
						tie=false;
					}
					else if(ser1==ser&&num==4)
					{
					  if(arr[w]>arr[max])
					  {
						max=w;
						a1=i;a2=j;a3=k;a4=w;
						tie=false;
					  }
					  else if(arr[w]==arr[max])
						tie=true;
					}
				}	
			}
		}
	  }
	}
	if(num==0)System.out.println(a+" ---- none");
	else if(tie)System.out.println(a+" ("+ser+"):"+" tie");
	else {
		System.out.print(a+" ("+ser+"):");
		if(num==1)System.out.println(" "+arr[a1]);
		else if(num==2)System.out.println(" "+arr[a1]+" "+arr[a2]);
		else if(num==3)System.out.println(" "+arr[a1]+" "+arr[a2]+" "+arr[a3]);
		else if(num==4)System.out.println(" "+arr[a1]+" "+arr[a2]+" "+arr[a3]+" "+arr[a4]);
	}
    }
  }	
 }
}
