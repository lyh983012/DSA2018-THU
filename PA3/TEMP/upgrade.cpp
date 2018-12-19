#include<iostream>
#include<string.h>
#define lowbit(x) ((x)&(-x))  
using namespace std;


int* pocker;
int* raw;
int n,m;

int direct_sum(int x,int y){
	int sum1=0,sum2=0;

	for(int i=x;i>0;i-=lowbit(i))// traverse all bit in I , exp: sum[(111)]=C[(100)]+C[(110)]+C[(111)];
	{
			sum1+=pocker[i];
	}
	for(int i=y;i>0;i-=lowbit(i))// traverse all bit in I , exp: sum[(111)]=C[(100)]+C[(110)]+C[(111)];
	{
			sum2+=pocker[i];
	}
	return sum2-sum1;
}

void change(int x) {
	int del;
	if(raw[x]==1){
		del=-1;
		raw[x]=0;
	}else {
		del=1;
		raw[x]=1;
	}
	for(int i=x;i<=n+1;i+=lowbit(i)){
				pocker[i]+=del;		
			}
}

int main(){
	char command;
	scanf("d%d%",&n,&m);
	pocker=new int[n+1];
	raw=new int[n+1];
	pocker[0]=0;
	raw[0]=0;
	memset(pocker,1,sizeof(int)*(n+1));
	memset(raw,1,sizeof(int)*(n+1));
	for(int tem = 2;tem <= m ;tem=tem*2){
			for(int i = tem;i <= m ;i+=tem){
				pocker[i]+=pocker[i-tem/2];
		}
	} 
	int i,j;
	for(int i=0;i<m;i++){
	char temp[2];
	scanf("s%",&temp);
	command=temp[0];
		if(command=='Q'){
			scanf("d%d%",&i,&j);
			int a=direct_sum(i-1,j);
			printf("d%/n",a);
		}
		else
		{
			scanf("d%",&i);
			change(i);
		}
	}

}