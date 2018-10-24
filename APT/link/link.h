#include<iostream>
using namespace std;

class linkpoint //简单实现一个链表的基本单元——节点
{
public:
int data;
linkpoint* next;
linkpoint* last;
linkpoint(int a){data=a;next=0;}
linkpoint(){data=0;next=0;}
};

class link  //简单实现一个链表，其中的成员只保留了存储最近操作的三个成员
			//集成了顺时针输出所有成员的API 因为懒惰所以都给了public
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

void link::add(int data,int index)	//分三种情况添加新的节点，
{
 if (len==0)	//初始化的节点，直接动态申请一个节点对象，
 {
 last_appended=new linkpoint(data);
 len++;
 }
 else if (len==1) //第二个节点的申请以及四个指向临位节点的指针，保证都具有前继和后继
 { 
 temp=new linkpoint(data);
 last_appended->next=temp;
 temp->next=last_appended;
 last_appended->last=temp;
 temp->last=last_appended;
 len++;
 last_appended=temp;//方便下一次插入操作
 }
 else //有多个节点的情况，属于插入两个节点之间，除了new的节点的连接，还要更新前一个节点的后继，后一个节点的前继
 {
 temp=new linkpoint(data);
 index=(index-1) % len;
 for(int i=1;i<=index;i++)
 {last_appended=last_appended->next;}
 next_appended = last_appended->next; //寻找插入的位置
 last_appended->next=temp;
 temp->next=next_appended;
 next_appended->last=temp;
 temp->last=last_appended;
 len++;
 last_appended=temp;//方便下一次插入操作
 }}