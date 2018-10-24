
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "game.h"
#define fps 100



int main()
{

Snake snake;
snake.printmap();
snake.generatefood();
snake.init_Snake();
while(1)
{

snake.move();
if(snake.print_snake())
	snake.generatefood();
Sleep(1000/fps);
snake.gotoxy(50,20);
cout<<"score:";
snake.print_len();

}


}