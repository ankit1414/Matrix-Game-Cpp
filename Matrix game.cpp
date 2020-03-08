//DEVELPOED BY::: ANKIT BHARDWAJ
#include<stdio.h>
#include<conio.h>
#include<windows.h>
COORD coord={0,0}; // this is global variable
                //center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y) //function for gotoxy as not included in code blocks
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int mat[4][4],complete=0,r=3,c=3,count=0;//r and c are keeping the position of the blank space.
int getkey()
{	int ch;
	ch=getch();
	if(ch==0)
	{	ch=getch();
		return ch;
	}
	return ch;
}
void initialize()
{
mat[0][0]=1;
mat[0][1]=4;
mat[0][2]=15;
mat[0][3]=7;
mat[1][0]=8;
mat[1][1]=10;
mat[1][2]=2;
mat[1][3]=11;
mat[2][0]=14;
mat[2][1]=3;
mat[2][2]=6;
mat[2][3]=13;
mat[3][0]=12;
mat[3][1]=9;
mat[3][2]=5;
mat[3][3]=16;
}
void check()
{	int t=1;
	complete=1;
	for(int i=0; i<4; i++)
	{	for(int j=0; j<4; j++)
		{	if(mat[i][j]!=t)
			{	complete=0;
			}
			t++;
		}
	}
}
void print()
{	for(int i=0;i<4; i++)
	{	for(int j=0; j<4; j++)
		{	if(i==r&&j==c)
			{	printf(" \t\t");//logic to make blank
			}
			else
				printf("%d\t\t",mat[i][j]);
		}
		printf("\n\n");
	}	
}
void start()
{	int temp,swap,move;
	move=getkey();
	if(move==80&&r!=0)//down arrow
	{	temp=mat[r][c];
		mat[r][c]=mat[r-1][c];
		mat[r-1][c]=temp;
		r=r-1;
		count++;
		//print();
		check();
	}
	else if(move==72&&r!=3)//up arrow
	{	temp=mat[r][c];
		mat[r][c]=mat[r+1][c];
		mat[r+1][c]=temp;
		r=r+1;
		count++;
		check();	
	}
	else if(move==75&&c!=3)//left arrow
	{	temp=mat[r][c];
		mat[r][c]=mat[r][c+1];
		mat[r][c+1]=temp;
		c=c+1;
		count++;
		check();	
	}
	else if(move==77&&c!=0)//right arrow
	{	temp=mat[r][c];
		mat[r][c]=mat[r][c-1];
		mat[r][c-1]=temp;
		c=c-1;
		count++;
		check();	
	}	
}
int main()
{
	initialize();//filling the matrix
	print();
	while(complete!=1)
	{	start();
		gotoxy(0,0);//to print the matrix on the same place
		print();
		gotoxy(0,0);
	}
	gotoxy(0,0);
	print();
	printf("\t\t\tCOMPLETED!!!\n");
	printf("THE NUMBER OF MOVES USED ARE:::%d",count);
	return 0;
}

