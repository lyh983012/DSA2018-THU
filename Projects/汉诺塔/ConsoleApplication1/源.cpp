
#include<iostream>
#include<cmath>


using namespace std;
char star,ed,side;/*start，end，side 我给柱子起名字
						star表示移动的起点，ed表示终点
							side表示过渡用的到的*/
int m,n;//m为步数计数

void move(char star,char ed)/*基础操作函数，当一个盘没有 
							其他盘子在上面的时候做的操作
							用于基础输出*/

 {
	 cout<<star<<"-->"<<ed<<endl;//输出操作
	 m=m+1;//计数器加一
}

int hanoi(int n, char star, char side, char ed)//递归函数

	/*这一部分是n=1的便捷操作*/
	{
		if (n==1 && side=='B' )//判断是否可以使用基础操作中的方案1
		   {	
			move(star,side);	
			move(side,ed);
			}	
		else if (n==1)   	//判断是否可以使用基础操作中的方案2
			move(star,ed);
	 /*这一部分是递推关系式*/
		else if (side=='B')
			{
			hanoi(n-1,star,side,ed);//把n-1个盘子从输入的起点柱移到终点柱
			move(star,side);
			hanoi(n-1,ed,side,star);//把n-1个盘子从输入的终点柱移到起点柱
			move(side,ed);
			hanoi(n-1,star,side,ed);//把n-1个盘子从输入的起点柱移到终点柱
			}
		else 
			{   
			hanoi(n-1,star,ed,side);//把n-1个盘子从输入的起点柱移到过渡柱
			move(star,ed);
			hanoi(n-1,side,star,ed);//把n-1个盘子从输入的过渡柱移到终点柱
			}

		return 0;
		}
void main()
{
	m=0;
	do{
	cin>>n;
	hanoi(n,'A','B','C');
	cout<<m<<endl;
	}
	while(1);
}