#include<stdio.h>
#include <stdbool.h>

void displayBoard(int board[][9], int row, int col);
void addGuess(int[][9], int, int, int);
void Reset(int[][9], bool[][9], int, int);
bool isFull(int[][9], int, int);
bool getAllowedValues(int[][9], int, int, int);

int main(void){
	
	const int ROWS = 9; 
	const int COLUMNS = 9; 
	int flag=1;
	//initializes the board & displays the initial board 
	bool correct=false, full=false;
	int board[9][9] = {{1,2,3,4,9,7,8,6,5}, {4,5,9}, {6,7,8}, {3, 0, 0, 1}, {2}, {9,0,0,0,0,5}, {8}, {7}, {5,0,0,9}}; 
	bool initial[9][9] = {
		{false,false,false, false, false, false, false, false, false},
		{false,false, false,true,true,true,true,true,true},
		{false,false,false,true,true,true,true,true,true},
		{false, true, true, false, true, true, true, true, true},
		{false, true, true, true, true, true, true, true, true},
		{false, true, true, true, true, false, true, true, true},
		{false, true, true, true, true, true, true, true, true},
		{false, true, true, true, true, true, true, true, true},
		{false, true, true, false, true, true, true, true, true},

			};

printf("Welcome to Sudoku!\n");
	while (correct==false && full==false)
	{
		int guessRow, guessColumn, choice, value;
		printf("Puzzle (0 means the square is blank): \n");
		displayBoard(board, ROWS, COLUMNS);
		printf("1. Enter a guess\n");
		printf("2. Display values that can be placed in a given square\n");
		printf("3. Reset puzzle\n");
		printf("Enter a choice (1-3): ");
		scanf("%d",&choice);
		if (choice<1 || choice>3)
			printf("Choice is out of range. Please enter a number (1-3)");
		else if (choice==1)
		{
			printf("Enter a row number: ");
			scanf("%d",&guessRow);
			printf("Enter a column number: ");
			scanf("%d", &guessColumn);
			printf("Enter a value: ");
			scanf("%d",&value);
			if (guessRow>10 || guessColumn>10)
				printf("Row or column is out of range. Please enter a number (1-9).\n");
			else if (initial[guessRow-1][guessColumn-1]==false)
				printf("This is a given value that cannot be changed.\n");
			else
				addGuess(board, guessRow, guessColumn, value);
		}
		else if (choice==2)
		{
			printf("Enter a row number: ");
			scanf("%d",&guessRow);
			printf("Enter a column number: ");
			scanf("%d", &guessColumn);
			if (guessRow>10 || guessColumn>10)
				printf("Row or column is out of range. Please enter a number (1-9).\n");
			else if (initial[guessRow-1][guessColumn-1]==false)
				printf("This is a given value that cannot be changed.\n");
			else
				getAllowedValues(board, guessRow, guessColumn, 2);

			//function will print out possible values 
		}

		else if (choice==3)
		{
			Reset(board, initial, ROWS, COLUMNS);
		}
		full=isFull(board, ROWS, COLUMNS);
		for (int i=0; i<ROWS; i++)
		{
			for (int j=0; j<COLUMNS; j++)
			{
				correct=getAllowedValues(board, i, j, 0);
				if (correct==false)
				{
					flag=0;
				}
			}
		}
		if (flag==0)
		{
			correct=false;
		}
		else
			correct=true;
		
	} 
	printf("Congrats! You solved the puzzle!\n");	// end of main 
}

void displayBoard(int board[][9], int r, int c){
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%d\t", board[i][j]);
		}
		printf("\n");

	}

}

void addGuess(int board[][9], int row, int column, int value)
{
		board[row-1][column-1]=value;
}

void Reset(int board[][9], bool initial[][9], int row, int column)
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<column; j++)
		{
			if (initial[i][j])
			{
				board[i][j]=0;
			}
		}
	}	
}

bool isFull(int board[][9], int row, int column)
{
	int flag=0;
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<column;j++)
		{
			if (board[i][j]==0)
				flag=1;
		}
	}
	if (flag)
		return false;
	else
		return true;
}

//returns an array of bool values, 
//true if digit can be placed withoutviolating restrictions 
//takes in a specific row and col to see what values to see what values can go in there 

/*
first creates a bool array, user will give row and col
while board[row][col] == 0 
then check for 1-9 and print out the number if == true meaning a valid number for input 
call get AllowedValues from main  

*/




bool getAllowedValues(int board[][9], int row, int col, int choice){

	bool allowed[9] = {true, true, true, true, true, true, true, true, true} ; 
	//true if the digit can be placed in the given square without violating the restrictions 

//checks the row 
	for (int i = 0; i < 9; i++){
	switch(board[row-1][i]){

		case 1: 
			allowed[0] = false; 
			break;
		case 2: 
			allowed[1] = false; 
			break; 
		case 3:
			allowed[2] = false;
			break; 
		case 4: 
			allowed[3] = false; 
			break;
		case 5: 
			allowed[4] = false; 
			break;
		case 6: 
			allowed[5] = false; 
			break;
		case 7: 
			allowed[6] = false; 
			break;
		case 8: 
			allowed[7] = false; 
			break;
		case 9: 
			allowed[8] = false;
			break; 

	} // end of switch 
}

	//checks the column
	for (int i = 0; i < 9; i++){
		switch(board[i][col-1]){

			case 1: 
				allowed[0] = false; 
				break;
			case 2: 
				allowed[1] = false; 
				break; 
			case 3:
				allowed[2] = false;
				break; 
			case 4: 
				allowed[3] = false; 
				break;
			case 5: 
				allowed[4] = false; 
				break;
			case 6: 
				allowed[5] = false; 
				break;
			case 7: 
				allowed[6] = false; 
				break;
			case 8: 
				allowed[7] = false; 
				break;
			case 9: 
				allowed[8] = false;
				break; 

		} // end of switch 
	}

//check the subgrid 
	if (row < 3 && col < 3){

		for(int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++){
				//check switch statement 

		switch(board[i][j]){

			case 1: 
				allowed[0] = false; 
				break;
			case 2: 
				allowed[1] = false; 
				break; 
			case 3:
				allowed[2] = false;
				break; 
			case 4: 
				allowed[3] = false; 
				break;
			case 5: 
				allowed[4] = false; 
				break;
			case 6: 
				allowed[5] = false; 
				break;
			case 7: 
				allowed[6] = false; 
				break;
			case 8: 
				allowed[7] = false; 
				break;
			case 9: 
				allowed[8] = false;
				break; 
				
				}
			}
		} // end of switch 
	}

	else {	//rows and col of 3,4,5,6,7,8
		int newRow = row  - (row % 3); //either be 3 or 6 
		int newCol = col - (col % 3);

		for(int i = newRow; i < newRow + 3; i++){	
			for (int j = newCol; j < newCol + 3; j++){

			switch(board[i][j]){

			case 1: 
				allowed[0] = false; 
				break;
			case 2: 
				allowed[1] = false; 
				break; 
			case 3:
				allowed[2] = false;
				break; 
			case 4: 
				allowed[3] = false; 
				break;
			case 5: 
				allowed[4] = false; 
				break;
			case 6: 
				allowed[5] = false; 
				break;
			case 7: 
				allowed[6] = false; 
				break;
			case 8: 
				allowed[7] = false; 
				break;
			case 9: 
				allowed[8] = false;
				break; 
			}
		}

	} // end of switch 
}

//prints out the allowed values 
if (choice==2){
	printf("Allowed values:\n");
for (int i = 0; i < 9; i++){
	if (allowed[i]){
		printf("%d\n", i+1);
	}
}
printf("\n");
}

else if (choice==0)
{
	if (allowed[board[row][col]-1])
		printf("");
	else
		return false;
}
return true;
}
	
