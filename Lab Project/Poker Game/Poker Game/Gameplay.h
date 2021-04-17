#ifndef GAMEPLAY_H
#define GAMEPLAYE_H

int** randomReplace(int** hand, int deck[][13], int &topCard, int nCard);


void playerDicision(int** playerHand, int deck[][13], int& topCard, int nCard);

void pokerGame(int deck[][13]);
#endif // !GAMEPLAY_H

