#include <bits/stdc++.h>

#define p 1000007
using namespace std;
const char b[27]={'0','A','B','C','D','E','F','G',
				  'H','I','J','K','L','M','N','O',
				  'P','Q','R','S','T','U','V','W',
				  'X','Y','Z'};                     //这个只是针对这道题的。。。可以无视

//##################main part########################
string ss;
long long n,aim;
stack <char> ope;   //在把中缀转换成后缀时的存储符号的stack

long long strnum(string s) //字符串转成long long
{
	long long num;
	stringstream ss(s);
	ss>>num;
	return num;
}

int pre(char a)//定义优先级
{
	if(a=='=' || a=='(')return 0;
	if(a=='+'||a=='-')return 1;
	if(a=='*')return 2;
	if(a=='^')return 3;
}
long long  sta[555555],top;//手打栈
long long work(string s)//计算后缀
{
	ss="";//注意，要把ss清空。 防止没有操作符，只有一个数字的s。
	memset(sta,0,sizeof(sta));top=0;//注意要把栈清空
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			ss+=s[i];
		else
		{
			if(s[i]==' ')
			{
				top++;
				sta[top]=strnum(ss)%p; //但要注意，最好不要在下面mod，因为那样很容易错，所以干脆就在一开始就mod
				ss="";
			}
			else
			{
				if(s[i]=='-')
				{
					long long s1,s2;
					s2=sta[top];
                    top--;
                    s1=sta[top];
                    s1=s1-s2;
                    sta[top]=s1;
				}
				if(s[i]=='+')
				{
					long long s1,s2;
					s2=sta[top];
					top--;
					s1=sta[top];
					s1=s1+s2;
					sta[top]=s1;
				}
				if(s[i]=='*')
				{
					long long s1,s2;
					s1=sta[top];if(top>0) top--;
					s2=sta[top];
					s1=s1*s2;
					sta[top]=s1;
				}
				if(s[i]=='^')
				{
					long long s1,s2;
					s1=sta[top];if(top>0) top--;
					s2=sta[top];
					long long z=1LL;
					for(int i=1;i<=s1;i++)
						z=z*s2;
					sta[top]=z;
				}
			}
		}
	}
	if(top==0)return strnum(ss);
	else return sta[top];
}

string change(string str)//中缀转后缀
{
	while(!ope.empty())	ope.pop();
	string s;
	ope.push('='); //防止读入符号时，ope是空的
	int len = str.length();
	for(int i = 0 ; i < len; ++i)
	{
		if(str[i] >= '0' && str[i] <= '9')	s+=str[i];	//处理数字
		else
		{
			if(i-1>=0 && str[i-1] >= '0' && str[i-1] <= '9')s+=' ';	//区别后缀表达式中的两个连续的数字，中间加个空格
			if(str[i] == '(')
					ope.push(str[i]);
			else if(str[i] == ')')
			{
				while (ope.top() != '(')
					{
						s+=ope.top();
						ope.pop();
					}
					ope.pop();
			}
			else if(pre(str[i]) > pre(ope.top())) 	ope.push(str[i]); //优先级比ope顶端的大，入stack
			else
			{
				while(pre(str[i]) <= pre(ope.top()))                  //优先级比当前符号高的出stack
				{
						s+=ope.top();
						ope.pop();
				}
				ope.push(str[i]);
			}
		}
	}
	while(!ope.empty())
	{
		if(s[s.size()-1]>= '0' && s[s.size()-1]<= '9')s+=' ';
		s+=ope.top();
		ope.pop();
	}
	return s;
}

//#######################################################

int main()
{
	string sss;
	getline(cin,sss);
	for(int i=0;i<sss.size();i++)
		if(sss[i]!=' ')ss+=sss[i]; //去除多余的空格，这题里有多余的空格。。。
	cin>>n;getchar();
	for(int i=0;i<ss.size();i++)
		if(ss[i]=='a')ss[i]='3';    //这题是带有未知数a的表达式，用质数3带进去，方便又不影响结果。
	long long aim=work(change(ss));
	for(int i=1;i<=n;i++)
	{
		string s,s2;
		getline(cin,s2);
		for(int j=0;j<s2.size();j++)
			if(s2[j]!=' ')s+=s2[j]; //去除多余的空格，这题里有多余的空格。。。
		for(int j=0;j<s.size();j++)
			if(s[j]=='a')s[j]='3';  //这题是带有未知数a的表达式，用质数3带进去，方便又不影响结果。
		long long z=work(change(s));
		if(aim==z)cout<<b[i];
	}
	cout<<endl;
	return 0;
}
