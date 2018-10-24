#include<iostream>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); 我发现cin cout真的太慢了，真的没法用，老师能不能讲一下阿
	int n,m;
	scanf("%d%d",&n,&m);
	int* seq = (int*)malloc(sizeof(int) * (n+1));//用于存放一个可能的排序
	int* zhan= (int*)malloc(sizeof(int) * (m+1));//一个栈 
	int pointer=0;//无序列正在等待检查的那位
	int head=-1;//栈顶等待检查的那位
	int flag=0;
	
	scanf("%d",&seq[pointer]);
	for (int wait=1;wait<=n;){//有序列正在等待比较的一位，这次检查输出可行性
		if (seq[pointer]==wait){
			wait++;
			pointer++;
			scanf("%d",&seq[pointer]);
		}else if(head>=0 && wait==zhan[head]){//检查是否出栈
				wait++;
				head--;
		}else{
			zhan[++head]=seq[pointer];
			if(head>0 && zhan[head]>zhan[head-1]){//如果栈内不是逆序，退出
				flag=1;break;}
			if (head>=m){//如果超出容量了，退出
				flag=1;break;}
			pointer++;
			scanf("%d",&seq[pointer]);
			}
		}
	if(flag==1){
		printf("No");
		return 0;
	}

	pointer=0;//重新给参数赋值，然后再来一遍，这次直接输出结果
	head=-1;

	for (int wait=1;wait<=n;){//有序列正在等待检查的一位
		if (seq[pointer]==wait){
			printf("%d P\n",seq[pointer]);
			pointer++;
			wait++;
		}else if(head>=0 && wait==zhan[head]){//检查是否出栈
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


