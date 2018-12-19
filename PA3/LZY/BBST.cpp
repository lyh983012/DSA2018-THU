#include<iostream>
using namespace std;

class material{
public:
	int hi,di;
};

class node{
public:
	node* parent;
	node* lc;
	node* rc;
	int data;
	int num;
	node(int dat){
		data=dat;
		lc=NULL;
		rc=NULL;
		parent=NULL;
		num=1;
	}
	node(){
		data=0;
		lc=NULL;
		rc=NULL;
		parent=NULL;
		num=1;
	}
};

class BSTree{

public:
	node* root;
	node* _hot;
	int _size;
	
	BSTree(){
		_size=1;
	}
	//return the materials "insert" need
	node* search(int key,node* v){
		_hot=NULL;
		while(!(v==NULL || v->data==key)){
			_hot=v;
			 if(v->data>key){  
				v=v->lc;
			 }else{
				v=v->rc;
			}
		}
		return v; 
	}

	//return the materials we need
	node* search2(int key,node* v){
		while(!v==NULL){
			 if(v->data>=key){  
				_hot=v;
				v=v->lc;
			 }else{
				v=v->rc;
			}
		}
			return _hot;
	}

	void insert(int key){
		if(_size==0){
			root=new node(key);
			_size++;
			return;
		}
		_size++;
		node* aim=search(key,root);
		node* v=new node(key);
		if ( aim==NULL){
			v->parent=_hot;
			if(v->data<_hot->data){
				_hot->lc=v;
			}
			else{
				_hot->rc=v;
			}
		}else{
			aim->num++;
		}
		return;
	}

	void remove(node* v){
		
		if(v->num>1){
			v->num--;
			return;
		}
		_hot=v->parent;
		if(!v->lc){//___________________________Type 1__________________
			if(v==root){
				if(v->rc)
					v->rc->parent=_hot;
				root=v->rc;
				return;
			}
			if(_hot->lc==v){
				_hot->lc=v->rc;
				if(v->rc)
					v->rc->parent=_hot;
			}else {
				_hot->rc=v->rc;
				if(v->rc)
					v->rc->parent=_hot;
			}
		 }else if(!v->rc){//___________________________Type 2__________________
			if(v==root){
				if(v->lc)
					v->lc->parent=_hot;
				root=v->lc;
				return;
			}
			if(_hot->lc==v){
				_hot->lc=v->lc;
				if(v->lc)
					v->lc->parent=_hot;
			}else {
				_hot->rc=v->lc;
				if(v->lc)
					v->lc->parent=_hot;
			}
		}else//___________________________Type 3__________________
		{		
			node* succ=v->rc;
			while(succ->lc!=NULL)
				succ=succ->lc;
			v->data=succ->data;
			//v->num=succ->num;
			remove(succ);
		}
		return;
	}

	int delnode(int key){
		node* v=search2(key,root);
		int temp=v->data;
		_size--;
		if(_size>0)
			remove(v);
		return temp;
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

//merge in value [for bridge]
void Merge( int*  unsorted,int lo,int mi,int hi){
	int head1=lo;
	int head2=mi+1;
	int head=lo;
	while(head1<=mi || head2<= hi){
		if(head1<=mi && head2<= hi){
			if( BGS[unsorted[head1]].vi>= BGS[unsorted[head2]].vi){
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
//merge in cost [for material]
void Merge2( int*  unsorted,int lo,int mi,int hi){
	int head1=lo;
	int head2=mi+1;
	int head=lo;
	while(head1<=mi || head2<= hi){
		if(head1<=mi && head2<= hi){
			if( MTS[unsorted[head1]].di>= MTS[unsorted[head2]].di){
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
	int n,m;
	cin>>n>>m;
	BGS= new bridge[n];
	MTS =new material[m];
	sorted_bgs = new int[n];
	sorted_mts = new int[m];
	help= new int[m];
//____________init____________________
	for(int i=0;i<n;i++){
		cin>>BGS[i].pi>>BGS[i].vi;
		sorted_bgs[i]=i;
	}
	MergeSort(sorted_bgs,0,n-1); 
	for(int i=0;i<m;i++){
		cin>>MTS[i].hi>>MTS[i].di;
		sorted_mts[i]=i;
	}
	MergeSort2(sorted_mts,0,m-1); 
//____________pre sort____________________
	BSTree* BST = new BSTree();
	int head_for_br=0;
	int head_for_mt=0;
	BST->root=new node(MTS[sorted_mts[head_for_mt++]].hi);
	long long sum=0;
	int temp;
	while(head_for_br<n){
		int cost=BGS[sorted_bgs[head_for_br]].pi;
		int value=BGS[sorted_bgs[head_for_br]].vi;
		while(head_for_mt<m && MTS[sorted_mts[head_for_mt]].di>=value){
			BST->insert(MTS[sorted_mts[head_for_mt]].hi);  //use all materials which value is big enough to construct a tree
			head_for_mt++;
		}
		temp=BST->delnode(cost);
		sum+=temp;
		head_for_br++;
	}
	cout<<sum;

}


