#include "CardShuffling_Dealing.h"

const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char* faces[FACES] = { "Ace", "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King" };

void shuffleCards(int deck[][FACES]) {
	srand(time(NULL));
	
	//Initialize 2-D array with all member is 0
	for (int i = 0; i < SUITS; i++) {
		for (int j = 0; j < FACES; j++) {
			deck[i][j] = 0;
		}
		
	}
	//Randomly put each number in the range [1, 52], to every element of the matrix
	int card = 1;

	while (card <= 52 )
	{
		int i = rand() % SUITS;
		int j = rand() % FACES;

		while (deck[i][j] != 0) {
			i = rand() % SUITS;
			j = rand() % FACES;
		}

		deck[i][j] = card;
		card++;
	}
}

void printCardsShuffling(int deck[][FACES], char* suits[], char* faces[]) {
	for (int i = 0; i < SUITS; i++) {
		for (int j = 0; j < FACES; j++) {
			int tmp = deck[i][j];
			cout << "(" << suits[tmp / FACES] << "," << faces[tmp % FACES - 1] << ")" << " ";
		}
		cout << endl;
	}

}

void printCardsShuffling(int deck[][FACES],const char* suits[],const char* faces[]) {
	//Initialize an 1-D array of four elements, suits:
	
	//Initialize an 1-D array of thirteen elements, faces:
	//faces = { "Ace", "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King" };

	int k = 1;
	while (k < 53) {
		for (int i = 0; i < SUITS; i++) {
			bool flag = false;
			for (int j = 0; j < FACES; j++) {
				if (deck[i][j] == k)
				{
					cout << "(" << suits[i] << "," << faces[j] << ")" << endl;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		k++;
	}

}