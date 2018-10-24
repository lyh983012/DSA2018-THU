
#include "stdafx.h"
#include"type.h"

using namespace std;

int m,n0,n1,xs1,xs2,nx;
void main()
{
 int n=0;
 Type print(1,1,1);
 cout<<endl;
 cout<<"林逸晗的计算器：选择计算模式，加法为1，减法为2,乘法为3,除法为4,线性递推为5，若出现错误请运行其他模式后重试"<<endl;
 cout<<"计算模式：(退出请按0)";
 cin>>n;
 do
 {
 switch(n)
 {
case 1:
 cout<<"请输入两个数字"<<endl;
 print.input();
 print.add();
 cout<<"和是:";
 print.outputc();
 break;
case 2:
 cout<<"请输入两个数字"<<endl;
 print.input();
 m=print.mov();
 cout<<"差是:";
 if (m) cout<<"-";
 print.outputc();
 break;
case 3:
 cout<<"请输入两个数字"<<endl;
 print.input();
 print.time();
 cout<<"乘积是:";
 print.outputc();
 break;
case 4:
 cout<<"请先输入被除数后输入除数"<<endl;
 print.input();
 print.div();
 break;
 case 5:
 cout<<"请先输入项数，以及符合f（n+2）=a*f（n+1）+b*f(n）的f(2),f(1),a , b"<<endl;
 cin>>nx;
 cout<<"f(1):  ";
 cin>>n0;
 cout<<"f(2):  ";
 cin>>n1;
 cout<<"   a:  ";
 cin>>xs1;
 cout<<"   b:  "; 
 cin>>xs2;
 print.fab(nx,n0,n1,xs1,xs2);
 print.outputc();
 break;
 default:
 cout<<"无效的计算模式";
  }
cout<<endl;
 cout<<"计算模式：(退出请按0)";
 cin>>n;
 }
while(n!=0);
}



