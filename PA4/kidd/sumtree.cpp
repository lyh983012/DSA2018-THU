#include <cstdlib>
#include<iostream>
#define lowbit(x) ((x)&(-x))  
using namespace std;

int** sumtree;
int** temp2;
int N,M;

//C[i]=A[i-2^k+1]+A[i-2^k+2]+......A[i];
//level up to 2d tree
//sum=C[i]+C[i-lowbit(i)]+C[i-lowbit(i)-lowbit[i-lowbit(i)])+....
long long direct_sum(int x,int y){
	long long sum=0;
	if(x==0 || y==0 )
		return 0;
	for(int i=x;i>0;i-=lowbit(i))// traverse all bit in I , exp: sum[(111)]=C[(100)]+C[(110)]+C[(111)];
	{
		for(int j=y;j>0;j-=lowbit(j)){
			sum+=sumtree[i][j];
		}
	}
	return sum;
}
	
void init(int n, int m, int **a) {
	temp2=a;
	N=n,M=m;
	sumtree = new int *[n + 1];
    for (int i = 0; i <= n; i++) { 
        sumtree[i] = new int[m + 1];
		if(i>0){
			for(int j = 1;j <= m ;j++){
					sumtree[i][j]=a[i][j];
			}
		}
	}
	for(int i = 1;i <= n ;i++)
		for(int tem = 2;tem <= m ;tem=tem*2){
			for(int j = tem;j <= m ;j+=tem){
				sumtree[i][j]+=sumtree[i][j-tem/2];
		}
	} 
	for(int j = 1;j <= m ;j++)
		for(int tem = 2;tem <= n ;tem=tem*2){
			for(int i = tem;i <= n ;i+=tem){
				sumtree[i][j]+=sumtree[i-tem/2][j];
		}
	}
	return;
}

int query(int x1, int y1, int x2, int y2) {
   long long sum=direct_sum(x2,y2)-direct_sum(x2,y1-1)-direct_sum(x1-1,y2)+direct_sum(x1-1,y1-1);
   int avr = sum/((x2-x1+1)*(y2-y1+1));
   return avr;
}

void change(int x, int y, int temp) {
	int del=temp-temp2[x][y];
	temp2[x][y]=temp;
	for(int i=x;i<=N;i+=lowbit(i)){
			 for(int j=y;j<=M;j+=lowbit(j))
			{
				sumtree[i][j]+=del;		
			}
		}
	return;
}
