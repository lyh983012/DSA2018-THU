#include<iostream>
using namespace std;

class point{

public:
	long long data;
	long long count;
	point(long long a,long long b){
		data=a;
		count=b;
	}
	point(){
		data=0;
		count=0;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	long long * queap= new long long  [n];
	point* max_queap= new point[n]();
	long long  hi,lo;
	int count,plo,phi,index;
	char temp[2];
	
	count=0;
	hi=0,lo=0;
	phi=0,plo=0;

	for(int i=0;i<n;i++){
		scanf("%s",&temp);
		switch(temp[0]){
			case 'E':{
				scanf("%ld",&queap[hi]);
				hi++;	
				if(plo<phi){
					count=0;
					index=phi-1;
					while(index>=plo){
						if(max_queap[index].data<queap[hi-1]){
							count+=max_queap[index].count;
							index--;
							if(index==plo-1){
								phi=plo+1;
								max_queap[plo].count=count+1;
								max_queap[plo].data=queap[hi-1];
								break;
							}
						}else if(max_queap[index].data==queap[hi-1]){
							max_queap[index].count+=(count+1);
							phi=index+1;
							break;
						}else if(max_queap[index].data>queap[hi-1]){
							max_queap[index+1].data=queap[hi-1];
							max_queap[index+1].count=count+1;
							phi=index+2;
							break;
						}
					}
				}else{
					max_queap[plo].data=queap[hi-1];
					max_queap[plo].count=1;
					phi++;
				}
				printf("%ld\n",max_queap[plo].data*(hi-lo));
				break;
			}
			case 'D':{
				if(lo<hi){
					lo++;
					max_queap[plo].count--;
					if(max_queap[plo].count>0){
						printf("%ld\n",max_queap[plo].data*(hi-lo));
						break;
					}else if(max_queap[plo].count==0 && phi-plo>1){
						plo++;
						printf("%ld\n",max_queap[plo].data*(hi-lo));
						break;
					}else if(max_queap[plo].count==0 && phi-plo==1){
						count=0;
						printf("%d\n",count);
						plo++;
						break;
					}
				}else{
					count=0;
					printf("%d\n",count);
				}
				break;
				}
			}
		}
	return 0;
}
