
/*#include<iostream>
using namespace std;



class edge
{   
public :
	char character; 
	int end;
    edge *next;
	edge(char n,int index ):character(n),end(index){}
};

class son_link
{
public :
	edge* leap;
    edge* firstedge;
};

class vertex{
public:
	int count;
	int outdegree;
	int index;
	bool is_end;
	char character;
	vertex* parent;
	son_link son_edges; 
	vertex(){
		count=0;outdegree=0;is_end=0;
	}
	void add_son(char n,int index){
		if(outdegree==0){
			son_edges.firstedge=new edge(n,index);
			son_edges.leap=son_edges.firstedge;
		}else{
			son_edges.leap->next=new edge(n,index);
			son_edges.leap=son_edges.leap->next;
		}
		outdegree++;
	}
	int no_son(char n)
	{
		int outdeg=0;
		for(edge* i = son_edges.firstedge; outdeg<outdegree; i = i->next )
			{
				outdeg++;
				if(n==i->character)
				{
					return i->end;
				}
		}
		return -1;
	}

};

class graph{

public:
	vertex* vertexs;
	graph(int n){
		vertexs=new vertex[n]();
		for(int i=0;i<n;i++){
		vertexs[i].index=i;
	}
	}
};

int max_all=0;
vertex* endv;
vertex startv;
vertex* tempv;

inline void DFS( graph& g, vertex& v){

	int outdeg=0;
	for(edge* i = v.son_edges.firstedge; outdeg<v.outdegree; i = i->next ){
		outdeg++;
		DFS(g,g.vertexs[i->end]);
	}
	if(v.is_end==1){
		cout<<"index "<<v.index<<endl;
		if(v.count>=max_all){
			endv=&v;
			max_all=v.count;
	}
}}


int main(){
	
	int n;
	scanf("%d",&n);
	char temp;
	graph* TSP=new graph(8*10000);
	startv=TSP->vertexs[0];
	int head=0;
	getchar();
	for(int i=1;i<=n;i++){
		tempv=&startv;
		while ((temp = getchar()) != '\n'){
			//cout<<temp<<"test"<<i<<endl;
			int end=tempv->no_son(temp);
			if(end==-1){			//can not find char in the son of tempv
				head++;
				tempv->add_son(temp,head);
				TSP->vertexs[head].parent=tempv;
				TSP->vertexs[head].character=temp;
				tempv=&TSP->vertexs[head];
			}else{ 
				tempv=&TSP->vertexs[end];
			}
		}
		tempv->count++;
		tempv->is_end=true;;
	}
	
	DFS(*TSP,TSP->vertexs[0]);
	char* list=new char[8];

	for(int i=0;i<=head;i++){
		vertex t=TSP->vertexs[i];
		cout<<t.character<<"  outdegree= "<<t.outdegree<<" is end?= "<<t.is_end<<endl;
	}
	head=0;
	while(endv->index!=0){
		list[head]=endv->character;
		head++;
		endv=endv->parent;
	}
	for(int i=head-1;i>=0;i--){
		printf("%d",list[i]);
	}
	printf(" %d",max_all);

	system("pause");
return 0;

}

*/