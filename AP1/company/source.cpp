#include<iostream>
using namespace std;

int main(){
int n,m,a,temp; 
long answer; //最终的输出答案
int online=0;//记录实时在线人数
char state='0';	//输入的状态

answer=0;
cin>>n>>m;
int *code=new int[n];	//申请对应的状态数组，并存储自己的code
for (int i=0;i<=n-1;i++)
	code[i]=-1;
int *list=new int[n];	//存储一下在线的员工名单
for (int i=0;i<=n-1;i++)
	list[i]=0;

for (int j=0;j<=m-1;j++)//主循环
{
cin>>state;
switch(int(state)){
	case 73: //I
		scanf("%d",&a);
		if (code[a-1]==-1)
		{
			online+=1;
			list[online-1]=a-1;	//用在线人数对应第n个上线的人的位置
		}
		scanf("%d",&code[a-1]);
		break;
	case 79: //O
		scanf("%d",&a);
		if (code[a-1]!=-1)
		{
			for(int i=0;i<=online-1;i++)
			{
				if(list[i]==a)
				{temp=i;break;}			//下线的时候把对应的人后面的都往前移，把这个人覆盖掉
			}
			for(int i=temp;i<=online-1;i++)
			{
			list[i]=list[i+1];
			}
			online-=1;
			code[a-1]=-1;
		}
		break;
	case 67: //C

		if (online!=0)
		for(int i=0;i<=online-1;i++)
		{
			code[list[i]]=-1;	//清理在线名单里的人就好了
		}
		online=0;
		break;
	case 78: //N
		answer+=online;
		break;
	case 81: //Q
		scanf("%d",&a);
		answer+=code[a-1];
		break;
		}}
cout<<answer;
delete code;
//system("pause");
return 0;
	
}

