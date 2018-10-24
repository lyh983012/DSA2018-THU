
#include<iostream>
#include"stdio.h"
#include"time.h"

using namespace std;

void generate(int n, int* ap)
{
	srand(n);
	for(int i=0;i<=n-1;i++)
	{
	ap[i]=rand();
	}
}

int bubsort(int n , int* ap){

int temp;
for (int i=0;i<=n-1;i++)
	for (int j=0;j<=n-2-i;j++){
		if (ap[j]>ap[j+1])
		{
			temp=ap[j];
			ap[j]=ap[j+1];
			ap[j+1]=temp;
		}
	}

for(int i=0;i<=n-1;i++)
	cout<<ap[i]<<" ";
cout<<endl;
return 0;
}

int chosort(int n , int* ap){

int temp;

for (int i=1;i<=n-1;i++)
{
	int j=i-1;
	temp=ap[i];
	while(ap[i]<ap[j] && j>=0)
		j--;
	j+=1;
	for (int k=i;k>j;k--)
		ap[k]=ap[k-1];
	ap[j]=temp;
}
for(int i=0;i<=n-1;i++)
	cout<<ap[i]<<" ";
cout<<endl;
return 0;
}

int bichsort(int n , int* ap){

int temp;
int lo,hi;
for (int i=1;i<=n-1;i++)
{
	int j=i-1;
	temp=ap[i];
	lo=0,hi=j;
	while(1)
	{
		if(j==0 && ap[i]<ap[j])
			break;
		else if (ap[i]>=ap[j] && ap[i]<=ap[j+1])
			break;
		if (ap[i]<ap[j])
		{
			hi=j;
			j=(lo+j)/2;
		}
		else
		{
			lo=j;
			j=(hi+j)/2;
		}
	}
	for (int k=i;k>j+1;k--)
		ap[k]=ap[k-1];
	ap[j]=temp;
}
for(int i=0;i<=n-1;i++)
	cout<<ap[i]<<" ";
cout<<endl;
return 0;
}

int shelsort(int n , int* ap){

int temp;
int h=n;
while(h>1)
{
h=h/2;
for (int i=h;i<=n-h;i+=h)
{
	int j=i-h;
	temp=ap[i];
	while(ap[i]<ap[j] && j>=0)
		j-=h;
	j+=h;
	for (int k=i;k>j;k--)
		ap[k]=ap[k-h];
	ap[j]=temp;
}
}

for(int i=0;i<=n-1;i++)
	cout<<ap[i]<<" ";
cout<<endl;
return 0;
}


int main()
{

//--------------------_______
int n,temp;
cout<<"input n";
cin>>n;
int* ap= new int[n];
//for(int i=0;i<=n-1;i++)
//	cin>>ap[i];
//_____________________-------
cout<<"bubsort"<<endl;
generate(n,ap);
bubsort(n,ap);
cout<<"chossort"<<endl;
generate(n,ap);
chosort(n,ap);
cout<<"bichsort"<<endl;
generate(n,ap);
bichsort(n,ap);
cout<<"shelsort"<<endl;
generate(n,ap);
shelsort(n,ap);
system("pause");
return 0;
}

