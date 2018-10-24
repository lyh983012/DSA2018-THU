#include"vector.h"
#include<iostream>
#include"stdio.h"
#include"time.h"

using namespace std;


int main()
{
vector<int> hei;
for(int i=0;i<=30;i++)
	{
	hei.insert(i,rand());
	cout<<"_size="<<hei.size()<<"_capacity="<<hei.capacity()<<endl;
	}

for(int i=0;i<=hei.size()-1;i++)
	cout<<hei[i]<<" ";

hei.bubsort();
cout<<endl<<"sorted"<<endl;
for(int i=0;i<=hei.size()-1;i++)
	cout<<hei[i]<<" ";
system("pause");
return 0;
}

