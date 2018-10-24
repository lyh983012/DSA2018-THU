#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char text[4096];
	int count[26] ={0};
	int i =0;
	gets(text);
	while(text[i]!='\0')
	{
		if ((int)'a'<=(int)text[i] && (int)text[i]<=(int)'z')
			count[(int)text[i]-(int)'a']+=1;
		if ((int)'A'<=(int)text[i]&& (int)text[i]<=(int)'Z')
			count[(int)text[i]-(int)'A']+=1;
		i++;
	}
	for (int i=0;i<=25;i++)
		if (count[i]!=0)
			cout<<(char)((int)'A'+i)<<": "<<count[i]<<endl;
	//system("pause");
	return 0;
}	