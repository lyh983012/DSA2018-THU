// ConsoleApplication3.cpp : 定义控制台应用程序的入口
//

#include "stdafx.h"
#include<iostream>

using namespace std;

void main()
{
char n;
long double r,a,b;
cout<<"请选择图形类型，正方形为1，圆形为2，长方形为3,输入0退出:"<<endl;
cin>>n;
while(n!='0')
{
	switch (n)
{
case '1':
	cout<<"please enter the a"<<endl;
	cin>>a;
	cout<<"S="<<(a*a)<<endl;
	cout<<"请选择图形类型，正方形为1，圆形为2，长方形为3,输入0退出:"<<endl;
	cin>>n;
	break;
case '2':
	cout<<"please enter the r"<<endl;
	cin>>r;
	cout<<"S="<<(r*r*3.141592653589793)<<endl;
	cout<<"请选择图形类型，正方形为1，圆形为2，长方形为3,输入0退出:"<<endl;
	cin>>n;
	break;
case '3':
	cout<<"please enter the a and b"<<endl;
	cin>>a>>b;
	cout<<"S="<<(a*b)<<endl;
	cout<<"请选择图形类型，正方形为1，圆形为2，长方形为3,输入0退出:"<<endl;
	cin>>n;
	break;
default:
	cout<<"please choose the right mode"<<endl;
	cin>>n;
	break;
}}
}

