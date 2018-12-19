/*
#include<iostream>
using namespace std;

class edge
{   
public :
	int end; 
	int profit;
    edge *next;
	edge(int n ,int profit):end(n),profit(profit){}
};

class adj_link
{
public :
	edge* leap;
    edge* firstedge;
};

class vertex{
public:
	int max_profit;
	char status;//1=visited 2=discovered 3=undiscovered
	int indegree;
	int outdegree;
	int index;
	adj_link son_edges;

	vertex(){
		max_profit=0;status=3;
		indegree=outdegree=0;
	}
	void add_son(int n,int pro){
		if(outdegree==0){
			son_edges.firstedge=new edge(n,pro);
			son_edges.leap=son_edges.firstedge;
		}else{
			son_edges.leap->next=new edge(n,pro);
			son_edges.leap=son_edges.leap->next;
		}
		outdegree++;
	}
	void add_parent(int n,int pro){
		indegree++;
	}

};

class graph{

public:
	int time;
	vertex* vertexs;
	graph(int n,int m){
		vertexs=new vertex[n]();
		for(int i=0;i<n;i++){
		vertexs[i].index=i;
	}
	}
};


inline int print_DFS( graph& g, vertex& v){
	
	if(v.max_profit>0){
		return v.max_profit;
	}else{
		v.status=2;	//discovered
		int temp_max=-1;
		int outdeg=0;
		for(edge* i = v.son_edges.firstedge; outdeg<v.outdegree; i = i->next )
			{
				outdeg++;
				temp_max=print_DFS(g,g.vertexs[i->end])+i->profit;
				if(temp_max>v.max_profit){
					v.max_profit=temp_max;
				}
			}
		v.status=1;	//visited
		return v.max_profit;
	}
}

void print_path(graph& g, vertex& v,int* list,int& head){
	
		list[head]=v.index+1;
		head++;
		if(v.outdegree==0)
			return;
		else{
		int temp_max=-1;
		int son_max=-1;
		int outdeg=0;
		int index=0;
		for(edge* i = v.son_edges.firstedge; outdeg<v.outdegree; i = i->next ){
				outdeg++;
				temp_max=g.vertexs[i->end].max_profit+i->profit;
				if(temp_max>son_max||(temp_max==son_max && index>i->end)){
					son_max=temp_max;
					index=i->end;
				}
			}
		print_path(g,g.vertexs[index],list, head );
		}
}



int main(){
	
	int n,m;
	scanf("%d %d ",&n,&m);
	graph* TSP=new graph(n+1,m+1);

	for(int i=0;i<m;i++){
		int begin,end,data;
		scanf("%d %d %d",&begin,&end,&data);
		end=end-1;
		begin=begin-1;
		TSP->vertexs[begin].add_son(end,data);
		TSP->vertexs[end].indegree++;
	}
	int max=-1;
	int temp_max;
	int index=0;


	for(int i=0;i<n;i++){
		if(TSP->vertexs[i].indegree==0){
			temp_max=print_DFS(*TSP,TSP->vertexs[i]);
			if (temp_max>max ||(temp_max==max && index>i)){
				max=temp_max;
				index=i;
			}

		}
	}

	int* list=new int[n];
	int head=0;

	print_path(*TSP,TSP->vertexs[index],list,head);

	for(int i=0;i<head;i++){
		printf("%d ",list[i]);
	}

	//system("pause");

return 0;
}

*/