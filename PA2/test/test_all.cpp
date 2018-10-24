#include<iostream>
using namespace std;

class point{

public:
	long long data;
	long long count;
	point(long long a,long long b){
		data=a;
		count=b;
	}
	point(){

	}
};

int search(point* seq, long long aim,  long long lo,long long hi)//输出不小于它的最小元素下标
{
	long long mi;
	while(0<hi-lo){
		mi=(lo+hi)>>1;
		if( aim<seq[mi].data) hi=mi;
		else if( aim>seq[mi].data) {
			lo=mi+1;
		}
		else {
			return mi;}
	}
	return mi;
}
void print_seq(point* seq,  long long lo, long long hi)
{
	cout<<"max data= ";
	for(int i=lo;i<hi;i++)
		cout<<seq[i].data<<" ";
	cout<<endl<<"max count= ";
	for(int i=lo;i<hi;i++)
		cout<<seq[i].count<<" ";
	cout<<endl;
}
void print_seq(long long * seq,  long long lo, long long hi)
{
	cout<<"main data= ";
	for(int i=lo;i<hi;i++)
		cout<<seq[i]<<" ";
	cout<<endl;

}

int search(point* seq,long long aim, long long lo,long long hi)//输出不小于它的最小元素下标
{
	long long mi;
	while(0<hi-lo){
		mi=(lo+hi)>>1;
		if( aim<seq[mi].data) hi=mi;
		else if( aim>seq[mi].data) {
			lo=mi+1;
		}
		else {
			return mi;}
	}
	return mi;
}
void print_seq(point* seq, long long lo,long long hi)
{
	cout<<"max data= ";
	for(int i=lo;i<hi;i++)
		cout<<seq[lo].data<<" ";
	cout<<endl<<"max count= ";
	for(int i=lo;i<hi;i++)
		cout<<seq[lo].count<<" ";
	cout<<endl;
}
void print_seq(long long* seq, long long lo,long long hi)
{
	cout<<"long data= ";
	for(int i=lo;i<hi;i++)
		cout<<seq[lo]<<" ";
	cout<<endl;

}
void main(){
	int n;
	cin>>n;
	point* test= new point[n];
	for(int i=0;i<=n-1;i++){
		test[i]= * new point(i*2,1);
		cout<<test[i].data<<endl;
	}
	int m;
	while(1){
		cin>>m;
		cout<<search(test,m,0,n-1)<<endl;
		cout<<"--"<<endl;
	}
}