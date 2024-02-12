#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<climits>
using namespace std;


void print(char tic[3][3])
{


    //Rander Game Board LAYOUT

  
    cout<<"     |     |     \n";
    cout<<"  "<<tic[0][0]<<"  |  "<<tic[0][1] <<"  |  "<<tic[0][2] <<"  \n";
    cout<<" ____|_____|____"<<endl;
    cout<<"     |     |     \n";
    cout<<"  "<<tic[1][0]<<"  |  "<<tic[1][1] <<"  |  "<<tic[1][2] <<"  \n";
        cout<<" ____|_____|____"<<endl;
    cout<<"     |     |     \n";
    cout<<"  "<<tic[2][0]<<"  |  "<<tic[2][1] <<"  |  "<<tic[2][2] <<"  \n";

}

void board(char tic[3][3])
{
		cout<<endl<<"\t \t \t \t \t \t  Tic Tac Toe "<<endl;
	cout<<"\t\t\t\t------------------------------------------------- "<<endl<<endl<<endl;

		print(tic);
		cout<<endl<<endl<<"First player : O "<<endl<<"Secound player : X "<<endl<<endl;
}


bool winChk(char tic[3][3], char player )
{
			 for(int i=0; i<3; i++)
			{
				if( 
					(tic[0][i] ==player && tic[1][i]==player && tic[2][i]==player) ||
					(tic[i][0] ==player && tic[i][1]==player && tic[i][2]==player) ||
					(tic[0][0] ==player && tic[1][1]==player && tic[2][2]==player) ||
					(tic[0][2] ==player && tic[1][1]==player && tic[2][0]==player)  
				  )
				  return true;
			}
		return false;
}

bool draw(char tic[3][3])
{

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(tic[i][j]==' ')
			{
				return false;
			}
			
		}
	}
	return true;
}


// MINI MAX CODE

int evaluate(char tic[3][3])
{
	if( winChk(tic,'X')==true )
	{
		return -10;
	}
	
	else if(winChk(tic,'O')==true )
	{
		return 10;
	}
	else return 0;
}


int minimax(char tic[3][3], int depth, bool isMax)
{	
int score =	evaluate(tic);
if(score==10||score==-10)
return score;

if( draw(tic) )
return 0;

if(isMax)
	{
		int BestScore = INT_MAX;
		for(int i=0; i<3; i++)
		{
			for( int j=0; j<3; j++)
			{
				if(tic[i][j]==' ')
				{
					tic[i][j]='X';
					int score = minimax(tic , depth+1, false);
					tic[i][j]=' ';
					if(score<BestScore)
					{
					 BestScore=	score ;
						}	
				}
					
			}	
		}	
		return BestScore;
	}	
else
	{
		int BestScore = INT_MIN;
		for(int i=0; i<3; i++)
		{
			for( int j=0; j<3; j++)
			{
				if(tic[i][j]==' ')
				{
					tic[i][j]='O';
					int score = minimax(tic , depth+1,true);
					tic[i][j]=' ';
					if(score>BestScore)
					{
						 BestScore =score ;
						}	
				}
					
			}	
		}	
		return BestScore;
	}	
	
	

	
}

void BestMove(char tic[3][3])
{
	
	
	int BestScore = INT_MIN;
	int bestMove[2]={-1,-1};
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(tic[i][j] ==' ')
			{
				tic[i][j]='O';
			int score =	minimax(tic, 0, true);
			tic[i][j]=' ';
			if(score>BestScore)
				{
					BestScore=score;
					bestMove[0]={i};
					bestMove[1]={j};
				}
			}			
		}
	}	
	tic[bestMove[0] ] [ bestMove[1]]='O';
}




int main()
{	char choice;
	int game;

	
	//minimax
	
	
	
	//minimax
	 
	do{
		
	char player='X';		
int row;
int col;
	char tic[3][3]={  {' ',' ',' '} , {' ',' ',' '} , {' ' , ' ' , ' '}   };
	int count=0;
	bool check=true;
	board(tic);
	bool win=false;

			cout<<"Do want to play two player or against AI "<<endl;
			cout<<"1. Two Players "<<endl;
			cout<<"2. AI "<<endl;
			cout<<"Type : ";
			cin>>game;
				system("cls");
				board(tic);
				
				
			switch(game)
			{
				case 1 :
					do{
					
	cout<<"Player "<<player << " turn : " <<endl;
cout<<"Enter  row : ";
cin>>row;
cout<<"Enter  column : ";
cin>>col;
if(tic[row-1][col-1] !=' ')
check=false;
else
check=true;	

	if(col>3||col<1 ||row>3||row<1 || check==false){
	
	cout<<"Invalid input"<<endl<<endl;

}
	else
	{	
	tic[row-1][col-1]=player;
					cout<<endl;	
	system("cls");
		board(tic);
win=winChk(tic, player );
		count++;
		
		
		if(win==true)
		break;
		
	else if(count>=9)
		break;
		if(player=='X')
player ='O';
else
 player='X';
		
}

		}
	while(win==false && count<=9 );
	
		if(win==false)
	{
		cout<<"It's a Draw "<<endl;
	}
	else
	{
		cout<<"Player "<<player<<" win!!";
	}
					break;
					
				case 2 :
					
							do{
					
	cout<<"Player "<<player << " turn : " <<endl;
cout<<"Enter  row : ";
cin>>row;
cout<<"Enter  column : ";
cin>>col;
if(tic[row-1][col-1] !=' ')
check=false;
else
check=true;	

	if(col>3||col<1 ||row>3||row<1 || check==false){
	
	cout<<"Invalid input"<<endl<<endl;
continue;
}
	else
	{	
	tic[row-1][col-1]=player;
					cout<<endl;	
	system("cls");
		board(tic);
win =winChk(tic , player);
		count++;
		if(win==true)
			{
				cout<<"You win! Well done  "<<endl;
		break;
	}
		
	else if(count>=9)
		break;
	}
	
	cout<<"Computer is making a move "<<endl;
	Sleep(2000);		
	
	BestMove(tic);
	//cp
	
	system("cls");
		board(tic);
	win = winChk(tic , 'O');
	
		
			if(win==true)
			{
				cout<<"Computer wins! Better luck next time :) "<<endl;
		break;
	}
	else if(count>=9)
		break;	
				count++;
				}
				
	while(win==false && count<=9 );	
	
		if(win==false)
	{
		cout<<"It's a Draw "<<endl;
	}
				break;
				
				default : cout<<"Invalid choice "<<endl;
				break;
					
}

	 
	cout<<endl<<"Do you want to play more (Y/N) =  ";
	cin>>choice;
	cout<<endl<<endl;
	system("cls");
			}
		
	while(choice=='Y'||choice =='y');		
return 0;
}


	
