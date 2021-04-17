#ifndef CARDSHUFFLINGANDDEALING_H
#define CARDSHUFFLINGANDDEALING_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int SUITS = 4;
const int FACES = 13;


extern const char* suits[SUITS];
extern const char* faces[FACES];

void shuffleCards(int deck[][FACES]);
void printCardsShuffling(int deck[][FACES], char* suits[], char* faces[]);
void printCardsShuffling(int deck[][FACES],const char* suits[],const char* faces[]);
#endif // !CARDSHUFFLING&DEALING_H

