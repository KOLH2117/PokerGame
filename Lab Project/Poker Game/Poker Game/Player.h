#ifndef ONEPLAYER_H
#define ONEPLAYER_H

extern const int PLAYERCARD;

//Additional function
void deleteHand(int** hand);
void sortCardByFaces(int** hand);
void printCard(int* Card, const char* suits[], const char* faces[]);

//One Player
int** dealingForHand(int deck[SUITS][FACES]);
void printHand(int** hand, const char* suits[], const char* faces[]);
int** createHandTest(int deck[SUITS][FACES]);
int isFourOfAKind(int** hand);
int isFullHouse(int** hand);
int isFlush(int** hand);
int isStraight(int** hand);
int isStraightFlush(int** hand);
int isThreeOfAKind(int** hand);
int isTwoPairs(int** hand);
int isPair(int** hand);
int getHighestCard(int** hand);

//Two Player
int*** dealingForHands(int deck[SUITS][FACES], int n);
int getStatusOfHand(int** hand);
int* rankingHands(int*** hands, int n);
#endif // !ONEPLAYER_H

