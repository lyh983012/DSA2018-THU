/*
#include<iostream>
using namespace std;
int *sorted;
int* m;
int *help;

void Merge( int*  unsorted,int lo,int mi,int hi){

	int head1=lo;
	int head2=mi+1;
	int head=lo;
	while(head1<=mi || head2<= hi){
		if(head1<=mi && head2<= hi){
			if( unsorted[head1]< unsorted[head2]){
				sorted[head]= unsorted[head1];
				head1++;
			}else{
				sorted[head]= unsorted[head2];
				head2++;
			}
		}
		else if (head1<=mi){
			sorted[head]= unsorted[head1];
			head1++;
		}
		else if (head2<=hi){
			sorted[head]= unsorted[head2];
			head2++;
		}
		head++;
	}
	for(int i=lo;i<=hi;i++){
		unsorted[i]=sorted[i];
	}
}

 
void MergeSort( int* unsorted, int lo, int hi){
	cout<<lo<<" "<<hi<<endl;
    if(lo < hi){
        int mi = (lo + hi)/2;
        MergeSort(unsorted, lo, mi);
        MergeSort(unsorted, mi+1, hi);
        Merge(unsorted, lo, mi, hi);
    }
}



int main(){
	m=new int[10];
	for(int i=9;i>=0;i--){
		m[9-i]=i;
		//cout<<i<<endl;
	}
	sorted=new int[10];

	MergeSort(m,0,9);

	for(int i=0;i<10;i++){
		cout<<sorted[i]<<endl;

	}

	for(int i=0;i<10;i++){
		cout<<m[i]<<endl;

	}

	return 0;

}

*/