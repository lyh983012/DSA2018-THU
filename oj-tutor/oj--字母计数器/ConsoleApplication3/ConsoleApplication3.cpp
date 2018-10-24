#include<iostream>
#include<cctype>
#include<string.h>

using namespace std;
char a[10000];
char m;
int l,n;
int c[26]={0};
int main()
{
 cin.get(a,10000);;
 l=strlen(a);
 n=0;
 while (n<=25)
{for (int i=0;i<=l-1;i++)
 if (a[i]-'a'==n||a[i]-'A'==n) c[n]++;
 n++;}
 for (int i=0;i<=25;i++)
 {m='A'+i;
 if (c[i]!=0) cout<<m<<": "<<c[i]<<endl;
 }
  return 0;
 }

