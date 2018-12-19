/*
#include<iostream>

using namespace std;

class material{

public:
	int height;
	material* parent;
	material* lc;
	material* rc;
	int hi,di;
	int ubfactor; //defined == lc.height-rc.height
	material(){
		lc=NULL;
		rc=NULL;
		parent=NULL;
	}
};

class BSTree{

public:
	material* head;
	material* _hot;
	int _size;

	void update(material* v){
		if(v->lc!=NULL && v->rc!=NULL ){
			int lh=v->lc->height;
			int rh=v->rc->height;
			v->ubfactor = lh-rh;
			int temp=lh>rh? lh+1:rh+1;
			if(temp>v->height){
				v->height=temp;
			}else{return;}
		}else{
			if(v->lc==NULL && v->rc==NULL){
				v->ubfactor=0;
				v->height=1;
			}else{
				if(v->lc==NULL){
					v->height=v->rc->height+1;
					v->ubfactor=-v->height;
				}else{
					v->height=v->lc->height+1;
					v->ubfactor=v->height;
				}
			}
		}
		if(v!=head)
			update(v->parent);
		else return;
	}

	material* search(int key,material* v){
		if(v==NULL || v->hi==key){
			if(v==head)
				_hot=NULL;
			return v; 
		}else if(v->hi>key){  
			_hot=v;
			return search(key,v->lc);
		}else{
			_hot=v;
			return search(key,v->rc);
		}	
	}

	void remove(int key){
		material*  succ;		
		material* v=search(key,head); //start at head
		if(v==NULL){
			return;
		}else if(v->lc==NULL && v->rc==NULL){//if both of its child are null		
			if(v==head){
				head=NULL;
				return;
			}
			if(_hot->rc == v)
				_hot->rc=NULL;
			else
				_hot->lc=NULL;
			update(_hot);
			return;
		}else if(v->lc==NULL || v->rc==NULL){	 //if one of its child is null				
			if(v->lc==NULL){
				succ=v->rc;		 //lc is null 
			}else if(v->rc ==NULL){
				succ=v->lc;		 //rc is null
			}
			succ->parent=_hot;	
			if(v==head){
				head=succ;
				update(succ);
				return;
			}
			if(_hot->lc=v)		 //updata parent`s son
				_hot->lc=succ;
			else
				_hot->rc=succ;
			update(succ);
			return;
		}else{									//if none of its child is null		
			if(v!=head){
				succ=v->rc; 
				while(succ->lc!=NULL){
					succ=succ->lc;
				}	
				material* succ_succ=succ->rc;
				material* succ_hot=succ->parent;
				if(_hot->lc=v)_hot->lc=succ;
				else _hot->rc=succ;
				succ->parent=_hot;
				if(v->rc!=succ){
					succ->rc=v->rc;
					succ->rc->parent=succ;
				}else succ->rc=NULL;
				if(v->lc!=succ){
					succ->lc=v->lc;
					succ->lc->parent=succ;
				}else succ->lc=NULL;
				if(succ_succ!=NULL){
					succ_hot->lc=succ_succ;
					succ_succ->parent=succ_hot;
					update(succ_succ);
				}else update(succ_hot);

			}else if(v==head){
				succ=v->rc; 
				while(succ->lc!=NULL){
					succ=succ->lc;
				}	
				material* succ_succ=succ->rc;
				material* succ_hot=succ->parent;
				succ->parent=_hot;
				head=succ;
				if(v->rc!=succ){
					succ->rc=v->rc;
					succ->rc->parent=succ;
				}else succ->rc=NULL;
				if(v->lc!=succ){
					succ->lc=v->lc;
					succ->lc->parent=succ;
				}else succ->lc=NULL;
				if(succ_succ!=NULL ){
					succ_hot->lc=succ_succ;
					succ_succ->parent=succ_hot;
					update(succ_succ);
				}else{
					update(succ_hot);
				}
			}
		}
		_size--;
		return;
	}

	void insert(material* v){

		material* insert_place=search(v->hi,head);
		if ( insert_place==NULL){
			v->parent=_hot;
			if(v->hi>_hot->hi)
				_hot->rc=v;
			else
				_hot->lc=v;
			_size++;
			update(v);
		}
		return;
	}

	void test(material* v){
		cout<<"hi="<<v->hi<<"di="<<v->di<<" height= "<<v->height<<endl;
		if(v->lc!=NULL || v->rc!=NULL){
			if(v->lc!=NULL ){
				test(v->lc);
			}
			if(v->rc!=NULL ){
				test(v->rc);
			}
			return;
		}else{
			return;
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,n;
	cin>>m;
	BSTree BST;
	material* MTS =new material[m];
	int i=0;
	cin>>MTS[i].hi>>MTS[i].di;
	MTS[i].height=1;
	MTS[i].ubfactor=0;
	BST.head=&MTS[0];
	BST._size=1;
	while(1){
		cout<<"please input common"<<endl;
		cin>>n;
		if(n==1 && i<m){
			cout<<"insert"<<endl;
			i++;
			cin>>MTS[i].hi>>MTS[i].di;
			BST.insert(&MTS[i]);
			BST.test(BST.head);
		}else if(n==2 && i<m){
			cout<<"delete"<<endl;
			cin>>n;
			BST.remove(n);
			BST.test(BST.head);
		}
	}
	system("pause");
}

*/