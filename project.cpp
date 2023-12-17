#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER='X';
const char COMPUTER='0';
void ComputerMove();
void resetboard();
void printboard();
int checkFreeSpace();
void playerMove();
char checkWinner();
void printWinner(char);

int main()
{
	char winner=' ';
	//empty means there is  no winner and if player wins winnner will be the x and computer wins the winner will be 0
	resetboard();
	
	while(winner ==' '&&checkFreeSpace()!=0){
	printboard();
	
	playerMove();
	winner = checkWinner();
	if(winner!= ' '&& checkFreeSpace()==0){
		break;
	}
	
	ComputerMove();
	winner = checkWinner();
	if(winner!= ' '&& checkFreeSpace()==0){
		break;
	}
	}
	printboard();
	printWinner(winner);
	return 0;
}
void resetboard(){
	//nested loop for row and column 
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		board[i][j]=' ';
		
		}
	}
	}
void printboard(){
	printf("| %c | %c | %c |",board[0][0],board[0][1],board[0][2]);
	printf("\n|---|---|---|\n");
	printf("| %c | %c | %c |",board[1][0],board[1][1],board[1][2]);
	printf("\n|---|---|---|\n");
	printf("| %c | %c | %c |",board[2][0],board[2][1],board[2][2]);
	
	printf("\n");
	
}
int checkFreeSpace(){
	
	int freeSpaces=9;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]!=' '){
				freeSpaces--;
			}
			
		}
	}
	return freeSpaces;
}
char checkWinner(){
	//here we need to check the row and column and diagonal for for the winner 
	//row 00 == 01 == 11 and 
	for(int i=0;i<3;i++){
		
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]){
		
		  return board[i][0];
	   }
	   
	//column
	for(int j=0;j<3;j++)
	{
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]);
		{
			return board[0][i];
		}
	}
	for(int k=0;k<3;k++){
		if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]);
		{
			return board[0][0];
		}
		if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]);
		{
			return board[0][2];
			
		}
		// if no winner
		return ' ';
		
		
	}
	
	
}}
void printWinner(char winner){
	if(winner==PLAYER){
		printf("You win");
	}
	else if(winner == COMPUTER)
	{
		printf("computer wins");
	}
	else{
		printf("its a draw");
	}
	
}
void playerMove(){
	int x;
	int y;
	
	do{
	
	printf("please enter the co ordinates to move \n");
	
	printf("Enter the row no# (1-3) \n");
	scanf("%d",&x);
	x--;
	printf("Enter the column no# (1-3) \n");
	scanf("%d",&y);
	y--;
	if(board[x][y]!=' '){
		printf("Invalid move \n");
	}
	else{
		board[x][y]=PLAYER;
		break;
	}
}while(board[x][y]!=' ');

}
void ComputerMove(){
	//create the seed
	srand(time(0));
	int x;
	int y;
	if(checkFreeSpace()>0){
		do{
			//creating random steps by te computer 
			x=rand()%3;
			y=rand()%3;
		}while(board[x][y]!=' ');
		
		board[x][y]=COMPUTER;
	}
	else{
		 printWinner(' ');
		
	}
}
