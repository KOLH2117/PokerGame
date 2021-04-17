#include "CardShuffling_Dealing.h"
#include "Player.h"
#include "Gameplay.h"

using namespace std;

int main() {
	int deck[SUITS][FACES];
	int n;
	shuffleCards(deck);
	printCardsShuffling(deck, suits, faces);
	
	pokerGame(deck);
	

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			delete[] nPlayer[i][j];
	}
	for (int i = 0; i < n; i++) {
		delete[] nPlayer[i];
	}
	delete[] nPlayer;
	*/
		
		
		
	
	system("pause");
	
		
	
	
	return 0;
}