#include<iostream>
using namespace std;


long long head;
char* str=new char[34000004]();
int* len=new int[34000004]();

int main(){

	char tem;
	long long sum=0;
	head=0;
	str[head++]='?';
	str[head++]='!';
	while((tem=getchar())!='\n'){
		str[head++]=tem;
		str[head++]='!';
	}
		str[head]='.';
	int imax=0;
	int pmax=0;
	len[0]=1;
	for(int i=2;i<head;i++){
		if(i<pmax){
			if(imax*2-i>=0 && len[2*imax-i]<pmax-i)
				len[i]=len[2*imax-i];
			else
				len[i]=pmax-i;
		}else{
			len[i]=1;
		}
		int start=len[i];
		while(i-start>=0 && head>i+start && str[i-start]==str[i+start]){
				start++;
		}
		len[i]=start;
		if(len[i]+i>pmax){
			pmax=len[i]+i;
			imax=i;
			}
		if(len[i]%2==0)
			sum+=len[i]/2;
		else
			sum+=(len[i]-1)/2;
	}

	cout<<sum;


	return 0;
}