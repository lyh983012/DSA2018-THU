
/*#include<iostream>
#define lowbit(x) ((x)&(-x))  
using namespace std;

int n,m;
int build(int* temp,int layer_big,int start){
	if(layer_big==1){
		temp[start]=1;
		return 1;
	}
	else{
		int tem=0;
		for(int i=start;i<=layer_big;i++){
			tem+=build(temp,layer_big/2,start+i);
		}
		temp[start]=tem;
		return tem;
	}
}
int main(){

	int* pocker;
	int* raw;

	char command;
	scanf("%d%d",&n,&m);
	pocker=new int[4*n+1];
	raw=new int[n+1];
	pocker[0]=0;
	raw[0]=0;
	for(int i=1;i<n+1;i++){
		raw[i]=1;
	}
	build(pocker,n,1);
	for(int i=1;i<2*n+1;i++){
		cout<<pocker[i]<<endl;
	}
	int layer=0;
	int x,y;
	for(int i=0;i<m;i++){
		char temp[2];
		scanf("%s",&temp);
		command=temp[0];
			if(command=='Q'){
				scanf("%d%d",&x,&y);
				int sum1=0,sum2=0;
					for(int i=x-1;i>0;i-=lowbit(i))//sum of[0,x-1]
					{
							sum1+=pocker[i];
					}
					for(int i=y;i>0;i-=lowbit(i))//sum of[0,y]
					{
							sum2+=pocker[i];
					}
				int sum=sum2-sum1; //sum of[x,y]
				printf("%d\n",sum);
			}
			else
			{
				scanf("%d%d",&x,&y);
				for(int j=x;j<=y;j++){
					int del;			 //delta=+-1
					if(raw[j]==1){
						del=-1;
						raw[j]=0;
					}else {	
						del=1;
						raw[j]=1;
					}
				}
				for(int tem = 2;tem <= n ;tem=tem*2){
					for(int i = tem;i <= n ;i+=tem){
						pocker[i]+=pocker[i-tem/2];
					}
				} 
			}
	}
	return 0;
}*/
