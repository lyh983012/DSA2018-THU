#include<iostream>
using namespace std;

class k_v{

	public :
	long long key; //存储26进制的名字
	long long value; //出现的次数
	long long howlong;
	k_v* next; //如果冲突需要继续查找
	bool end;	//是否是该类的重点 
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
  			temp2=temp2*27+(long)(temp-'a'+1); //取27进制存储（防止出现0）
			howlong++;
			}

		index=temp2%29989; //直接取模作为hash函数
		thiskv=&kvs[index]; //`进入该类的入口

		bool oldword=false;
		while(thiskv->end!=true){
			if(thiskv->key==temp2){ //寻找是否冲突
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
		if(oldword==false){ //第一次碰到这个词，设置好键值对
			thiskv->end=false;
			thiskv->value=1;
			thiskv->howlong=howlong;
			thiskv->next=new k_v; //保证next一定有一个end点
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
		list[head]=(char)(max_all%27+'a'-1);  //通过存储的key还原出原本的单词
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

