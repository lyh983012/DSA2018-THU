// 쳲��������� ��ҵ3-2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

using namespace std;


int n;
long long m2,m1,f,f1;


int main()
{
	do{

 m2=1;
 m1=1;
 f=0;
 f1=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{ f1=f;
		  f=m1+m2;
		  m2=m1;
		  m1=f1;
			}
	cout<<f;
	cin>>n;}
while(1);
			return 0;

}
				
