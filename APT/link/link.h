#include<iostream>
using namespace std;

class linkpoint //��ʵ��һ������Ļ�����Ԫ�����ڵ�
{
public:
int data;
linkpoint* next;
linkpoint* last;
linkpoint(int a){data=a;next=0;}
linkpoint(){data=0;next=0;}
};

class link  //��ʵ��һ���������еĳ�Աֻ�����˴洢���������������Ա
			//������˳ʱ��������г�Ա��API ��Ϊ�������Զ�����public
{
	private:
	linkpoint* last_appended;
	linkpoint* temp;
	linkpoint* next_appended;
	int len;
	public:
	void add(int data,int index);
	void print()
	{
		for(int i=0;i<=len-1;i++)
		{
			cout<<last_appended->data<<" ";
			if (len>1)
			{
			last_appended=last_appended->last;
			}
		}
	}
	link(){len=0;}
};

void link::add(int data,int index)	//�������������µĽڵ㣬
{
 if (len==0)	//��ʼ���Ľڵ㣬ֱ�Ӷ�̬����һ���ڵ����
 {
 last_appended=new linkpoint(data);
 len++;
 }
 else if (len==1) //�ڶ����ڵ�������Լ��ĸ�ָ����λ�ڵ��ָ�룬��֤������ǰ�̺ͺ��
 { 
 temp=new linkpoint(data);
 last_appended->next=temp;
 temp->next=last_appended;
 last_appended->last=temp;
 temp->last=last_appended;
 len++;
 last_appended=temp;//������һ�β������
 }
 else //�ж���ڵ����������ڲ��������ڵ�֮�䣬����new�Ľڵ�����ӣ���Ҫ����ǰһ���ڵ�ĺ�̣���һ���ڵ��ǰ��
 {
 temp=new linkpoint(data);
 index=(index-1) % len;
 for(int i=1;i<=index;i++)
 {last_appended=last_appended->next;}
 next_appended = last_appended->next; //Ѱ�Ҳ����λ��
 last_appended->next=temp;
 temp->next=next_appended;
 next_appended->last=temp;
 temp->last=last_appended;
 len++;
 last_appended=temp;//������һ�β������
 }}