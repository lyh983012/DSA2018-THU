
#include "stdafx.h"
#include"type.h"

using namespace std;

int m,n0,n1,xs1,xs2,nx;
void main()
{
 int n=0;
 Type print(1,1,1);
 cout<<endl;
 cout<<"�����ϵļ�������ѡ�����ģʽ���ӷ�Ϊ1������Ϊ2,�˷�Ϊ3,����Ϊ4,���Ե���Ϊ5�������ִ�������������ģʽ������"<<endl;
 cout<<"����ģʽ��(�˳��밴0)";
 cin>>n;
 do
 {
 switch(n)
 {
case 1:
 cout<<"��������������"<<endl;
 print.input();
 print.add();
 cout<<"����:";
 print.outputc();
 break;
case 2:
 cout<<"��������������"<<endl;
 print.input();
 m=print.mov();
 cout<<"����:";
 if (m) cout<<"-";
 print.outputc();
 break;
case 3:
 cout<<"��������������"<<endl;
 print.input();
 print.time();
 cout<<"�˻���:";
 print.outputc();
 break;
case 4:
 cout<<"�������뱻�������������"<<endl;
 print.input();
 print.div();
 break;
 case 5:
 cout<<"���������������Լ�����f��n+2��=a*f��n+1��+b*f(n����f(2),f(1),a , b"<<endl;
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
 cout<<"��Ч�ļ���ģʽ";
  }
cout<<endl;
 cout<<"����ģʽ��(�˳��밴0)";
 cin>>n;
 }
while(n!=0);
}



