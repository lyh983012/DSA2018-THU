/*
#include <cstdlib>
#include "temperature.h"

using namespace std;


class node{

public:
	int x1,x2,y1,y2;
	node* son;
	int sum;
	bool isend;
	bool isline;
	node()
	{
	isend=false;
	isline=false;
	}
	void test(){
	}
};

int** temp;
node* head;


int lowbit(int x){
int n=0;
while(!(x&1)){
	x=x>>1;
	n++;
}
return n;
}


void build_2dtree(node& v,int x1,int x2,int y1,int y2){
    if(x2-x1 == 0 ||y2-y1== 0){
		v.sum=0;
		v.x1=x1;
		v.x2=x2;
		v.y1=y1;
		v.y2=y2;
		v.isline=true;
        return;
    }else if(x2-x1 == 1 && y2-y1 == 1) {
		v.x1=x1;
		v.x2=x2;
		v.y1=y1;
		v.y2=y2;
		v.sum=temp[x1][y1];
		v.isend=true;
        return;
    }
	v.x1=x1;
	v.x2=x2;
	v.y1=y1;
	v.y2=y2;
	int xmi=(x1+x2)/2;
	int ymi=(y1+y2)/2;
	v.son=new node[4]();
	build_2dtree(v.son[0],xmi,x2,ymi,y2); //1
	build_2dtree(v.son[1],x1,xmi,ymi,y2); //2
	build_2dtree(v.son[2],x1,xmi,y1,ymi); //3
	build_2dtree(v.son[3],xmi,x2,y1,ymi); //4 xiangxian   
	v.sum=v.son[0].sum+v.son[1].sum+v.son[2].sum+v.son[3].sum;
	return;
}

inline int change_point(node& node,int x,int y,int temp){
	
	if(node.isend && node.x1==x && node.y1==y){
		int del=temp-node.sum;
		node.sum=temp;
		return del;
	}else{
		int xmi=(node.x1+node.x2)/2;
		int ymi=(node.y1+node.y2)/2;
		if (node.x2>x && x>=xmi && node.y2>y && y>=ymi ) //[xmi,x2),[ymi,y2)
		{
			int del=change_point(node.son[0],x,y,temp);
			node.sum+=del;
			return del;
		}
		else if (xmi>x && x>=node.x1 && node.y2>y && y>=ymi)// [x1,xmi),[ymi,y2)
		{
			int del=change_point(node.son[1],x,y,temp);
			node.sum+=del;
			return del;
		}
		else if (xmi>x && x>=node.x1 && ymi>y && y>=node.y1)//[x1,xmi),[y1,ymi)
		{
			int del=change_point(node.son[2],x,y,temp);
			node.sum+=del;
			return del;
		}
		else if (node.x2>x && x>=xmi && ymi>y && y>=node.y1)//[xmi,x2),[y1,ymi)
		{
			int del=change_point(node.son[3],x,y,temp);
			node.sum+=del;
			return del;
		}
	}
}

inline int check_range(node& node,int x1,int x2,int y1,int y2){
	if(node.isline || x1>=x2 || y1>=y2  ){
		return 0;
	}
	if(node.x1>=x1 && node.y1>=y1 && x2>=node.x2 && y2>=node.y2){ 
		return node.sum;
	}else if(!node.isend){
		int xmi=(node.x1+node.x2)/2;
		int ymi=(node.y1+node.y2)/2;
		int sum1,sum2,sum3,sum4;
		int sum;
//ymi>y1---wrong
		if(x1<xmi && y1<ymi && x2>xmi && y2>ymi){
			sum1=check_range(node.son[0],xmi,x2,ymi,y2);
			sum2=check_range(node.son[1],x1,xmi,ymi,y2);
			sum3=check_range(node.son[2],x1,xmi,y1,ymi);
			sum4=check_range(node.son[3],xmi,x2,y1,ymi);
			sum=sum1+sum2+sum3+sum4;
		}else if(y1>=ymi){
			if(x1<xmi && x2>xmi){
				sum1=check_range(node.son[0],xmi,x2,y1,y2);
				sum2=check_range(node.son[1],x1,xmi,y1,y2);
				sum=sum1+sum2;
			}else if(x1>=xmi){
				sum=check_range(node.son[0],x1,x2,y1,y2);
			}else {
				sum=check_range(node.son[1],x1,x2,y1,y2);
			}
		}else if(y2<=ymi){
			if(x1<xmi && x2>xmi){
				sum1=check_range(node.son[3],xmi,x2,y1,y2);
				sum2=check_range(node.son[2],x1,xmi,y1,y2);
				sum=sum1+sum2;
			}else if(x1>=xmi){
				sum=check_range(node.son[3],x1,x2,y1,y2);
			}else {
				sum=check_range(node.son[2],x1,x2,y1,y2);
			}
		}else if(x2<=xmi){
			sum1=check_range(node.son[1],x1,x2,ymi,y2);
			sum2=check_range(node.son[2],x1,x2,y1,ymi);
			sum=sum1+sum2;
		}else{
			sum1=check_range(node.son[0],x1,x2,ymi,y2);
			sum2=check_range(node.son[3],x1,x2,y1,ymi);
			sum=sum1+sum2;
		}
//recheck;
		return sum;
	}else{
		return 0;
	}
}

void init(int n, int m, int **a) {
	temp=a;
	head=new node();
	build_2dtree(*head,1,n+1,1,m+1);
	return;
}

int query(int x1, int y1, int x2, int y2) {
   int temp=check_range(*head,x1,x2+1,y1,y2+1); //change [x1,x2];[y1,y2] to [x1,x2+1);[y1,y2+1)
   int avr = temp/((x2-x1+1)*(y2-y1+1));
   return avr;
}

void change(int x, int y, int temp) {
    change_point(*head,x,y,temp);
	return;
}


int ask(int x1,int y1,int x2,int y2){
    return sum(x2,y2)+sum(x1-1,y1-1)-sum(x2,y1-1)-sum(x1-1,y2);
}


*/
