#include<iostream>
using namespace std;
#define pass(x1,y4,x2,y2,x3,y3) (((x2)-(x1))*((y3)-(y2))-((x3)-(x2))*((y2)-(y4))>(0) || ((x1)==(x3) && (y3)==(y4)) ) 


int main(){
/*
测试自己的二进制数据文件
int testData[]={11,1,6,1,0,4,11,5,5,7,11,7,0,7,7,8,1,8,12,9,3,10,6};
FILE* fp = fopen("test.in", "wb");
for(int i=0;i<25;i++){
	fwrite(&testData[i], sizeof(int), 1, fp);
}
fclose(fp);
FILE* fp1 = fopen("test.in", "rb");
int n;
//fread(&n,sizeof(int) , 1, stdin);
fread(&n,sizeof(int) , 1, fp1);
int testData[]={11,1,0,1,6,4,11,5,5,7,11,7,0,7,7,8,1,8,12,9,3,10,6};
int n=testData[0];
*/

//读入二进制数据
int n;
fread(&n,sizeof(int) , 1, stdin);
int *X=new int [n];
int *Y=new int [n];
for (int i=0;i<n;i++)//先读xy坐标值
{
	fread(&X[i], sizeof(int), 1, stdin);
	fread(&Y[i], sizeof(int), 1, stdin);
}	
///

long*L =new long[n];	//对应每个坐标x中y的最小值
long*H =new long[n];	//对应每个坐标x中y的最大值
long*X0 =new long[n];	//对应“出现过的x”
long temp=0;			
long temp1=0;			
long ymin=Y[0];			
long ymax=Y[0];			
////////////////////////////////////////////////////////////
//找出点集的一个密的边界：由每个x的最高／最低点构成
for(int i=1;i<n;i++){
	if( X[i]==X[i-1]){
		if(ymax<Y[i])
			ymax=Y[i];
		if(ymin>Y[i])
			ymin=Y[i];
		if(i==(n-1)){
			L[temp]=ymin;
			H[temp1]=ymax;
			X0[temp]=X[i];	
			temp++;
			if(ymax!=ymin)
				temp1++;
			break;
		}
	}else{
		L[temp]=ymin;
		H[temp1]=ymax;
		X0[temp]=X[i-1];
		temp++;
		temp1++;
		ymin=Y[i];
		ymax=Y[i];
		if(i==(n-1)){
			L[temp]=ymin;
			X0[temp]=X[i];	
			temp++;
			break;
	}}}	
////////////////////////////////////////////////////////////////
//把点集从x，y都最小的点开始，逆时针排列成一个环，存在一个数组中（将H反向和L拼接，
//并且最后一个点和第一个点相同

）
	for(int i=0;i<temp1;i++){
		L[temp+i]=H[temp1-i-1];
		X0[temp+i]=X0[temp1-i-1];
	}
	long len=temp+temp1+1;//
	if((H[0]==L[0]))
	{		
		len--;
	}else{
		X0[len-1]=X0[0];
		L[len-1]=L[0];
	}

////////////////////////////////////////////////////////////
//用一个栈存储凸包点，相邻三个点判断是否在凸包上，破坏凸性质则放弃中间点，再次检查
	long* zhan=new long[len];
	zhan[0]=0,zhan[1]=1;
	long head=2;
	long lenth=2;
	while(head!=len){
		if(pass(X0[zhan[lenth-2]],L[zhan[lenth-2]],X0[zhan[lenth-1]],L[zhan[lenth-1]],X0[head],L[head])){
			lenth++;
			zhan[lenth-1]=head;
			head++;
		}else{
			zhan[lenth-1]=head;
			head++;
			while(lenth>=3 && !pass(X0[zhan[lenth-3]],L[zhan[lenth-3]],X0[zhan[lenth-2]],L[zhan[lenth-2]],X0[zhan[lenth-1]],L[zhan[lenth-1]])){
				zhan[lenth-2]=zhan[lenth-1];
				lenth--;
			}
		}	
}
/////////////////////////////////////////////////
//找出题目要求的点，进行逆时针输出

	ymin=L[0];
	long xmin=X0[0];
	long count=0;
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

	return 0;

}