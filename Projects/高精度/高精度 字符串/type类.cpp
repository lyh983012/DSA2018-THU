#include "stdafx.h"
#include"type.h"
#include<iostream>
using namespace std;
int Type::add (int a1[10000],int a2[10000],int l1,int l2)
{
int lc;
int c[10001]={0};
if (l1>l2)
lc=l1-1;
else lc=l2-1;
for (int i=0;i<=lc;i++)
{
	c[i]+=(a1[i]+a2[i]);
	c[i+1]+=c[i]/10;
	c[i]=c[i]%10;
}

cout<<"the sum is :";
if (c[lc+1]==0)
		{
			for (int i=lc;i>=0;--i)
		{
			cout<<c[i];
			}}
else
	{
		for (int i=lc+1;i>=0;--i)
		{
	cout<<c[i];
		}}
return 1;
	}
int Type::div(int a1[10000],int a2[10000],int l1,int l2)
{
	int com[10000];
	for (int i=l1-1;i>=l2-1;i--)
	{   
		if(a1[i]>0)
		{   
			while (compare(a1,a2,l1,l2,i))
			{
				for (int j=0;j<=l2-1;j++)
				{
				a1[i+j-l2+1]=(a1[i+j-l2+1]-a2[j]+10);
				if (a1[i-j]<10)
				a1[i+j-l2+2]-=1;
				else
				a1[i+j-l2+1]-=10;
				com[l1-1-i]+=1;
				}
			}
			for (int j=0;j<=l2-1;j++)
				{
				a1[i+j-l2]=(a1[i+j-l2]-a2[j]+10);
				if (a1[i+j-l2]<10)
				a1[i+j-l2+1]-=1;
				else
				a1[i+j-l2]-=10;
				com[l1-i]+=1;
				}
		}
	}
	for(int i=0; i<=l1-l2;i++)
	{
	cout<<com[i];
	}

return 1;}
int Type::mov(int a1[10000],int a2[10000],int l1,int l2)

{
int c[10001]={0};
int lc;
if (l1>l2)
lc=l1-1;
else lc=l2-1;
for (int i=0;i<=lc;i++)
{
	c[i]+=(a1[i]-a2[i]+10);
	if (c[i]<10)
	c[i+1]-=1;
	else
	c[i]-=10;
}

cout<<"the result is :";
for (int i=lc;i>=0;--i)
{
	cout<<c[i];

}
return 1;
	}
int Type::time (int a1[10000],int a2[10000],int l1,int l2)
{
int lc=l1+l2;
for(int i=0;i<=lc;i++)
{c[i]=0;}
for(int i=0;i<=l1-1;i++)
	{for (int j=0;j<=l2-1;j++)
		{c[i+j]+=a2[j]*a1[i];
		 if (c[j+i]>=10)
		 {c[j+i+1]+=c[j+i]/10;
		  c[j+i]=c[j+i]%10;
		 }}}
cout<<"the result is :";
if(c[lc]==0){lc=lc-1;if(c[lc]==0){lc=lc-1;}}
for (int i=lc;i>=0;--i)
{
	cout<<c[i];
}
return 1;	
	}