
#include"link.h"
#include<cmath>
#include"time.h"
#define Random(x) (rand() % x) 
#define mapsize 40
#define PATERN "+"
#define FOOD "@"
//以下是蛇的具体实现

//mapstate 0--null 1--boody or wall 2--food 
class Map{

public:
	void printmap();
	int fx,fy;
	void clearwindows();
	void Map::gotoxy(int x,int y)
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = x;
    csbiInfo.dwCursorPosition.Y = y;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
//这个是抄的
	void generatefood();
	int Mapstate[mapsize/2][mapsize];
	Map()
	{
	for (int i=0;i<=mapsize/2-1;i++)
		for (int j=0;j<=mapsize-1;j++)
		Mapstate[i][j]=0;

	for (int i=0;i<=mapsize/2-1;i++)
	{
	Mapstate[i][0]=1;
	Mapstate[i][mapsize-1]=1;
	
	}
	for (int i=0;i<=mapsize-1;i++)
	{
	Mapstate[0][i]=1;
	Mapstate[mapsize/2-1][i]=1;
	}
	}
};

void Map::printmap()
{
	gotoxy(0,0);
	for (int i=0;i<=mapsize/2-1;i++)
{
	for (int j=0;j<=mapsize-1;j++)
	if (Mapstate[i][j]==0) cout<<" " ;else cout<<"#";;
	cout<<endl;
}
	}

void Map::generatefood()
{
	int x,y;
	srand(time(NULL));
	while(1)
	{
	y=Random(mapsize/2-2)+1;
	x=Random(mapsize-2)+1;
	if (Mapstate[y][x]==0)
	{
	fx=x,fy=y;
	Mapstate[y][x]=2;
	gotoxy(x,y);
	cout<< FOOD;
	return;
	}
	}
	

}

class Snake:public Map
{
private:
	link<point> snake;
public:
	void init_Snake();
	int find_path(int dir,int x ,int y);
	int getdir();
	void move();
	int print_snake();
	int print_len(){cout<<snake.len; return 0;}

};

void Snake::init_Snake()
{
	
	int y=10;
	int x=10;
	gotoxy(x,y);
	cout<<PATERN;
	Mapstate[y][x]=1;
	snake.add(x,y);

	gotoxy(x,y+1);
	cout<<PATERN;
	Mapstate[y+1][x]=1;
	snake.add(x,y+1);

	snake.head->data.x=x,snake.head->data.y=y+1;
	snake.end->data.x=x,snake.end->data.y=y;
	
}

void Snake::move()
	{
	int n= getdir();
	int x=snake.head->data.x;
	int y=snake.head->data.y;
	switch(n)
	{
	case 1:
	if(Mapstate[y][x+1]==0)
	{
	snake.add(x+1,y);
	Mapstate[y][x+1]=1;
	}
	else if(Mapstate[y][x+1]==2)
	{
	snake.add(x+1,y);
	}
	else 
	{
		gotoxy(50,50);
		cout<<"game over"<<endl<<"len="<<snake.len;
		Sleep(50000);
		exit(1);
	}
	break;
	case 2:
	if(Mapstate[y][x-1]==0)
	{
	snake.add(x-1,y);
	Mapstate[y][x-1]=1;
	}
	else if(Mapstate[y][x-1]==2)
	{
	snake.add(x-1,y);
	}
	else 
	{
		gotoxy(50,50);
		cout<<"game over"<<endl<<"len="<<snake.len;
		Sleep(50000);
		exit(1);
	}
	break;
	case 3:
	if(Mapstate[y+1][x]==0)
	{
	snake.add(x,y+1);
	Mapstate[y+1][x]=1;
	}
	else if(Mapstate[y+1][x]==2)
	{
	snake.add(x,y+1);
	}
	else 
	{
		gotoxy(50,50);
		cout<<"game over"<<endl<<"len="<<snake.len;
		Sleep(50000);
		exit(1);
	}
	break;
	case 4:
	if(Mapstate[y-1][x]==0)
	{
	snake.add(x,y-1);
	Mapstate[y-1][x]=1;
	}
	else if(Mapstate[y-1][x]==2)
	{
	snake.add(x,y-1);
	}
	else 
	{
		gotoxy(50,50);
		cout<<"game over"<<endl<<"len="<<snake.len;
		Sleep(50000);
		exit(1);
	}
	break;
	}
}

int Snake::print_snake()
{
	int x=snake.head->data.x;
	int y=snake.head->data.y;
	if (Mapstate[y][x]==2)
	{
	gotoxy(x,y);
	cout<<PATERN;
	Mapstate[y][x]=1;
	return 1;
	}
	else
	{
	gotoxy(x,y);
	cout<<PATERN;
	gotoxy(snake.end->data.x,snake.end->data.y);
	cout<<" ";
	Mapstate[snake.end->data.y][snake.end->data.x]=0;
	snake.del_end();
	return 0;
	}
	}

int Snake::getdir()
{
	{
	
	int x=snake.head->data.x;
	int y=snake.head->data.y;
	int delx=x-fx;
	int dely=y-fy;
	int a[5]={0};//up down left right 
	int tmp=0;
	
	if (abs(delx)<=abs(dely))
	{ if (dely>0) a[4]+=5;else a[3]+=5;}
	else 
	{if (delx>0) a[2]+=5;else a[1]+=5;}

	for (int i=1;i<=4;i++)	
	{
		tmp+=find_path(i,x,y);
		if (!find_path(i,x,y))
			a[i]-=40;
	}
	 

	if(Mapstate[y+1][x]==2)
			a[3]+=30;
	if(Mapstate[y-1][x]==2)
			a[4]+=30;
	if(Mapstate[y][x+1]==2)
			a[1]+=30;
	if(Mapstate[y][x-1]==2)
			a[2]+=30;
	
	if(y+2==mapsize/2-1)
			a[3]-=4;
	if(y-2==0)
			a[4]-=4;
	if(x+2==mapsize-1)
			a[1]-=4;
	if(x-2==0)
			a[2]-=4;
	
	if(Mapstate[y+1][x]==1)
			a[3]=-9999;
	if(Mapstate[y-1][x]==1)
			a[4]=-9999;
	if(Mapstate[y][x+1]==1)
			a[1]=-9999;
	if(Mapstate[y][x-1]==1)
			a[2]=-9999;
	
	
		if(a[1]>=a[2]&&a[1]>=a[3]&&a[1]>=a[4])	
			return 1;
		if(a[2]>=a[1]&&a[2]>=a[3]&&a[2]>=a[4])	
			return 2;
		if(a[3]>=a[1]&&a[3]>=a[2]&&a[3]>=a[4])	
			return 3;
		if(a[4]>=a[3]&&a[4]>=a[1]&&a[4]>=a[2])	
			return 4;

	}

	}

int Snake::find_path(int dir,int x,int y){

	int  M[mapsize/2][mapsize]={0};
for (int i=0;i<=mapsize/2-1;i++)
	for (int j=0;j<=mapsize-1;j++)
		M[i][j]=Mapstate[i][j];

	switch(dir){
case 1:
	if (M[y][x+1]==2) return 1;
	M[y][x+1]=3;
	break;
case 2:;
	if (M[y][x-1]==2) return 1;
	M[y][x-1]=3;
	break;
case 3:
	if (M[y+1][x]==2) return 1;
	M[y+1][x]=3;
	break;
case 4:
	if (M[y-1][x]==2) return 1;
	M[y-1][x]=3;
	break;
}

for (int k=0;k<=(mapsize/2)*(mapsize)-1;k++){

for (int i=1;i<=mapsize/2-1;i++)
		for (int j=1;j<=mapsize-1;j++)
	{
		if (M[i][j]!=1)
		{
			if (M[i+1][j]==3 || M[i-1][j]==3|| M[i][j+1]==3 || M[i][j-1]==3)
			{
				if(M[i][j]==2)
					return 1;
			M[i][j]=3;
				}
			}
		}
	int x=0;
}
return 0;
}

	
	