#include<iostream>
using namespace std;

class k_v{

	public :
	long long key; //�洢26���Ƶ�����
	long long value; //���ֵĴ���
	long long howlong;
	k_v* next; //�����ͻ��Ҫ��������
	bool end;	//�Ƿ��Ǹ�����ص� 
	k_v(){
		end=true;
	}
};

int main(){

	k_v* kvs=new k_v[30000]();
	k_v* thiskv;
	k_v* max;

	long long max_all=0;
	long  n;
	scanf("%d",&n);

	char temp;
	long long temp2=0;
	long long index;
	long long howlong=0;
	getchar();
	for(int i=1;i<=n;i++){
		
		while ( (temp = getchar()) != '\n'){
  			temp2=temp2*27+(long)(temp-'a'+1); //ȡ27���ƴ洢����ֹ����0��
			howlong++;
			}

		index=temp2%29989; //ֱ��ȡģ��Ϊhash����
		thiskv=&kvs[index]; //`�����������

		bool oldword=false;
		while(thiskv->end!=true){
			if(thiskv->key==temp2){ //Ѱ���Ƿ��ͻ
				thiskv->value++;
				oldword=true;
				if(thiskv->value>max_all){
					max_all=thiskv->value;
					max=thiskv;
				}
				break;
			}else{
				thiskv=thiskv->next;
			}
		}
		if(oldword==false){ //��һ����������ʣ����úü�ֵ��
			thiskv->end=false;
			thiskv->value=1;
			thiskv->howlong=howlong;
			thiskv->next=new k_v; //��֤nextһ����һ��end��
			thiskv->key=temp2;
			if(thiskv->value>max_all){
				max_all=thiskv->value;
				max=thiskv;
				}
		}
		howlong=0;
		temp2=0;
	}

	long long head=0;
	char* list=new char[8];

	max_all=max->key;

	for(int i=0;i<max->howlong;i++){
		list[head]=(char)(max_all%27+'a'-1);  //ͨ���洢��key��ԭ��ԭ���ĵ���
		max_all/=27;
		head++;
	}

	for(int i=head-1;i>=0;i--){
		printf("%c",list[i]);
	}
		printf(" %d",max->value);
	//system("pause");
return 0;

}

