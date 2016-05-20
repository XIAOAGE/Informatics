#include <stdio.h>
#include <math.h>

typedef struct str_fence
{
	int A_i;
	int B_i;
} fence;

#define MAX_N 50001
#define MAX_R 100010
#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) > (b) ? (b) : (a)
void insert(int index,int start,int end,int left,int right,int val);
int query(int index,int start,int end,int pos);
int cal_min(int i,int pos);
fence F[MAX_N],dp[MAX_N];
int tree[MAX_N*16];
int N,S;
int main()
{
	int i;
	scanf("%d%d",&N,&S);
	S += MAX_R;
	for(i = 1; i <= N; i++)
	{
		scanf("%d%d",&F[i].A_i,&F[i].B_i);
		F[i].A_i += MAX_R;
		F[i].B_i += MAX_R;
		dp[i].A_i = cal_min(query(1,0,MAX_R*2,F[i].A_i),F[i].A_i);
		dp[i].B_i = cal_min(query(1,0,MAX_R*2,F[i].B_i),F[i].B_i);
		insert(1,0,MAX_R*2,F[i].A_i,F[i].B_i,i);
	}
	printf("%d\n",min(S-F[N].A_i+dp[N].A_i,F[N].B_i-S+dp[N].B_i));
	return 0;
}

void insert(int index,int start,int end,int left,int right,int val)
{
	if(start == left && end == right)
	{
		tree[index] = val;
		return;
	}
	int mid = (start + end)/2;
	if(right <= mid)
		insert(index*2,start,mid,left,right,val);
	else if(left > mid)
		insert(index*2+1,mid+1,end,left,right,val);
	else
	{
		insert(index*2,start,mid,left,mid,val);
		insert(index*2+1,mid+1,end,mid+1,right,val);
	}
}

int query(int index,int start,int end,int pos)
{
	if(start == pos && end == pos)
		return tree[index];
	int val;
	int mid = (start + end) / 2;
	if(pos <= mid)
		val = query(index*2,start,mid,pos);
	else if(pos > mid)
		val = query(index*2+1,mid+1,end,pos);
	return max(val,tree[index]);
}

int cal_min(int i,int pos)
{
	if(!i)
		return abs(pos - MAX_R);
	else
		return min(F[i].B_i-pos+dp[i].B_i,pos-F[i].A_i+dp[i].A_i);
}
