// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<windows.h>
#include <iostream>

using namespace std;
int a[36];

int main()
{
	a[0]=262;
	for(int i=1;i<=35;i++)
	{
		(int) a[i]=a[i-1]*1.0594630944;		
	}
	int n=1,m=60;
	while(1)
	{
	for (int i=1;i<=36;i++)
		{if (i==n) 
		{cout<<"*";
	    Beep(a[i],500+10*i);}
		else 
		cout<<ends;
		}
	cout<<endl;
	if (rand()%2==1)
	n=n+4;
	else 
		{
	n=n-3;
	}
	if (n>36) n=1;
	if (n<1) n=36;
	}
	return 0;
}