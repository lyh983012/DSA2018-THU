/*
#include<iostream>
using namespace std;

class material{

public:
	bool used;
	int height;
	material* parent;
	material* lc;
	material* rc;
	int hi,di;
	int index;
	int ubfactor;
	material(){
		used=false;
	}
};

class bridge{

public:
	int pi,vi;
};


bridge* BGS;
material* MTS;
int* sorted_bgs;
int* sorted_mts;
int* help;

void Merge( int*  unsorted,int lo,int mi,int hi){

	int head1=lo;
	int head2=mi+1;
	int head=lo;
	while(head1<=mi || head2<= hi){
		if(head1<=mi && head2<= hi){
			if( BGS[unsorted[head1]].vi> BGS[unsorted[head2]].vi){
				help[head]= unsorted[head1];
				head1++;
			}else{
				help[head]= unsorted[head2];
				head2++;
			}
		}
		else if (head1<=mi){
			help[head]= unsorted[head1];
			head1++;
		}
		else if (head2<=hi){
			help[head]= unsorted[head2];
			head2++;
		}
		head++;
	}
	for(int i=lo;i<=hi;i++){
		unsorted[i]=help[i];
	}
}

void MergeSort( int* unsorted, int lo, int hi){
    if(lo < hi){
        int mi = (lo + hi)/2;
        MergeSort(unsorted, lo, mi);
        MergeSort(unsorted, mi+1, hi);
        Merge(unsorted, lo, mi, hi);
    }
}

void Merge2( int*  unsorted,int lo,int mi,int hi){

	int head1=lo;
	int head2=mi+1;
	int head=lo;
	while(head1<=mi || head2<= hi){
		if(head1<=mi && head2<= hi){
			if( MTS[unsorted[head1]].hi> MTS[unsorted[head2]].hi){
				help[head]= unsorted[head1];
				head1++;
			}else{
				help[head]= unsorted[head2];
				head2++;
			}
		}
		else if (head1<=mi){
			help[head]= unsorted[head1];
			head1++;
		}
		else if (head2<=hi){
			help[head]= unsorted[head2];
			head2++;
		}
		head++;
	}
	for(int i=lo;i<=hi;i++){
		unsorted[i]=help[i];
	}
}

void MergeSort2( int* unsorted, int lo, int hi){
    if(lo < hi){
        int mi = (lo + hi)/2;
        MergeSort2(unsorted, lo, mi);
        MergeSort2(unsorted, mi+1, hi);
        Merge2(unsorted, lo, mi, hi);
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long sum=0;
	int n,m;
	cin>>n>>m;
	BGS= new bridge[n];
	MTS =new material[m];
	sorted_bgs = new int[n];
	sorted_mts = new int[m];
	help= new int[m];

	for(int i=0;i<n;i++){
		cin>>BGS[i].pi>>BGS[i].vi;
		sorted_bgs[i]=i;
	}
	MergeSort(sorted_bgs,0,n-1); //«≈∞¥’’value≈≈–Ú

	for(int i=0;i<m;i++){
		cin>>MTS[i].hi>>MTS[i].di;
		sorted_mts[i]=i;
	}
	
	MergeSort2(sorted_mts,0,m-1); //≤ƒ¡œ∞¥’’cost≈≈–Ú
	
	int head=0;
	int lo;
	int hi;
	int mi;

	while(head<n){
		int cost=BGS[sorted_bgs[head]].pi;
		int value=BGS[sorted_bgs[head]].vi;
		lo=0;
		hi=m-1;
		mi=(lo+hi)/2;
		while(lo<hi){
			mi=(lo+hi)/2;
			if( cost<MTS[sorted_mts[mi]].hi) 
				lo=mi+1;
			else if( cost>MTS[sorted_mts[mi]].hi){
				hi=mi;
			}else{
			break;
			}
		}
		mi++;
		while(1){
			if(mi<=hi && MTS[sorted_mts[mi]].used==false && MTS[sorted_mts[mi]].di>=value && MTS[sorted_mts[mi]].hi>=cost )
				break;
			mi--;
		}
		sum+=MTS[sorted_mts[mi]].hi;
		MTS[sorted_mts[mi]].used=true;
		head++;
	}
	

	cout<<sum;
	//system("pause");

}


*/