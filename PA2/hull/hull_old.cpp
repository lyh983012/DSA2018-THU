
#include<iostream>
using namespace std;
#define out(x1,y4,x2,y2,x3,y3) (((x2)-(x1))*((y3)-(y2))-((x3)-(x2))*((y2)-(y4))>(0) || ((x1)==(x3) && (y4)==(y3))) 

int main(){
/*	
int testData[]={11,1,6,1,0,4,11,5,5,7,11,7,0,7,7,8,1,8,12,9,3,10,6};
FILE* fp = fopen("test.in", "w+");
for(int i=0;i<23;i++){
	fwrite(&testData[i], sizeof(int), 1, fp);}
fclose(fp);
fp = fopen("test.in", "r");
*/
int n=0;
fread(&n,sizeof(int) , 1, stdin);

int *X=new int [n];
int *Y=new int [n];
for (int i=0;i<n;i++)
{
	fread(&X[i], sizeof(int), 1, stdin);
	fread(&Y[i], sizeof(int), 1, stdin);
}

////////////////////////////////////////
int*L =new int[n];
int*H =new int[n];
int*X0 =new int[n];
int temp=0;
int ymin=Y[0];
int ymax=Y[0];
for(int i=1;i<=n-1;i++){
	if( X[i]==X[i-1]){
		if(ymax<Y[i])
			ymax=Y[i];
		if(ymin>Y[i])
			ymin=Y[i];
	}else{
		L[temp]=ymin;
		H[temp]=ymax;
		X0[temp]=X[i-1];
		temp++;
		ymin=Y[i];
		ymax=Y[i];
	}
	if(i==n-1){
		L[temp]=ymin;
		H[temp]=ymax;
		X0[temp]=X[i];	
	}
	}	
	int t=0;
	if(L[temp]==H[temp])
		t++;
	for(int i=0;i<=temp-t;i++){
		L[1+temp+i]=H[temp-i-1];
		X0[1+temp+i]=X0[temp-i-1];
	}
	int len=temp*2+2-t;
	if(L[0]==H[0])
		len--;

////////////////////////////////////////需要X0，L两个列，顺序的。
	
	len++;
	int* zhan=new int[len];
	X0[len-1]=X0[0];
	L[len-1]=L[0];
	zhan[0]=0;
	zhan[1]=1;
	int head=2;
	int lenth=2;
	while(!(head==len))
	{
	if(X0[head]==X0[head+1] && L[head]==L[head+1]){
	head++;
	continue;
	}
	else if(out(X0[zhan[lenth-2]],L[zhan[lenth-2]],X0[zhan[lenth-1]],L[zhan[lenth-1]],X0[head],L[head])){
		lenth++;
		zhan[lenth-1]=head;
		head++;
	}else{
		zhan[lenth-1]=head;
		if (lenth>=3){
			while(!out(X0[zhan[lenth-3]],L[zhan[lenth-3]],X0[zhan[lenth-2]],L[zhan[lenth-2]],X0[zhan[lenth-1]],L[zhan[lenth-1]])){
				zhan[lenth-2]=zhan[lenth-1];
				lenth--;
			}
		}
		head++;
	}}
///

ymin=L[0];
int xmin=X0[0];
int count=0;
for(int i=0;i<lenth-1;i++){
	if(L[zhan[i]]<ymin){
		ymin=L[zhan[i]];
		xmin=X[zhan[i]];
		count=i;
	}else if(L[zhan[i]]==ymin && xmin>X[zhan[i]]){
		xmin=X[zhan[i]];
		count=i;
		}
	}
for(int i=count;i<lenth-1;i++){
	printf("%d %d\n",X0[zhan[i]],L[zhan[i]]);
}
for(int i=0;i<count;i++){
	printf("%d %d\n",X0[zhan[i]],L[zhan[i]]);
}
//system("pause");
return 0;

}
