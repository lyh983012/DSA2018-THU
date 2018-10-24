#include<iostream>
using namespace std;

class CLIENT
{
public:
	static char ServerName;
	static int ClientNum;

	static void ChangeServerName()
	{cin>>ServerName;}
	static void getname()
	{cout<<ServerName;}
	~CLIENT(){cout<<"one of our computer sign out";}
};

 char CLIENT::ServerName= 'o';
 int CLIENT::ClientNum=0;

