/*#include<iostream>
using namespace std;

class point{
public:
	int data;
	point* next;
	point(int a){data=a;}
}
;

class link{
public:
	point* head;
	point* temp;
	int capacity;
	int len;

	link(int m){capacity=m;len=0;head=NULL;}
	int into(int data){
		if(len<capacity){
			temp=new point(data);
			temp->next=head;
			head=temp;
			len++;
			return 0;
		}else{
			return -1;
		}

	}

	int out(){
		if (len>0){
			temp=head;
			head=head->next;
			len--;
			return temp->data;}
		else{
			return -1;
		}
	}
	
	int get_head(){
		if (len>0)
			return head->data;
		else return -1;
		}
};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	link mylink(m);
	int* seq=new int[n];
	for(int i=1;i<=n;i++)
		scanf("%d %d",&seq[i]);
	int pointer=0;
	int wait=1;
	while(pointer<n)
	{
		if (seq[pointer]==wait){
			printf("%d %C",seq[pointer],'P');
			pointer++;
			wait++;
			continue;
		}else if(seq[pointer]<wait){
			if(seq[pointer]==mylink.get_head()){
				printf("%d %C",seq[pointer],'O');
				pointer++;
				mylink.out();
			}else{


	
	}
	}


}
*/