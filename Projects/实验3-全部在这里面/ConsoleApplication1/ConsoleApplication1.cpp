// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>

using namespace std;
int transtemp(double n)
{
	return(n-32)*5/9;
}

int maxl(int a,int b)
{if (a>b) return a; else return b;}
double maxl(double a,double b)
{if (a>b) return a; else return b;}
int maxl(int a,int b,int c)
{
	int n;
	if (a>b)
		n=a; else n=b;
	if (c>n)
		n=c;
	return c;
}
double maxl(double a,double b,double c)
{
	double n;
	if (a>b)
		n=a; else n=b;
	if (c>n)
		n=c;
	return c;
}
long long fab1(int m)
{
	long long n(1),f1(1),f2(1);
	m=m-1;
	if (m==0 || m==1)
		return 1;
	else 
		for(int i=1;i<=m;i++)
		  {n=f1+f2;

           f2=f1;
		              f1=n;
	} 
	return n;
}

		

void main()
{
double n;
double a,b,c;
int ai,bi,ci,m;
while(1)
{
cout<<"你要执行第几个实验？";
cin>>m;
switch(m)
{
case 1:
cin>>n;
cout<<transtemp(n)<<endl;
break;
case 2:
cin>>a>>b>>c;
cout<<maxl(a,b)<<endl;
cout<<maxl(a,b,c)<<endl;
cin>>ai>>bi>>ci;
cout<<maxl(ai,bi)<<endl;
cout<<maxl(ai,bi,ci)<<endl;
break;
case 3:
cin>>a>>b;
cout<<pow(a,b);
break;
case 4:
cin>>ai;
cout<<fab1(ai);
break;
default: 
cout<<"ileaglly input";
}}
}
