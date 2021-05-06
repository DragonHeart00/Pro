//
// Created by Sulaiman Kasas on 06/05/2021.
//

#ifndef PRO_GAMELOGIC_H
#define PRO_GAMELOGIC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Controller.h"
static const char solitaireSuits[5]={'H','D','S','C','\0'};
static const char solitaireCards[14]={'K','Q','J','T','9','8','7','6','5','4','3','2','A','\0'};

struct Card{
    //This holds our card
    //First char stores our card value e.g A for Ace
    //The second char stores our card suite e.g H for Hearts
    char value[2];
    //This pointer represents a memory address of the next card in our linked list
    struct Card *Next;
    bool fliped;
    char color;

};


struct Deck{

    struct Card * cardList;
};

struct Suite{
    char suiteLetter;
    struct Card * cardList;
};

struct Game{

    struct Deck Decks[7];
    struct Suite Suites[4];
//
};

struct MoveSummary{
    bool isvalid;
    char  Message[50];
};
//Card will be used to represent the cardItem and its row/column


//Prototypes
void Initialize(struct Game *game);
void InitializeDecks(struct Deck Decks[]);
void InitializeSuites(struct Suite Suites[]);
void LoadGame();
void LoadSW(struct Game* game,char Message[10]);
void FlipCards(struct Card * cardList);
void Load(char filename[],struct Game *Game,char Message[4]);
void DisplayDecks(struct Game *Game);
void DisplaySuites(struct Suite Suites[]);
void Render(struct Game *game);
void DisplayCardList(struct Card * cardList);
void AddDisplaySuite(struct Suite Suites[],char DeckGrid[][13][2],int column);
void AddDisplayDeck(struct Deck _deck,char DeckGrid[][7][3],int column);
void Shuffle(struct Deck Decks[]);
void Split(struct Deck Decks[]);
bool isCardInDeck(struct Card * card,char cardvalue[2]);
bool isCardInDeck1(struct Card * cardList,int index);
struct Card * GetCard(struct Card * cardList, int Index);
struct Card * GetCard1(struct Card * cardList, char cardvalue[2]);
char * RandomCardValue1();
void MoveDeckCardsToSuite();
int ListCount(struct Card * cardList);
void AddCardToList(struct Card*cardList,struct Card *CardToAdd);
struct MoveSummary IsValidMove(struct Card*cardList,struct Card *CardToAdd);

void AddCardsToDeck(struct Deck Decks[],int DeckColumn,int cardCount,int flipedCount);
void GameAction(char command[20],struct Game* game);
void RandomCardValue(char RandomCard[2]);
void MoveCardToDeck(struct Game *game,int FinalDeckColumn,int currentDeckColumn,char data[2]);
void RemoveLastCard(struct Card*cardList);
void GenerateDiffDeckCard(struct Card * cardList, char cardvalue[2]);
void SaveToFile(char filename[],struct Deck Decks[],int column );
void DisplayMovSumMessage(struct  MoveSummary sum);
void ExitGame();
#endif //PRO_GAMELOGIC_H
