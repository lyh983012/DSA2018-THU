/*
#include <stdio.h>
#include <iostream>
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


//节点对象，存储出度，是否是终点，节点的亲节点，有向邻接表，以及以此节点作结尾的字符串个数count
class vertex{
public:
	int count;
	int outdegree;
	int index;
	
	bool is_end;
	char character;
	vertex* parent;
	edge* leap;
    edge* firstedge;

	vertex(){
		count=0;outdegree=0;is_end=0;
	}

	//加入新的节点到son节点中
	void add_son(char n,int index){
		if(outdegree==0){
			firstedge=new edge(n,index);
			leap=firstedge;
		}else{
			leap->next=new edge(n,index);
			leap=leap->next;
		}
		outdegree++;
	}

	//判断是否是一个新的子节点
	int no_son(char n)
	{
		int outdeg=0;
		for(edge* i = firstedge; outdeg<outdegree; i = i->next )
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

	ios::sync_with_stdio(false);
	cin.tie(0);
	vertex* endv;
	vertex* startv;
	vertex* tempv;
	vertex* vertexs=new vertex[8*10000];   //直接申请一个80000的字典树，用数组存储节点
	startv=&vertexs[0];
	endv=&vertexs[1];
	int max_all=0;
	int n;
	char temp[9];
	cin>>n;
	int head=0;
	int count1=0;

	for(int i=1;i<=n;i++){
		tempv=startv;
		scanf("%s",temp);
		count1=0;
		while ( temp[count1] != '\0'){
			int aim=tempv->no_son(temp[count1]);	//判断读入的字符是否是在已有的序列中的
			if(aim==-1){	
				head++;	                   //如果不是，见证一个孩子的诞生
				vertexs[head].index=head;
				tempv->add_son(temp[count1],head); 
				vertexs[head].parent=tempv;
				vertexs[head].character=temp[count1];
				tempv=&vertexs[head];
			}else{ 
				tempv=&vertexs[aim];      //否则直接进入这个分支继续判断
			}
			count1++;
		}
		tempv->count++;
		tempv->is_end=true;
		if(tempv->count>max_all){
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
		cout<<list[i];
	}
		cout<<" "<<max_all;
return 0;

}

*/

