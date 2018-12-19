#include<iostream>
using namespace std;

//边类型
class edge
{   
public :
	int end; 
	int profit; //记录了边的权重
    edge *next;
	edge(int n ,int profit):end(n),profit(profit){}
};


//节点类的实现
//包含：最大利润，对应的孩子，出度和入度，在数组中对应的下标，以及封装了添加孩子的操作

class vertex{
public:
	int max_profit;
	int max_son;
	int indegree;
	int outdegree;
	int index;
	edge* leap;
    edge* firstedge;

	vertex(){
		max_profit=0;
		indegree=outdegree=0;
		max_son=-1;
	}
	void add_son(int n,int pro){
		if(outdegree==0){
			firstedge=new edge(n,pro);
			leap=firstedge;
		}else{
			leap->next=new edge(n,pro);
			leap=leap->next;
		}
		outdegree++;
	}

};


//使用深度优先搜索
//在搜索回溯的同时，标记并返回：从这个节点出发能够获得的最大利润，记录对应的子孙

int DFS( vertex* g, vertex& v){
	
	if(v.max_profit==0){
		int temp_max=-1;
		int outdeg=0;
		for(edge* i = v.firstedge; outdeg<v.outdegree; i = i->next )
			{
				outdeg++;
				temp_max=DFS(g,g[i->end])+i->profit; 
				if(temp_max>v.max_profit ||( temp_max==v.max_profit && i->end<v.max_son )){ //考虑字典序
					v.max_profit=temp_max;//从这个节点出发能够获得的最大利润
					v.max_son=i->end;//对应的子孙
				}
			}
		return v.max_profit;
	}else{
		return v.max_profit; //如果已经计算过，避免重复的计算（动态规划）
	}
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	//scanf("%d %d ",&n,&m);
	cin>>n>>m;
	vertex* vertexs=new vertex[n](); //创建节点数组
	for(int i=0;i<n;i++){
		vertexs[i].index=i;
	}
	//读入数据
	for(int i=0;i<m;i++){
		int begin,end,data;
		//scanf("%d %d %d",&begin,&end,&data);
		cin>>begin>>end>>data;
		vertexs[begin-1].add_son(end-1,data);
		vertexs[end-1].indegree++;
	}
	
	int max=-1;
	int temp_max;
	int index=0;
	
	//对所有零入度的点都进行一次DFS
	for(int i=0;i<n;i++){
		if(vertexs[i].indegree==0){
			temp_max=DFS(vertexs,vertexs[i]);
			if (temp_max>max ||(temp_max==max && index>i)){
				max=temp_max;
				index=i;
			}

		}
	}

	//迭代输出
	cout<<max;
	/*
	do{
		index=vertexs[index].max_son;
		cout<<index+1<<" ";
	}
	while(vertexs[index].max_son!=-1);
	*/

return 0;
}
