#include "CardShuffling_Dealing.h"
#include "Player.h"

const int PLAYERCARD = 5;

void deleteHand(int** hand) {
	for (int i = 0; i < PLAYERCARD; i++) {
		delete[] hand[i];
	}
	delete[] hand;
}

void swapCard(int *Card1, int *Card2) {
	int suits = Card1[0];
	int faces = Card1[1];

	Card1[0] = Card2[0];
	Card1[1] = Card2[1];

	Card2[0] = suits;
	Card2[1] = faces;
}

void sortCardByFaces(int** hand) {
	for (int i = 0; i < PLAYERCARD; i++) {
		if (hand[i][1] == 0)
			hand[i][1] = 13;
	}


	for (int i = 1; i < PLAYERCARD; i++) {
		int count = 0;
		for (int j = PLAYERCARD - 1; j >= i; j--) {
			if (hand[j][1] < hand[j - 1][1]) {
				swapCard(hand[j], hand[j - 1]);
				count++;
			}
		}
		if (count == 0)
			break;
	}
	for (int i = 0; i < PLAYERCARD; i++) {
		if (hand[i][1] == 13)
			hand[i][1] = 0;
	}
}

void printCard(int* Card, const char* suits[], const char* faces[]) {
	int row = Card[0];
	int col = Card[1];
	cout << "(" << suits[row] << "," << faces[col] << ")" << endl;
}
//One Player
int** dealingForHand(int deck[SUITS][FACES]) {
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++) {
		hand[i] = new int[2];
	}
	
	int key = 1;
	int x = 0;

	do
	{
		for (int i = 0; i < SUITS; i++) {
			bool flag = false;
			for (int j = 0; j < FACES; j++) {
				if (deck[i][j] == key) {
					hand[x][0] = i;
					hand[x++][1] = j;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		key++;
	} while (key <= 5);
	
	return hand;
}

void printHand(int** hand, const char* suits[], const char* faces[]) {
	for (int i = 0; i < 5; i++) {
		int row = hand[i][0];
		int col = hand[i][1];
		cout << "(" << suits[row] << "," << faces[col] << ")";
	}
	cout << endl;

}

int** createHandTest(int deck[SUITS][FACES]){
	srand(time(NULL));
	int** test = new int* [5];

	for (int i = 0; i < 5; i++) {
		test[i] = new int[2];
	}
	for (int i = 0; i < 5; i++) {
		test[i][0] = rand() % SUITS;
		test[i][1] = rand() % FACES;
	}
	return test;
}

int isSequentialRank(int** hand) {
	sortCardByFaces(hand);

	//Special case with ACE card (Ten, Jack, Queen, King, Ace)
	// if first card is an ACE
	if (hand[0][1] == 0) { 
		// if second card is TEN
		if (hand[1][1] == 9) {
			for (int i = 2; i < PLAYERCARD - 1; i++) {
				if (abs(hand[i][1] - hand[i + 1][1]) != 1){
					return false;
				}
			}
			return true;
		}
		else
			return false;
	}
	for (int i = 0; i < PLAYERCARD - 1; i++) {
		if (abs(hand[i][1] - hand[i + 1][1]) != 1) {
			return false;
		}
	}	
	return true;
}

int isTheSameSuits(int** hand) {
	//Check all of card is the same suit
	for (int i = 0; i < PLAYERCARD - 1; i++) {
		if (hand[i][0] != hand[i + 1][0])
			return false;
	}

	return true;
}

int isFourOfAKind(int** hand) {
	int rank[13] = { 0 };
	
	for (int i = 0; i < PLAYERCARD; i++) {
		rank[hand[i][1]]++;
	}

	for (int index = 0; index < 13; index++) {
		if (rank[index] == 4)
			return true;
	}
	return false;
}

int isFullHouse(int** hand) {
	int rank[13] = { 0 };
	int flag = false;

	for (int i = 0; i < PLAYERCARD; i++) {
		rank[hand[i][1]]++;
	}

	for (int i = 0; i < 13; i++) {
		if (rank[i] == 2) {
			flag = true;
			break;
		}
	}

	if (flag == true) {
		for (int i = 0; i < 13; i++) {
			if (rank[i] == 3) {
				return true;
			}
		}
		return false;
	}

	return false;
}

int isFlush(int** hand) {
	if (isTheSameSuits(hand) == true && isSequentialRank(hand) == false)
		return true;
	return false;
}

int isStraight(int** hand) {
	if (isTheSameSuits(hand) == false && isSequentialRank(hand) == true)
		return true;
	return false;
}

int isStraightFlush(int** hand) {
	if (isTheSameSuits(hand) == true && isSequentialRank(hand) == true)
		return true;
	return false;
}

int isThreeOfAKind(int** hand) {
	int rank[13] = { 0 };
	int flag = false;

	for (int i = 0; i < PLAYERCARD; i++) {
		rank[hand[i][1]]++;
	}

	for (int i = 0; i < 13; i++) {
		if (rank[i] == 3) {
			flag = true;
			break;
		}
	}

	if (flag == true) {
		for (int i = 0; i < 13; i++) {
			if (rank[i] > 1) {
				return false;
			}
		}
		return true;
	}

	return false;
}

int isTwoPairs(int** hand) {
	int rank[13] = { 0 };
	int count = 0;

	for (int i = 0; i < PLAYERCARD; i++) {
		rank[hand[i][1]]++;
	}

	for (int i = 0; i < 13; i++) {
		if (rank[i] == 2)
			count++;
	}
	if (count == 2)
		return true;
	return false;
}

int isPair(int** hand) {
	int rank[13] = { 0 };
	int count = 0;

	for (int i = 0; i < PLAYERCARD; i++) {
		rank[hand[i][1]]++;
	}

	for (int i = 0; i < 13; i++) {
		if (rank[i] == 2)
			count++;
	}

	for (int i = 0; i < 13; i++) {
		if (rank[i] == 1)
			count++;
	}	

	if (count != 4)
		return false;

	return true;
}

int getHighestCard(int** hand) {
	if (isStraightFlush(hand))
		return false;
	
	if (isFourOfAKind(hand))
		return false;
	
	if (isFullHouse(hand))
		return false;

	if (isFlush(hand))
		return false;
	
	if (isStraight(hand))
		return false;

	if (isThreeOfAKind(hand))
		return false;

	if (isTwoPairs(hand))
		return false;

	if (isPair(hand))
		return false;

	int highestCard = -1;
	for (int i = 0; i < PLAYERCARD; i++) {
		//if meet the ACE card return ACE
		if (hand[i][1] == 0)
			return 0;
		else {
			if (hand[i][1] > highestCard)
				highestCard = hand[i][1];
		}
	}
	return highestCard;
}

//TwoPlayer
int*** dealingForHands(int deck[SUITS][FACES], int n) {
	int*** nPlayer = new int** [n];
	for (int i = 0; i < n; i++) {
		nPlayer[i] = new int* [5];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			nPlayer[i][j] = new int[2];
		}
	}
	
	int card = 0;

	while (card < n * PLAYERCARD)
	{
		//Find card in deck
		int row = 0;
		int col = 0;
		while (row < SUITS) {
			if (deck[row][col] == card + 1)
				break;
			else {
				col++;
				if (col == FACES) {
					col = 0;
					row++;
				}
			}
		}
		nPlayer[card % n][card / n][0] = row;
		nPlayer[card % n][card / n][1] = col;
		card++;
	} 
	for (int i = 0; i < n; i++) {
		sortCardByFaces(nPlayer[i]);
	}
	return nPlayer;
}

int getStatusOfHand(int** hand) {
	if (isStraightFlush(hand))
		return 8;

	if (isFourOfAKind(hand))
		return 7;

	if (isFullHouse(hand))
		return 6;

	if (isFlush(hand))
		return 5;

	if (isStraight(hand))
		return 4;

	if (isThreeOfAKind(hand))
		return 3;

	if (isTwoPairs(hand))
		return 2;

	if (isPair(hand))
		return 1;

	return 0;
}

int* rankingHands(int*** hands, int n)
{
	int* rankOfPlayer = new int[n];
	for (int i = 0; i < n; i++)
	{
		rankOfPlayer[i] = getStatusOfHand(hands[i]);
	}

	return rankOfPlayer;
}

int* evaluateHands(int deck[][FACES], int s,int n) {
	//Initialize score with 0
	int* score = new int [n];
	for (int i = 0; i < n; i++) {
		score[i] = 0 ;
	}

	int turn = 0;

	while (turn < s) {
		shuffleCards(deck);
		int*** nPlayer = dealingForHands(deck, n);
		int* rankOfPlayer = rankingHands(nPlayer, n);
		for (int i = 0; i < n; i++) {
			score[i] += rankOfPlayer[i];
		}
		
		//Free memory
		delete[] rankOfPlayer;
		for (int i = 0; i < n; i++) {
			deleteHand(nPlayer[i]);
		}
		delete[] nPlayer;
		turn++;
	}

	return score;
}

