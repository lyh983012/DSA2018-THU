#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include"windows.h"
#define size 10000

using namespace std;


class Type
{
public:
void add (int xs1,int xs2);//����Ĭ�ϲ���������������ʵ��xa1+ya2 x��y�ǵ;��ȣ�����y=0��ʵ�ֵ;���*�߾���
void add ();//���صļӷ���ֱ��ʵ��A=1,B=1�������ڴ����a1��a2���ӷ�
int div ();//�����ڴ����a1��a2������
int mov ();//�����ڴ����a1��a2������
int time ();//�����ڴ����a1��a2���˷�
int fab (int n,int a,int b,int xs1,int xs2);//�����ڴ����a1��a2�����Ե���
void outputc();//����������
void input(); //����A1,A2�ַ������飬�ҽ�����ĵ��ַ���ת��Ϊ��l1/l2,���±�0~l1-1/0~l2-1��������
Type(int l1_,int l2_,int lc_){l1=l1_;l2=l2_;lc=lc_;cout<<"Type`s construction completed"<<endl;}//����
~Type(){cout<<"calculation space released"<<endl; Sleep(2000);}//����
private:
int getlen(const int* n);//��ȡ�������鳤�� 
void clear();
int compare(int* a1,int* a2,int s,int l2);//�Ƚ����鴢���a1��a2���ֵĴ�С��sΪ����Ƚϵ����λ,l2Ϊ�Ƚϵĳ���
int lc;
int c[size];
char b1[size],b2[size];
int a1[size],a2[size];
int l1,l2;
};



void Type::add (int xs1,int xs2)
{
for(int i=0;i<=size+1;i++)
{c[i]=0;}
l1=getlen(a1);
l2=getlen(a2);
if (l1>l2)
lc=l1;
else lc=l2;
for (int i=0;i<=lc-1;i++)
{
	c[i]+=(a1[i]*xs1+a2[i]*xs2);
	c[i+1]+=c[i]/10;
	c[i]=c[i]%10;
}}
void Type::add ()
{
for(int i=0;i<=size+1;i++)
{c[i]=0;}
l1=getlen(a1);
l2=getlen(a2);
if (l1>l2)
lc=l1;
else lc=l2;
for (int i=0;i<=lc-1;i++)
{
	c[i]+=(a1[i]+a2[i]);
	c[i+1]+=c[i]/10;
	c[i]=c[i]%10;
}
}
int Type::div()
{
for(int i=0;i<=size+1;i++)
{c[i]=0;}

	for (int i=l1-1;i>=l2-1;i--)
	{   
		while (compare(a1,a2,i,l2)!=2)
				{for (int j=0;j<=l2-1;j++)
				{
				if (a1[i-l2+1+j]>=a2[j])
					a1[i-l2+1+j]=a1[i-l2+1+j]-a2[j];
				else
				{
				a1[i-l2+1+j]=10+a1[i-l2+1+j]-a2[j];
				a1[i-l2+2+j]-=1;
				}}
				c[l1-1-i]+=1; }
		while(a1[i]>0 && i!=(l2-1))
				{
				for (int j=0;j<=l2-1;j++)
				{
				if (a1[i-l2+j]>=a2[j])
					a1[i-l2+j]=a1[i-l2+j]-a2[j];
				else
				{
				a1[i-l2+j]=10+a1[i-l2+j]-a2[j];
				a1[i-l2+1+j]-=1;
				}}
				c[l1-i]+=1;}}
	for (int i=0;i<=l1-l2;i++)
		{if (c[i]!=0){lc=i;break;}}
	 cout<<"���� ��";
	for(int i=lc; i<=l1-l2;i++)
		{cout<<c[i];}
	 cout<<endl<<"������:";
	 for (int i=l1-l2;i>=0;i--)
	 {cout<<a1[i];}
	 lc=l1-l2-lc+1;
	return 1;
}
int Type::mov()

{
for(int i=0;i<=size+1;i++)
{c[i]=0;}
l1=getlen(a1);
l2=getlen(a2);
if (l1>l2)
lc=l1-1;
else lc=l2-1;

if (l1>l2||compare(a1,a2,l1-1,l2)==1)
{
	for (int i=0;i<=lc;i++)
	{
		c[i]+=(a1[i]-a2[i]+10);
		if (c[i]<10)
		c[i+1]-=1;
		else
		c[i]-=10;
	}

}
else if(l1<l2||compare(a1,a2,l1-1,l2)==2)
{
for (int i=0;i<=lc;i++)
{
	c[i]+=(a2[i]-a1[i]+10);
	if (c[i]<10)
	c[i+1]-=1;
	else
	c[i]-=10;
}
return 1;
}
else 
	{for (int i=0;i<=size+1;i++)
		c[i]=0;
	}
return 0;

	}
int Type::time ()
{
for(int i=0;i<=size+1;i++)
{c[i]=0;}
l1=getlen(a1);
l2=getlen(a2);
lc=l1+l2;
for(int i=0;i<=l1-1;i++)
	{for (int j=0;j<=l2-1;j++)
		{c[i+j]+=a2[j]*a1[i];
		 if (c[j+i]>=10)
		 {c[j+i+1]+=c[j+i]/10;
		  c[j+i]=c[j+i]%10;
		 }}}
return 1;	
	}
int Type::fab (int n,int a,int b,int xs1,int xs2)
{
	int a1[size]={0},a2[size]={0};
	a1[0]=a;
	a2[0]=b;
	lc=10;
	for (int j=1;j<=n;j++)
	{
		add(xs1,xs2);//A1+A2
		lc=getlen(c);
        for(int i=lc+1;i>=0;i--)
		{a1[i]=a2[i];a2[i]=c[i];}
		lc=getlen(c);
	}
return 1;	
}
void Type::input() //������ĵ��ַ���ת��Ϊ��l1/l2,���±�0~l1-1/0~l2-1��������
{
for(int i=size;i>=0;i--)
	a1[i]=0;
for(int i=size;i>=0;i--)
	a2[i]=0;
cin>>b1>>b2;
l1=strlen(b1);
l2=strlen(b2);
for
(int i=0;i<=l1-1;i++)
{a1[i]=b1[l1-1-i]-'0';}//a�ĵ�iλ��b�ĵ�l1-1-iλ��a�ĵ�iλ����ʵ�ʵĵ�i+1λ,in total is l1-1 wei;
for(int i=0;i<=l2-1;i++)
{a2[i]=b2[l2-1-i]-'0';}
};
void Type::outputc()
{
  int l=getlen(c);
  for (int i=l;i>=0;i--)
		{printf("%d",c[i]);}
};
int Type::compare(int* a1,int* a2,int s,int l2)
{
	int n;
	for (int i=l2-1;i>=0;i--)
	{if (*a1+s-l2+i+1>*a2+i)
	{
	  n=1;
	  break;
	}
	else if (*a1+s-l2+1+i<*a2+i)
	{n=2;
	 break;}
	n=0 ;
	}
	return n;
	}
int Type::getlen(const int* n)
	{
		for (int i=size;i>=0;i--)
	{
		if (*(n+i)!=0) {return i;break;}
	}
}	 
void Type::clear()
{
	for(int i=0;i<=size;i++)
	{a1[i]=0;a2[i]=0;c[i]=0;}
}
				