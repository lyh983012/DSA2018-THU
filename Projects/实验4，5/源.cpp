
#include"computer.h"
#include<iostream>


using namespace std;

int main()
{
int n;
cin>>n;

switch(n)
{
	case 1:
	cout<<"Ö´ÐÐÊµÑé4";
	n=1;
	COMPUTER ALIEN(P1,1,2);
	while(n)
	{
	ALIEN.CPU1.run();
	Sleep(5000);
	if (ALIEN.CPU1.frequency+rand()%10>21)
	ALIEN.CPU1.stop();
	else 
	cout<<"ok now we are working, so you can type in another number to examinate our computer`s stability;";
	cin>>n;
	}
	
	case 2:
}
