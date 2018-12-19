#include<iostream>
using namespace std;

//������
class edge
{   
public :
	int end; 
	int profit; //��¼�˱ߵ�Ȩ��
    edge *next;
	edge(int n ,int profit):end(n),profit(profit){}
};


//�ڵ����ʵ��
//������������󣬶�Ӧ�ĺ��ӣ����Ⱥ���ȣ��������ж�Ӧ���±꣬�Լ���װ����Ӻ��ӵĲ���

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


//ʹ�������������
//���������ݵ�ͬʱ����ǲ����أ�������ڵ�����ܹ���õ�������󣬼�¼��Ӧ������

int DFS( vertex* g, vertex& v){
	
	if(v.max_profit==0){
		int temp_max=-1;
		int outdeg=0;
		for(edge* i = v.firstedge; outdeg<v.outdegree; i = i->next )
			{
				outdeg++;
				temp_max=DFS(g,g[i->end])+i->profit; 
				if(temp_max>v.max_profit ||( temp_max==v.max_profit && i->end<v.max_son )){ //�����ֵ���
					v.max_profit=temp_max;//������ڵ�����ܹ���õ��������
					v.max_son=i->end;//��Ӧ������
				}
			}
		return v.max_profit;
	}else{
		return v.max_profit; //����Ѿ�������������ظ��ļ��㣨��̬�滮��
	}
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	//scanf("%d %d ",&n,&m);
	cin>>n>>m;
	vertex* vertexs=new vertex[n](); //�����ڵ�����
	for(int i=0;i<n;i++){
		vertexs[i].index=i;
	}
	//��������
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
	
	//����������ȵĵ㶼����һ��DFS
	for(int i=0;i<n;i++){
		if(vertexs[i].indegree==0){
			temp_max=DFS(vertexs,vertexs[i]);
			if (temp_max>max ||(temp_max==max && index>i)){
				max=temp_max;
				index=i;
			}

		}
	}

	//�������
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
