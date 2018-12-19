#include<iostream>
using namespace std;

int main(){
	int n,m;
	long ab1,ab2;
	int index,hi,lo;
	cin>>n>>m;
	long *alist=new long[n]; //a
	long *blist=new long[n];//b
	long *list=new long[n];//a*b
	int *dotx=new int[m];//x
	int *doty=new int[m];//y
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d%d",&alist[i],&blist[i]);
		list[i]=alist[i]*blist[i];
	}
	for(int i=0;i<=m-1;i++)
	{
		scanf("%d%d",&dotx[i],&doty[i]);
	}
	//以上是准备阶段

	for(int i=0;i<=m-1;i++)//利用直线方程 bx+ay=ab 以及点的坐标进行判断
							//bx0+ay0>=ab的时候在直线的上方，反之在下方
	{
		index=n-1;
		hi=n-1,lo=0;
	while(1)//二分查找
	{
		ab1=alist[index]*doty[i]+blist[index]*dotx[i];	//计算好这一步比较需要的ab的值
		if (index<n && list[index]<=ab1 && (alist[index+1]*doty[i]+blist[index+1]*dotx[i])<list[index+1])
				{index+=1;break;} //判断是否在中间，即在这条直线上方与下一条直线下方
		else if (list[index]<=ab1 && index==n-1)//如果不是，判断是否在最上方
				{index+=1;break;}
		else if (list[index]>ab1 && index==0)//如果不是，判断是否在最下方
				break;
		else if(ab1<list[index])//如果不是，如果在上方，将区间上界缩小
			{hi=index;index=(index+lo)>>1;}
		else {lo=index;index=(hi+index)>>1;}//否则，将区间下界增大
	}
		printf("%d\n",index);
	}
	return 0;

}