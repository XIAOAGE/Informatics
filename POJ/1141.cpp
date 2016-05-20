#include<iostream>
#include<string>
#include<fstream>
using namespace std;
string s;
int d[101][101], value[101][101], length;
void fun()
{
    for (int p = 0; p < length; p++)d[p][p] = 1;
    for (int tem = 1; tem < length; tem++)
        for (int i = 0; i < length - tem; i++)
        {
            int j = tem + i;
            d[i][j] = 99999;
            if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))//1@
            {
                d[i][j] = d[i + 1][j - 1];
                value[i][j] = -1;
            }
            for (int k = i; k < j; k++)//此处需要注意，即便1@处成立，也不能省略
                if (d[i][j] > d[i][k] + d[k + 1][j])
                {
                    d[i][j] = d[i][k] + d[k + 1][j];
                    value[i][j] = k;
                }
        }
        return;
}
void print(int i, int j)
{
    if (i > j)return;
    else if (i == j)
    {
        if (s[i] == '(' || s[i] == ')') printf("()");
        if (s[i] == '[' || s[i] == ']')printf("[]");
    }else if (value[i][j] == -1)
    {
        printf("%c", s[i]);
        print(i + 1, j - 1);
        printf("%c", s[j]);
    }else {
        print(i, value[i][j]);
        print(value[i][j] + 1, j);
    }
    return;
}
int main()
{
    while (getline(cin, s))
    {
        memset(d, 0, sizeof(d));
        length = (int)s.length();
        fun();
        print(0, length - 1);
        printf("\n");
    }
    return 0;
}
