/*
#include<iostream>
using namespace std;
typedef unsigned short us;

//邻接表的边对象
class edge
{   
public :
	char character; 
	int end;
    edge *next;
	edge(char n,int index ):character(n),end(index){}
};

//邻接表对象
class son_link
{
public :
	edge* leap;
    edge* firstedge;
};

//节点对象，存储出度，是否是终点，节点的亲节点，有向邻接表，以及以此节点作结尾的字符串个数count
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

	//加入新的节点到son节点中
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

	//判断是否是一个新的子节点
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


int main(){


vertex* endv;
vertex* startv;
vertex* tempv;

	int max_all=0;
	int n;
	scanf("%d",&n);
	char temp;

	vertex* vertexs=new vertex[8*10000];   //直接申请一个80000的字典树，用数组存储节点
	startv=&vertexs[0];
	int head=0;
	getchar();//读掉讨厌的换行符

	//每一个词查询是否在字典中，有的话count++，没有的话添加进字典
	for(int i=1;i<=n;i++){
		tempv=startv;
		while ( (temp = getchar()) != '\n'){
			int aim=tempv->no_son(temp);	//判断读入的字符是否是在已有的序列中的
			if(aim==-1){	
				head++;	                   //如果不是，见证一个孩子的诞生
				vertexs[head].index=head;
				tempv->add_son(temp,head); 
				vertexs[head].parent=tempv;
				vertexs[head].character=temp;
				tempv=&vertexs[head];
			}else{ 
				tempv=&vertexs[aim];      //否则直接进入这个分支继续判断
			}
		}
		tempv->count++;
		tempv->is_end=true;
		if(tempv->count>=max_all){
			endv=tempv;
			max_all=tempv->count;
		}	 
    }
	char* list=new char[8];

    head=0;
	while(endv->index!=0){
		list[head]=endv->character; //根据父子关系寻找祖宗
		head++;
		endv=endv->parent;
	}
	for(int i=head-1;i>=0;i--){
		printf("%c",list[i]);
	}
		printf(" %d",max_all);

return 0;

}

*/