/*
#include<iostream>
#define lowbit(x) ((x)&(-x))  
using namespace std;

int main(){

	int* pocker;
	int* raw;
	int n,m;
	char command;
	scanf("%d%d",&n,&m);
	pocker=new int[n+1];
	raw=new int[n+1];
	pocker[0]=0;
	raw[0]=0;
	for(int i=1;i<n+1;i++){
		pocker[i]=raw[i]=1;
	}
	for(int tem = 2;tem <= n ;tem=tem*2){
			for(int i = tem;i <= n ;i+=tem){
				pocker[i]+=pocker[i-tem/2];
		}
	}  //construct a sum tree in "pocker"
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



int change(int i,int j,int index){
	int a=tree[index].a;
	int b=tree[index].b;
	int mi=(a+b)/2;
	if(i>=b || j<=a || i>=j ) // none
		return 0;
	else if(i<=a && b<=j){  // all 
		int raw=tree[index].sum;
		tree[index].sum=tree[index].sum0-tree[index].sum;
		if(length(index)>1){
			tree[index].lazy*=-1;	//switch mode {waiting/sleeping}
		}
		return tree[index].sum-raw;
	}
	else if(a<=i && j<=b){
		if(j<=mi){
			int del=change(i,j,lc);
			tree[index].sum+=del;
			return del;
		}else if(mi<=i){
			int del=change(i,j,rc);
			tree[index].sum+=del;
			return del;
		}else{
			int del=change(i,mi,lc)+change(mi,j,rc);  
			tree[index].sum+=del;
			return del;
		}
	}
	else if(a<=i){
		if(i<mi){
			int del=change(i,mi,lc)+change(mi,b,rc);
			tree[index].sum+=del;
			return del+change(b,j,rn);
		}
		else
		{
			int del=change(i,b,rc);
			tree[index].sum+=del;
			return del+change(b,j,rn);
		}
	}
	else {
		if(mi<j){
			int del=change(a,mi,lc)+change(mi,j,rc);  
			tree[index].sum+=del;
			return del+change(i,a,ln);
		}
		else{
			int del=change(a,j,lc);
			tree[index].sum+=del;
			return del+	change(i,a,ln);
		}
	}
}
*/