/*#include<iostream>
using namespace std;

class material{

public:
	material* parent;
	material* lc;
	material* rc;
	int hi,di;
	material(){
		lc=NULL;
		rc=NULL;
		parent=NULL;
	}
};

material* PARENT=new material();

class BSTree{

public:
	material* head;
	material* _hot;	
	material* search(int key,material* v){
		if(v==NULL){
			return _hot; 
		}else if( v->hi==key){
			return v; 
		}else if(v->hi>=key){  
			_hot=v;
			return search(key,v->lc);
		}else if(v->hi<key)
			_hot=v;
			return search(key,v->rc);
		}	
	material* search2(int key,material* v){
		if(v==NULL){
			return _hot; 
		}else if(v->hi>=key){  
			_hot=v;
			return search(key,v->lc);
		}else if(v->hi<key)
			return search(key,v->rc);
		}	
	

	void remove(material* v){
		material* succ;	
		_hot=v->parent;
		 if(!v)
			return;
		 if(!v->lc){
			if(_hot->lc=v){
				_hot->lc=v->rc;
				if(v->rc)
					v->rc->parent=_hot;
				if(v==head){
					head=v->rc;
					PARENT->rc=v->rc;
					PARENT->lc=v->rc;
				}
			}else {
				_hot->rc=v->rc;
				if(v->rc)
					v->rc->parent=_hot;
				if(v==head){
					head=v->rc;
					PARENT->rc=v->rc;
					PARENT->lc=v->rc;
				}
			}
		 }else if(!v->rc){
			if(_hot->lc=v){
				_hot->lc=v->lc;
				if(v->lc)
					v->lc->parent=_hot;
				if(v==head){
					head=v->lc;
					PARENT->rc=v->lc;
					PARENT->lc=v->lc;
				}
			 }else {
				_hot->rc=v->lc;
				if(v->lc)
					v->lc->parent=_hot;
				if(v==head){
					head=v->lc;
					PARENT->rc=v->lc;
					PARENT->lc=v->lc;
				}
			}
		}else
		{
			succ=v->rc;
			while(succ->lc!=NULL)
				succ=succ->lc;
			v->di=succ->di;
			v->hi=succ->hi;
			remove(succ);
		}
		return;
	}

	void insert(material* v){
		material* insert_place=search(v->hi,head);
		if(v->hi>insert_place->hi){
			v->parent=insert_place;
			insert_place->rc=v;
		}else if(v->hi<insert_place->hi){
			v->parent=insert_place;
			insert_place->lc=v;
		}else{
			if(v->di<insert_place->di){
				v->parent=insert_place;
				insert_place->lc=v;
			}else {
				v->parent=insert_place;
				insert_place->rc=v;
			}
		}	
		return;
	}

};



struct node{
	int data;
	node* lchild;
	node* rchild;
};
 
node* newNode(int v){
	node* Node = new node;
	Node -> data = v;
	Node -> lchild = Node -> rchild = NULL;
	return Node;
}
 
void insert(node* &root,int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x == root -> data){
		return;
	}else if(x < root -> data){
		insert(root -> lchild,x);
	}else{
		insert(root -> rchild,x);
	}
}
 
node* Create(int data[],int n){
	node* root = NULL;
	for(int i = 0;i < n;i++){
		insert(root,data[i]);
	}
	return root;
}
 
node* findMax(node* root){
	while(root -> rchild != NULL){
		root = root -> rchild;
	}
	return root;
}
 
node* findMin(node* root){
	while(root -> lchild != NULL){
		root = root -> lchild;
	}
	return root;
}
 
void deleteNode(node* &root,int x){
	if(root == NULL) return;
	if(root -> data == x){
		if(root -> lchild == NULL && root -> rchild == NULL){
			root = NULL;
		}else if(root -> lchild != NULL){
			node* pre = findMax(root -> lchild);
			root -> data = pre -> data;
			deleteNode(root -> lchild,pre -> data);
		}else{
			node* post = findMin(root -> rchild);
			root -> data = post -> data;
			deleteNode(root -> rchild,post -> data);
		}
	}else if(root -> data > x){
		deleteNode(root -> lchild,x);
	}else
		deleteNode(root -> rchild,x);
}



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
//merge in cost [for material]
void Merge2( int*  unsorted,int lo,int mi,int hi){

	int head1=lo;
	int head2=mi+1;
	int head=lo;
	while(head1<=mi || head2<= hi){
		if(head1<=mi && head2<= hi){
			if( MTS[unsorted[head1]].di> MTS[unsorted[head2]].di){
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
	BSTree* BST= new BSTree();
	BST->head=&MTS[sorted_mts[0]];
	
	
	PARENT->lc=BST->head;
	PARENT->rc=BST->head;
	PARENT->hi=0;
	PARENT->di=0;
	BST->head->parent=PARENT;

	int head_for_br=0;
	int head_for_mt=0;
	long long sum=0;

	while(head_for_br<n){
		int cost=BGS[sorted_bgs[head_for_br]].pi;
		int value=BGS[sorted_bgs[head_for_br]].vi;
		while(head_for_mt<m && MTS[sorted_mts[head_for_mt]].di>=value){
			BST->insert(&MTS[sorted_mts[head_for_mt]]);
			head_for_mt++;
		}
		material* v=BST->search2(cost,BST->head);
		sum+=v->hi;
		head_for_br++;
		BST->remove(v);
	}
	cout<<sum;

	return 0 ;
}*/