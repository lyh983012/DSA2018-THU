
#include<iostream>
#include<cmath>


using namespace std;
char star,ed,side;/*start��end��side �Ҹ�����������
						star��ʾ�ƶ�����㣬ed��ʾ�յ�
							side��ʾ�����õĵ���*/
int m,n;//mΪ��������

void move(char star,char ed)/*����������������һ����û�� 
							���������������ʱ�����Ĳ���
							���ڻ������*/

 {
	 cout<<star<<"-->"<<ed<<endl;//�������
	 m=m+1;//��������һ
}

int hanoi(int n, char star, char side, char ed)//�ݹ麯��

	/*��һ������n=1�ı�ݲ���*/
	{
		if (n==1 && side=='B' )//�ж��Ƿ����ʹ�û��������еķ���1
		   {	
			move(star,side);	
			move(side,ed);
			}	
		else if (n==1)   	//�ж��Ƿ����ʹ�û��������еķ���2
			move(star,ed);
	 /*��һ�����ǵ��ƹ�ϵʽ*/
		else if (side=='B')
			{
			hanoi(n-1,star,side,ed);//��n-1�����Ӵ������������Ƶ��յ���
			move(star,side);
			hanoi(n-1,ed,side,star);//��n-1�����Ӵ�������յ����Ƶ������
			move(side,ed);
			hanoi(n-1,star,side,ed);//��n-1�����Ӵ������������Ƶ��յ���
			}
		else 
			{   
			hanoi(n-1,star,ed,side);//��n-1�����Ӵ������������Ƶ�������
			move(star,ed);
			hanoi(n-1,side,star,ed);//��n-1�����Ӵ�����Ĺ������Ƶ��յ���
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