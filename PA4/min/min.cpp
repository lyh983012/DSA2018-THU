#include<iostream>
using namespace std;
#define lc index*2 
#define rc index*2+1
#define pr index/2
#define ln index-1
#define rn index+1

int main(){
	int n,k;
	fread(&n,sizeof(int) , 1, stdin);
	fread(&k,sizeof(int) , 1, stdin);
	int len=1;
    while(len<k){
         len<<=1;
	}
	int* que=new int[len+1]();
	int temp,index;
	int head=1;
	for(int i=0;i<n;i++){
		fread(&temp,sizeof(int) , 1, stdin);
		if(head<k+1){ //if less ,put in the last location and level up the maximun
			index=head;
			que[index]=temp;
			while(pr){
				if(que[pr]<que[index]){
					temp=que[index];
					que[index]=que[pr];
					que[pr]=temp;
					index=pr;
				}else break; //keep the max element located in the top of the heap,,construct a max leap
			}
		head++;
		}else{//adjust the max leap
			index=1;
			if(temp<que[index]){
				que[index]=temp;
				while(index<=k){
					if(lc<=k && rc<=k){
						if (que[lc]>que[rc]){
							if(que[index]<que[lc]){
								temp=que[lc];
								que[lc]=que[index];
								que[index]=temp;
								index=lc;
							}else break;
						}else {
							if(que[index]<que[rc]){
								temp=que[rc];
								que[rc]=que[index];
								que[index]=temp;
								index=rc;
							}else break;
						}
					}else{
						if(lc<=k && que[index]<que[lc]){
								temp=que[lc];
								que[lc]=que[index];
								que[index]=temp;
								index=lc;
						}else break;
					}
				}
			}
		}
	}
	cout<<que[1];
	return 0;
}



/*
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


int n;
fread(&n,sizeof(int) , 1, stdin);
//int testData[]={13,1,-1,1,0,2,0,3,0,5,5,7,11,7,0,7,7,8,1,8,12,9,3,10,6,10,7};
//int n=testData[0];
int *X=new int [n];
int *Y=new int [n];
for (int i=0;i<n;i++)
{
	fread(&X[i], sizeof(int), 1, stdin);
	fread(&Y[i], sizeof(int), 1, stdin);
	//fread(&X[i], sizeof(int), 1, fp1);
	//fread(&Y[i], sizeof(int), 1, fp1);
	//X[i]=testData[2*i+1];
	//Y[i]=testData[2*i+2];
}	
///

}*/