#include<iostream>
using namespace std;
#define capacity 39997

class k_v{

	public :
	char* word;
	int key;
	int value; 
	k_v* next; 
	bool end;	
	k_v(){
		end=true;
		
	}
};

int* leap;

bool check(char* word,char* temps,int n){

		int index=0,len=-1;
		int j=0,i=0;
		while(i<n){
			if(j==-1 || word[i]==temps[j]){
				j+=1;i+=1;
				if(j==n)
					return true;
			}else{
				while(index<j+1){
					if(len==-1 || temps[index]==temps[len]){
							++index,++len;
							leap[index]=len;
						}else{
							len=leap[len];
						}
					}
				j=leap[j];
			}	
		}
		while(i>=n && i<2*n){
			if(word[i-n]==temps[j]){
				i+=1;j+=1;
				if(j==n){
					return true;
				}
			}else{
				return false;
			}
		}
		return false;
	}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	leap=new int[n];
	k_v* kvs=new k_v[capacity]();
	k_v* thiskv;
	char* temps=new char[n+1];
	int temp2=0;
	int index=0;
	bool oldword;
	leap[0]=-1;

	for(int i=1;i<m+1;i++){
		for(int t=0;t<n;t++){
			cin>>temps[t];
  			temp2+=(temps[t]-'a'+10)*(temps[t]-'a'+10);
		}
		index=temp2%capacity; 
		thiskv=&kvs[index]; 
		oldword=false;
		while(thiskv->end!=true){
			if(thiskv->key==temp2 && check(thiskv->word,temps,n)){//double check
				oldword=true;
				cout<<thiskv->value<<endl;
				break;
			}else{
				thiskv=thiskv->next;
			}
		}
		if(oldword==false){ 
			thiskv->end=false;
			thiskv->value=i;
			thiskv->key=temp2;
			thiskv->next=new k_v();
			thiskv->word=new char[n];
			for(int j=0;j<n;j++){
				thiskv->word[j]=temps[j];
			}
			cout<<0<<endl;
		}
		temp2=0;
	}
return 0;
}

