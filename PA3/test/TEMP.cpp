/*
#include <cstdlib>
#include<string.h>

#define lowbit(x) ((x)&(-x)) 

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

int** sumtree;
int** temp;
node* head;


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

inline int check_range(int x,int y){
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
	sumtree = new int *[n + 1];
    for (int i = 1; i <= n; i++) { 
        sumtree[i] = new int[m + 1];
		for(int j = 1;j <= m ;j+=1){
				sumtree[i][j]=temp[i][j];
		}
	}
	for(int i = 0;i <= n ;i++)
		for(int tem = 2;tem <= m/2 ;tem*=2){
			for(int j = tem;j <= m ;j+=tem){
				sumtree[i][j]+=temp[i][j-tem/2];
		}
	}
	for(int j = 0;j <= m ;j++)
		for(int tem = 2;tem <= m/2 ;tem*=2){
			for(int i = tem;i <= m ;i+=tem){
				sumtree[i-tem/2][j]+=temp[i][j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<sumtree[i][j]<<" ";
		}
	cout<<endl;
	}
	return;
}

int query(int x1, int y1, int x2, int y2) {
   int temp=check_range(x2,y2)+check_range(x1-1,y1-1)-check_range(x2,y1-1)-check_range(x1-1,y2);
   int avr = temp/((x2-x1+1)*(y2-y1+1));
   return avr;
}

void change(int x, int y, int temp) {
    change_point(*head,x,y,temp);
	return;
}
*/