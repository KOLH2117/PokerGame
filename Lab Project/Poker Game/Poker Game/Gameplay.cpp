#include "Gameplay.h"
#include "CardShuffling_Dealing.h"
#include "Player.h"

int** drawCard(int deck[][FACES], int &topCard, int nCard) {
	int** newCard = new int* [nCard];
	for (int i = 0; i < nCard; i++) {
		newCard[i] = new int[2];
	}
	int i = 0;
	while (i < nCard)
	{
		int row = 0;
		int col = 0;
		while (row < SUITS) {
			if (deck[row][col] == topCard)
				break;
			col++;
			if (col == FACES) {
				col = 0;
				row++;
			}
		}
		topCard++;
		newCard[i][0] = row;
		newCard[i][1] = col;
		i++;
	}
	return newCard;
}

//Dealer Side
int** randomReplace(int** hand,int deck[][FACES],int &topCard,int nCard) {
	srand(time(NULL));
	int** newCard = drawCard(deck, topCard, nCard);
	bool flag[5] = { false };
	int i = 0;
	
	while (i < nCard)
	{
		//Random card in Dealer hand
		int pos = rand() % 5;
		//Check if the card is already replace yet
		while (flag[pos]) {
			pos = rand() % 5;
		}
		//If not the replace it
		flag[pos] = true;
		hand[pos][0] = newCard[i][0];
		hand[pos][1] = newCard[i][1];
		delete[] newCard[i];
		i++;
	}
	delete[] newCard;
	sortCardByFaces(hand);
	return hand;
}
//
//int** replaceBetter(int** hand, int deck[][FACES], int &topCard,int nCard) {
//	int** newCard = drawCard(deck, topCard, nCard);
//	int handRanking = getStatusOfHand(hand);
//	
//
//}

//Player Side
void playerDicision(int** playerHand, int deck[][FACES], int &topCard,int nCard) {
	int** newCard = drawCard(deck, topCard, nCard);
	int pos[5];
	bool flag[5] = { false };

	cout << "Your have " << nCard << " new card.\n";
	for (int i = 0; i < nCard; i++) {
		printCard(newCard[i], suits, faces);
	}

	cout << "This is your present hand.\n";
	printHand(playerHand, suits, faces);
	for (int i = 0; i < nCard; i++) {
		do
		{
			cout << "\nWhich card do you want to replace.Input the postion (1 to 5): ";
			cin >> pos[i];
			if (pos[i] < 1 || pos[i] > 5) {
				cout << "Out of range. Please chose again.\n";
				continue;
			}
			if (flag[pos[i] - 1]) {
				cout << "You already replace that card. Please chose another card.\n";
				continue;
			}
			else {
				flag[pos[i] - 1] = true;
				playerHand[pos[i] - 1][0] = newCard[i][0];
				playerHand[pos[i] - 1][1] = newCard[i][1];
			}
			if (nCard - i - 1 > 0)
				cout << nCard - i - 1 << " card is remaining\n";
			else {
				cout << "Replace complete...Check your card below.\n";
				printHand(playerHand, suits, faces);
			}
		} while (pos[i] < 1 || pos[i] > 5);
	}
	
}


void pokerGame(int deck[][FACES]) {
	cout << "Dealing time...\n";
	Sleep(1000);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "*";
			Sleep(100);
		}
		cout << "\n";
		Sleep(100);
	}
	cout << "Done\n";
	int n = 2;
	int*** nPlayer = dealingForHands(deck,n);
	int topCard = n * PLAYERCARD + 1;
	cout << "YOUR HAND\n";
	sortCardByFaces(nPlayer[0]);
	printHand(nPlayer[0], suits, faces);
	cout << "DEALER HAND\n";
	sortCardByFaces(nPlayer[1]);
	printHand(nPlayer[1],suits,faces);
	int nCard;
	cout << "Do you wna draw"
	cout << "Player draw...\nHow many card your want to draw???\n";
	
	do
	{
		
	} while (true);
	playerDicision(nPlayer[0], deck, topCard, nCard);
}


