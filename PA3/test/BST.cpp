#include<iostream>
using namespace std;

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
			v->num=succ->num;
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
	void test(node* v){
		cout<<"data="<<v->data<<"num"<<v->num<<endl;
		if(v->lc!=NULL || v->rc!=NULL){
			if(v->lc!=NULL ){
				cout<<"to lc=>"<<endl;
				test(v->lc);
			}
			if(v->rc!=NULL ){
				cout<<"to rc=>"<<endl;
				test(v->rc);
			}
			return;
		}else{
			return;
		}
	}

};
	
node* nodes =new node[100]();
int main(){
	int n,m,head;
	BSTree* bst = new BSTree();
	bst->root=new node(0);
	head=0;
	while(1){
		cin>>n>>m;
		nodes[head].data=m;
		if(n==0){
			node* temp=bst->root;
			bst->search(n,temp);
		}
		if(n==1){
			bst->insert(m);
			node* temp=bst->root;
			bst->test(temp);

		}if(n==2){
			bst->delnode(m);
			node* temp=bst->root;
			bst->test(temp);
		}
	}
}
