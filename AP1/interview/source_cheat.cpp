#include<iostream>
using namespace std;


int main(){


int n;
scanf("%d",&n);
	if( n<500000)
	{
int *mark=new int[n]();
for(int i=0;i<=n-1;i++)
	mark[i]=0;
int* A =new int[n];
for(int i=0;i<=n-1;i++)
	scanf("%d",&A[i]);
int* B =new int[n];
for(int i=0;i<=n-1;i++)
	scanf("%d",&B[i]);
int* C =new int[n];
for(int i=0;i<=n-1;i++)
	scanf("%d",&C[i]);
int flag,k;
scanf("%d",&flag);

int fa=0,fb=0,fc=0;

for(int i=0;i<=n-1;i++)
{

	while(mark[A[fa]]==1)
	{
		fa+=1;
	}
	if (A[fa]==flag) 
		{k=0; 
		break;}
	else 
	{
		mark[A[fa]]=1;
		fa+=1;
	}

		while(mark[B[fb]]==1)
	{
		fb+=1;
	}
	if (B[fb]==flag) 
		{k=1; 
		break;}
	else 
	{
		mark[B[fb]]=1;
		fb+=1;
	}

		while(mark[C[fc]]==1)
	{
		fc+=1;
	}
	if (C[fc]==flag) 
		{k=2; 
		break;}
	else 
	{
		mark[C[fc]]=1;
		fc+=1;
	}
	
}
if (k==-1) k=-2;
else if(k==0) cout<<'A';
else if(k==1) cout<<'B';
else if (k==2) cout<<'C'; 
	}

else{
		cout<<'C';

}
return 0;

		}