#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>




//y=Random(mapsize/2-2)+1;
//x=Random(mapsize-2)+1;

using namespace std;

//简单链表结构的c++实现,以及point类简单定义

class point
{

public:
	int x,y;
	point(int _x,int _y)
	{x=_x;y=_y;}
};

template<class T>
class linkpoint
{
public:
T data;
linkpoint* next;
int check;
linkpoint(int a,int b):data(a,b){}
};

template<class T>
class link
{
	public:
linkpoint<T>* temp;
linkpoint<T>* head;
linkpoint<T>* end;
int len;
	void add(int x,int y);
	void del_end()
	{
	temp=end->next;
	delete end;
	end=temp;
	len--;
	}
	void del(linkpoint<T>* de)
	{
	ed=ed->next
	delete ed;
	len--;
	}
	link()
	{
	len=0;
	}
};

template<class T>
void link<T>::add(int x,int y)
{
 temp=new linkpoint<T>(x,y);
 if (len==0)
 {
 head=temp;
 end=temp;
 len++;
 }
 else 
 {
 if (len==1)
 { end->next=temp; }
 head->next=temp;//head的指针指向下上一个点，然后把下个点命名为head，原来的head点只能用指针找到
 head=temp;
 len++;
 }
}