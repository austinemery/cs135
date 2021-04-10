#include<stdio.h>

int menuRun();
void vsComputer();
void vsHuman();
void clearBoard(char board[3][3]);
void printBoard(char board[3][3]);

int main()
 {
	menuRun();

	return 0;
 }

int menuRun()
 { 
	
	int a;
	//menu

	for (;;)
	 {
		printf("\nWelcome to tic-tac-toe, what would you like to do?\n");
		printf("1. VS Computer\n2. VS Human\n3. Quit\nCommand: ");
		scanf("%d", &a);

		if ( a == 1 )
		 {
			vsComputer();
		 }
		else if ( a == 2 )
		 {
			vsHuman();
		 }
		else if ( a == 3 )
		 {
			return 0;
		 }
		else
		 {
			printf("--Invalid Key--");
		 }

	 }
 }

void vsComputer()
 {
	int xrowc[3] = {0}, xcolc[3] = {0}, xdiagc[2] = {0};
	int orowc[3] = {0}, ocolc[3] = {0}, odiagc[2] = {0};
	char board[3][3];

	printf("Versus Computer\n");
	clearBoard(board);
	
	printBoard(board);
 }

void vsHuman()
 {
	printf("\nVersus Human");
 }
void clearBoard(char board[3][3])
 {
	int i, j;

	for (i = 0; i < 3; i++)
	 {
		for (j = 0; j < 3; j++)
		 {
			board[i][j] = 'a';
		 }
	 }
 }

void printBoard(char board[3][3])
 {
	int i, j;

	for (i = 0; i < 3; i++)
	 {
		for (j = 0; j < 3; j++)
		 {
			printf("%c ", board[i][j]);
		 }
		printf("\n");
	 }
 }
