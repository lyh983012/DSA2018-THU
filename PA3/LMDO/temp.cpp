/*
#include <stdio.h>
#include <iostream>
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


//�ڵ���󣬴洢���ȣ��Ƿ����յ㣬�ڵ���׽ڵ㣬�����ڽӱ��Լ��Դ˽ڵ�����β���ַ�������count
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

	//�����µĽڵ㵽son�ڵ���
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

	//�ж��Ƿ���һ���µ��ӽڵ�
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
	vertex* vertexs=new vertex[8*10000];   //ֱ������һ��80000���ֵ�����������洢�ڵ�
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
			int aim=tempv->no_son(temp[count1]);	//�ж϶�����ַ��Ƿ��������е������е�
			if(aim==-1){	
				head++;	                   //������ǣ���֤һ�����ӵĵ���
				vertexs[head].index=head;
				tempv->add_son(temp[count1],head); 
				vertexs[head].parent=tempv;
				vertexs[head].character=temp[count1];
				tempv=&vertexs[head];
			}else{ 
				tempv=&vertexs[aim];      //����ֱ�ӽ��������֧�����ж�
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
		list[head]=endv->character; //���ݸ��ӹ�ϵѰ������
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

