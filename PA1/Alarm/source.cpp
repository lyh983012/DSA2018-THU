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
	while((hi-lo)!=1)
	{
		ab1=alist[index]*doty[i]+blist[index]*dotx[i];	//计算好这一步比较需要的ab的值
		if (index<n && ab1<list[index])
			{hi=index;index=(index+lo)>>1;}
		else if(index<n && ab1>=list[index])
			{lo=index;index=(hi+index)>>1;}
		else if (list[index]<=ab1 && index==n-1)//如果不是，判断是否在最上方
				{index=n;break;}
		else if (list[index]>ab1 && index==0)//如果不是，判断是否在最下方
				{index=0;break;}

	}
	if(!(index==n || index==0))
		index++;
		printf("%d\n",index);
	}
	return 0;

}