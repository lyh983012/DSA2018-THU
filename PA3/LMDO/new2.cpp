/*
#include<iostream>
using namespace std;
typedef unsigned short us;

//�ڽӱ�ı߶���
class edge
{   
public :
	char character; 
	int end;
    edge *next;
	edge(char n,int index ):character(n),end(index){}
};

//�ڽӱ����
class son_link
{
public :
	edge* leap;
    edge* firstedge;
};

//�ڵ���󣬴洢���ȣ��Ƿ����յ㣬�ڵ���׽ڵ㣬�����ڽӱ��Լ��Դ˽ڵ�����β���ַ�������count
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

	//�����µĽڵ㵽son�ڵ���
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

	//�ж��Ƿ���һ���µ��ӽڵ�
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

	vertex* vertexs=new vertex[8*10000];   //ֱ������һ��80000���ֵ�����������洢�ڵ�
	startv=&vertexs[0];
	int head=0;
	getchar();//��������Ļ��з�

	//ÿһ���ʲ�ѯ�Ƿ����ֵ��У��еĻ�count++��û�еĻ���ӽ��ֵ�
	for(int i=1;i<=n;i++){
		tempv=startv;
		while ( (temp = getchar()) != '\n'){
			int aim=tempv->no_son(temp);	//�ж϶�����ַ��Ƿ��������е������е�
			if(aim==-1){	
				head++;	                   //������ǣ���֤һ�����ӵĵ���
				vertexs[head].index=head;
				tempv->add_son(temp,head); 
				vertexs[head].parent=tempv;
				vertexs[head].character=temp;
				tempv=&vertexs[head];
			}else{ 
				tempv=&vertexs[aim];      //����ֱ�ӽ��������֧�����ж�
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
		list[head]=endv->character; //���ݸ��ӹ�ϵѰ������
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