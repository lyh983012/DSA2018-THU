/* students please write your program here */

#include <iostream>
#include <cmath>

using namespace std;

class Equation{
private:
    int _a, _b, _c;
	int jud(int a,int b,int c)
	{if (a==0)
			{if (b==0)
				{
					if (c==0)
						return 5;
					else 
						return 4;
				}
			else 
			 return 6;
             }
	else {
		if(b*b-4*a*c>0)
			return 1;
		else if(b*b-4*a*c==0)
			return 2;
		else if(b*b-4*a*c<0)
			return 3;
		}
	}
public:
    Equation(int a, int b, int c){
		_a=a;
		_b=b;
		_c=c;
    }
    void solve();
};

void Equation::solve(){
	int m=jud(_a,_b,_c);
	double x1,x2;
	cout<<m<<endl;
	switch (m)
	{
	case 1:
		x1=(-_b+sqrt(_b*_b-4*_a*_c))/(2*_a);
		x2=(-_b-sqrt(_b*_b-4*_a*_c))/(2*_a);
		if (_a>0)
		 printf("%.2f %.2f \n",x2,x1);
		else 
	     printf("%.2f %.2f \n",x1,x2);
		break;
    case 2:
		x1=-_b/(2*_a);
		 printf("%.2f",x1);
		break;
	case 6:
		x1=-(_c/_b);
		 printf("%.2f",x1);
		break;
	}
	}

int main(){

    int a, b, c;
    cin >> a >> b >> c;
    Equation tmp(a, b, c);
    tmp.solve();
	return 0;
}

