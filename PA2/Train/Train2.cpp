	/*
#include<iostream>
using namespace std;

int main(){
	cout<<"No"<<endl;
}


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int* seq=new int[n];
	int* dseq=new int[n]();

	int k=-1;
	for(int i=0;i<=n-1;i++){
		cin>>seq[i];
	}
	int pointer=0;//���������ڵȴ�����һλ
	int temp;
	int number_of_dseq=0;
	int head=-1;
	for(int pointer=0;pointer<=n;pointer++)
	{
		if (seq[pointer]!=seq[pointer+1]-1)//���ַ�˳������,��ʼ��ջ
		{
			if (seq[pointer+1]<seq[pointer+2]){
				cout<<"No"<<endl;
				system("pause");
				return 0;
			}
			temp=pointer+1;
			while(seq[temp]>seq[temp+1]){ //�ж����򳤶�
				temp++;}
			if (temp-pointer+1>m || seq[temp]!=seq[pointer]+1 ){
				cout<<"No"<<endl;
				system("pause");
				return 0;
			}
			


	return 0;
}

*/
