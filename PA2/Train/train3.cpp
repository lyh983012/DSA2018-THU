#include<iostream>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); �ҷ���cin cout���̫���ˣ����û���ã���ʦ�ܲ��ܽ�һ�°�
	int n,m;
	scanf("%d%d",&n,&m);
	int* seq = (int*)malloc(sizeof(int) * (n+1));//���ڴ��һ�����ܵ�����
	int* zhan= (int*)malloc(sizeof(int) * (m+1));//һ��ջ 
	int pointer=0;//���������ڵȴ�������λ
	int head=-1;//ջ���ȴ�������λ
	int flag=0;
	
	scanf("%d",&seq[pointer]);
	for (int wait=1;wait<=n;){//���������ڵȴ��Ƚϵ�һλ����μ�����������
		if (seq[pointer]==wait){
			wait++;
			pointer++;
			scanf("%d",&seq[pointer]);
		}else if(head>=0 && wait==zhan[head]){//����Ƿ��ջ
				wait++;
				head--;
		}else{
			zhan[++head]=seq[pointer];
			if(head>0 && zhan[head]>zhan[head-1]){//���ջ�ڲ��������˳�
				flag=1;break;}
			if (head>=m){//������������ˣ��˳�
				flag=1;break;}
			pointer++;
			scanf("%d",&seq[pointer]);
			}
		}
	if(flag==1){
		printf("No");
		return 0;
	}

	pointer=0;//���¸�������ֵ��Ȼ������һ�飬���ֱ��������
	head=-1;

	for (int wait=1;wait<=n;){//���������ڵȴ�����һλ
		if (seq[pointer]==wait){
			printf("%d P\n",seq[pointer]);
			pointer++;
			wait++;
		}else if(head>=0 && wait==zhan[head]){//����Ƿ��ջ
			printf("%d O\n",wait);
			wait++;
			head--;
		}else{
			zhan[++head]=seq[pointer];
			printf("%d I\n",seq[pointer]);
			pointer++;
			}
	}
		//system("pause");
	return 0;
}


