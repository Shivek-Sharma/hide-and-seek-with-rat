/*
    Program:    Hide and Seek with Rat Game
    Author:     Shivek Sharma
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void GuessGame(int amount_bet, int* inhand_cash)
{
	char Hole[3] = { 'N', 'R', 'N' };
	printf("\nWait!! Rat is shuffling its position...\n");
	usleep(2000000);

	srand(time(NULL));

	int i, x, y, temp;

	//Swapping the Rat's (R's) position five times using
	//the random number for random index
	for (i = 0; i < 5; i++) {
		x = rand() % 3;
		y = rand() % 3;
		temp = Hole[x];
		Hole[x] = Hole[y];
		Hole[y] = temp;
	}

	int PlayerGuess;

	printf("\nYou may now guess the hole in which Rat is present (1, 2 or 3): ");

	scanf("%d", &PlayerGuess);

	if (Hole[PlayerGuess - 1] == 'R') {
		(*inhand_cash) += 2 * amount_bet;
		printf("\nYou won! The holes are as follows: ");
		printf("\"%c %c %c\" ", Hole[0], Hole[1], Hole[2]);
		printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
	}

	else {
		(*inhand_cash) -= amount_bet;
		printf("\nYou Loose! The holes are as follows: ");
		printf("\"%c %c %c\" ", Hole[0], Hole[1], Hole[2]);
		printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
	}
}

int main()
{
	int amount_bet, inhand_cash;

	printf("----Enter the inhand_cash you have right now---- : ");

	scanf("%d", &inhand_cash);

	while (inhand_cash > 0) {
		printf("\nEnter the amount_bet you want to play for : ");
		scanf("%d", &amount_bet);

		if (inhand_cash == 0 || amount_bet > inhand_cash)
			break;
		GuessGame(amount_bet, &inhand_cash);
	}

	if (inhand_cash == 0 || amount_bet > inhand_cash) {
		printf("\n\"Sorry you don't have enough cash to play more, ");
		printf("Do come next time.\"\n");
		printf("Thank You for playing!\n");
	}
	return 0;
}
