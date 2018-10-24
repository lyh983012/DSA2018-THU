#include<cstdio> 
#include<iostream>
using namespace std;

int total,order;
int activeid=0;
long long int sum;
int code[10000000];

class bitmap
{
public:
	int mark[1250000];
	bitmap(){};//构造
	void set(int id){mark[id>>3]|=(0x80>>(id&0x07));}
	void deleteid(int id){mark[id>>3]&=~(0x80>>(id&0x07));}
	bool check(int id){return mark[id>>3]&(0x80>>(id&0x07));}
	~bitmap(){};//析构
};
bitmap bit;
char c;
int id,code0;
int main()
{
setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);//设置输入缓冲区
scanf("%d%d",&total,&order);
for(int i=0;i<order;i++)
 {
	 scanf("%s",c);
	 switch(c)
	  {
	  case('I'):
	  {
		  scanf("%d%d",&id,&code0);
		  if(bit.check(id)){code[id]=code0;}
		  else{bit.set(id);activeid++;code[id]=code0;}
	  break;
	  }
	  case('O'):
	  {
		  scanf("%d",&id);
		  if(bit.check(id)){bit.deleteid(id);activeid--;code[id]=-1;}
	  break;
	  }
	  case('C'):
	  {  
		  for(int j=0;j<(total+9)/8;j++)
		  {bit.mark[j]=0;}
		  activeid=0;
		  break;
	  }
	  case('N'):
	  {
	  sum+=activeid;
	  break;
	  }
	  case('Q'):
	  {
	  scanf("%d",&id);
	  sum+=code[id];
	  break;
	  } 
	  }
  }
cout<<sum;
}
