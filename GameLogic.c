//
// Created by Sulaiman Kasas on 06/05/2021.
//
#include "GameLogic.h"
//use it to show all the cards in the order


void LoadSW(struct Game* game,char Message[10]){

    for(int i=0;i<7;i++)
    {
        FlipCards(game->Decks[i].cardList);
    }
    strcpy(Message,"OK");
}



static  bool isSecondComValid=false;
void Load(char filename[],struct Game* game,char Message[10])
{

    char ReadFields[53][4];
    readFromFile(filename,"r",ReadFields,Message);
    int itemcount=   FileCount(filename,0);
    //Items count validation
    if(itemcount>52 || itemcount<52)
    {
        Message="Failed";
    }
    if(strcmp(Message,"OK")==0)
    {
        int cardCount=0;
        while(true)
        {
            for (int j=0; j<7; j++)
            {

                if(cardCount<7)
                {

                    game->Decks[j].cardList=(struct Card*) malloc(sizeof(struct Card));
                    game->Decks[j].cardList->Next=NULL;
                    char lo[2];
                    lo[0]=ReadFields[cardCount][0];
                    lo[1]=ReadFields[cardCount][1];
                    lo[2]='\0';
                    game->Decks[j].cardList->fliped=false;
                    strcpy(game->Decks[j].cardList->value,lo);
                    game->Decks[j].cardList->color= game->Decks[j].cardList->value[1];

                }
                else
                {
                    if(cardCount>52-1)
                    {
                        return;
                    }

                    struct Card * card=(struct Card*) malloc(sizeof(struct Card));
                    card->Next=NULL;

                    char lo[2];
                    lo[0]=ReadFields[cardCount][0];
                    lo[1]=ReadFields[cardCount][1];
                    lo[2]='\0';


                    strcpy(card->value,lo);
                    card->color=card->value[1];


                    card->fliped=false;

                    AddCardToList(game->Decks[j].cardList,card);

                }

                cardCount++;
            }

        }

    }




}


void LoadGame()
{

    struct Game * _game=(struct Game*)malloc(sizeof(struct Game));
    Initialize(_game);

    Render(_game);
}


void Render(struct Game * game){
    char  inputString[50];
    newline(3);
//GameAction("p",game);



    while(true)
    {
        printf("input:");
        fgets(inputString,50,stdin);

        GameAction(inputString,game);

    }

}





void GameAction(char command[20],struct Game *game)
{
    char PlayerCommand[2][50];
    char splitch[]=" ";
    char LastCommand[50];
    char _Message[10];

    split(PlayerCommand,command,splitch);
    char cr=' ';
    if(canSplit(command,cr)==true)
    {
        isSecondComValid=true;

    }else
    {
        isSecondComValid=false;

    }
    if(strstr(PlayerCommand[0],"LD")!=NULL)
    {
        //Load(PlayerCommand[1],game,_Message);
        if(strlen(PlayerCommand[1])>2)
        {
            Load(PlayerCommand[0],game,_Message);
        }else
        {
            //LD <filename>
            Load("/Users/sulaimankasas/CLionProjects/Pro/Card.txt",game,_Message);
        }


        if(strcmp(_Message,"OK")==0)
        {
            DisplayDecks(game);
        }


        strcpy(LastCommand,command);
        printf("Last Command:%s \n",LastCommand);
        printf("Message:%s \n\n",_Message);

    }
    else if(strstr(PlayerCommand[0],"SW")!=NULL)
    {
        LoadSW(game,_Message);
        if(strcmp(_Message,"OK")==0)
        {
            DisplayDecks(game);
        }

        strcpy(LastCommand,command);
        printf("Last Command:%s \n",LastCommand);
        printf("Message:%s \n\n",_Message);
    }


    else if(strstr(PlayerCommand[0],"SR")!=NULL)
    {

        strcpy(LastCommand,command);
    }

    else if(strstr(PlayerCommand[0],"P")!=NULL)
    {

        strcpy(LastCommand,command);
    }

    else if(strstr(PlayerCommand[0],"Q")!=NULL)
    {

        ExitGame();
        strcpy(LastCommand,command);
    }
    else
    {
        printf("wrong command\n");
        strcpy(LastCommand,command);
    }

}






void RandomCardValue(char RandomCard[2])
{
    char solitaireCards[14]= {'K','Q','J','T','9','8','7','6','5','4','3','2','A','\0'};
    char solitaireSuits[5]= {'H','D','S','C','\0'};

    char card[2];
    //Generate a random card from the 12 solitaire cards
    card[0]=solitaireCards[Randomize(0,12)];
    //Generate a random suit from 4 solitaire suits
    card[1]=solitaireSuits[Randomize(0,3)];
    card[2]='\0';

    //then return the concatenated card and suite
    //printf_s("%s",card);
    strcpy(RandomCard,card);

}



char * RandomCardValue1()
{
    char card[2];
    //Generate a random card from the 12 solitaire cards
    card[0]=solitaireCards[Randomize(0,12)];
    //Generate a random suit from 4 solitaire suits
    card[1]=solitaireSuits[Randomize(0,3)];
    card[2]='\0';
    char *newCard=(char*)malloc(sizeof(char)*2);
    // newCard=card;
    strcpy(newCard,card);
    //then return the concatenated card and suite
    //printf_s("%s",card);
    return newCard;
}





bool isCardInDeck(struct Card * cardList,char cardvalue[2])
{

    struct Card * next=cardList;
    bool cardExists=false;
    while (next!=NULL)
    {
        if(strcmp(next->value,cardvalue)==0)
        {
            cardExists=true;
            return cardExists;

        }


        next=next->Next;
    }
    return cardExists;
}





void DisplayCardList(struct Card * cardList)
{


    struct    Card *card=cardList;
    while (card!=NULL)
    {
        if(card->fliped==true)
        {
            printf("%s\n",card->value);
        }
        else
        {
            printf("%s\n","[]");
        }

        card=card->Next;
    }
}





void FlipCards(struct Card * cardList)
{
    struct    Card *card=cardList;
    while (card!=NULL)
    {
        if(card->fliped==false)
        {
            card->fliped=true;

        }


        card=card->Next;
    }

}





bool isCardInDeck1(struct Card * cardList,int index)
{

    struct Card * next=cardList;
    bool cardExists=false;
    int count=0;
    count++;

    while (next!=NULL )
    {


        if(count==index)
        {
            cardExists=true;
            //  return cardExists;
        }

        count++;
        next=next->Next;
    }


    return cardExists;
}





struct Card * GetCard(struct Card *List,int Index)
{


    struct    Card *card=List;


    int listCounter=0;


    while (listCounter!=Index)
    {
        card=card->Next;
        listCounter++;
        // printf_s("%d",listCounter);
    }

    //printf_s("%s",card->value);


    return card;
};



struct Card * GetCard3(struct Card *List)
{

    struct  Card *card=List;

    struct  Card *card1;
    while (card!=NULL)
    {
        if(card!=NULL)
        {
            card1=card;

        }
        card=card->Next;

        // printf_s("%d",listCounter);
    }

//printf_s("%s",card->value);

    return card1;
};





struct Card * GetCard1(struct Card * cardList, char cardvalue[2])
{

    bool cardExists=false;
    struct    Card *card=NULL;
    cardExists=isCardInDeck(cardList,cardvalue);
    if(cardExists)
    {
        card=cardList;

        while (strcmp(card->value,cardvalue)!=0 && card->Next!=NULL)
        {
            card= card->Next;

        }
    }
    return card;
}




void AddCardToList(struct Card*cardList,struct Card *CardToAdd)
{

    struct Card *card=NULL;

    card=GetCard3(cardList);

    if(card!=NULL)
    {
        card->Next=CardToAdd;
    }
}





int ListCount(struct Card * List1)
{

    int listCounter=0;
    if ((List1!=NULL))
    {
        struct  Card *card=List1;
//  if(card!=NULL)    listCounter+1;
        while (card!=NULL)
        {
            card=card->Next;
            listCounter++;
        }

    }

    return listCounter;

}





void Initialize(struct Game *game)
{
    //code goes here
    InitializeDecks(game->Decks);
    InitializeSuites(game->Suites);
    printf("Foundations\n\n");
    DisplaySuites(game->Suites);
    //newline(1);
    DisplayDecks(game);



}




void InitializeSuites(struct Suite Suites[])
{

    for (int j=0; j<4; j++)
    {
        Suites[j].suiteLetter=solitaireSuits[j];
        Suites[j].cardList=NULL;
    }

}



void InitializeDecks(struct Deck Decks[])
{
    for(int i=0;i<7;i++)
    {
        Decks[i].cardList=NULL;
    }


    /* for(int i=0; i<7; i++)
     {
         if(i==0)
         {
             AddCardsToDeck(Decks,i,1,0);
         }
         else
         {
             AddCardsToDeck(Decks,i,5+i,1);
         }

     }*/

}



void DisplaySuites(struct Suite Suites[])
{



    char DisplayGrid[4][13][2];

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<13; j++)
        {
            strcpy(DisplayGrid[i][j],"");

        }
    }
    for (int i=0; i<4; i++)
    {

        AddDisplaySuite(Suites,DisplayGrid,i);
    }


    for(int i=0; i<4; i++)
    {
        printf("%c\t",Suites[i].suiteLetter);
        for(int j=0; j<13; j++)
        {
            printf("%s\t",DisplayGrid[i][j]);

        }
        printf("\n");
    }

}




struct MoveSummary IsValidMove(struct Card*lastCard,struct Card *CardToAdd)
{


    struct MoveSummary movesummary;
    movesummary.isvalid=true;

    strcpy(movesummary.Message,"valid move");
    int currentCardIndex=0;
    int lastCardIndex=0;

    if (CardToAdd==NULL || lastCard==NULL)
    {

        movesummary.isvalid=true;

        strcpy(movesummary.Message,"deck or card does not exists");

    }
    else
    {

        for (int i=0; i<13; i++)
        {

            if(solitaireCards[i]==lastCard->value[0])
            {
                lastCardIndex=i;
            }
            if(solitaireCards[i]==CardToAdd->value[0])
            {
                currentCardIndex=i;
            }
        }
        if(lastCard->color==CardToAdd->color )
        {

            movesummary.isvalid=false;
            strcpy(movesummary.Message,"color match");
        }
        else if (strcmp(lastCard->value,CardToAdd->value)==0)
        {

            movesummary.isvalid=false;
            strcpy(movesummary.Message,"card match");
        }
        else if(CardToAdd->fliped==false)
        {
            movesummary.isvalid=false;
            strcpy(movesummary.Message,"card not visible");
        }
        else if(lastCardIndex<currentCardIndex)
        {
            movesummary.isvalid=false;
            strcpy(movesummary.Message,"card is bigger");
        }

    }


    return movesummary;

}





void AddDisplaySuite(struct Suite Suites[],char DeckGrid[][13][2],int column)
{
    struct    Card *card=Suites[column].cardList;
    int counter=0;
    while (card!=NULL)
    {
        if(card->fliped==true)
        {

            strcpy(DeckGrid[column][counter],card->value);
        }
        else
        {
            strcpy(DeckGrid[column][counter],"[]");

        }

        card=card->Next;
        counter++;
    }


}



void MoveDeckCardsToSuite(struct Game *game)
{
    for (int i=0; i<7; i++)
    {
        struct Card* card= GetCard3(game->Decks[i].cardList);
        if(card!=NULL)
        {
            for (int j=0; j<4; j++)
            {
                struct Card*card1=GetCard3(game->Suites[j].cardList);
                if(card1!=NULL)
                {
                    int suitcardIndex=12;
                    int deckcardIndex=12;
                    for(int k=12; k>0; k--)
                    {
                        if(card1->value[0]==solitaireCards[k])
                        {
                            suitcardIndex=k;
                        }

                        if(card->value[0]==solitaireCards[k])
                        {
                            deckcardIndex=k;
                        }
                    }
                    if(suitcardIndex==deckcardIndex+1 && card->color==card1->color)
                    {
                        AddCardToList(game->Suites[j].cardList,card);
                        int listCounter=ListCount(game->Decks[i].cardList);
                        struct Card* card3= GetCard(game->Decks[i].cardList,listCounter-2);
                        card3->Next=NULL;

                    }

                }
                else
                {

                    int deckcardIndex=12;
                    for(int k=12; k>0; k--)
                    {
                        if(card->value[0]==solitaireCards[k])
                        {
                            deckcardIndex=k;
                        }
                    }

                    if(deckcardIndex==12)
                    {
                        AddCardToList(game->Suites[j].cardList,card);
                        int listCounter=ListCount(game->Decks[i].cardList);
                        if(listCounter-2>=0)
                        {
                            struct Card* card3= GetCard(game->Decks[i].cardList,listCounter-2);
                            card3->Next=NULL;
                        }
                        else
                        {
                            card=NULL;
                        }

                    }

                }
            }
        }

    }


}



void DisplayMovSumMessage(struct  MoveSummary sum)
{


    printf("%s",sum.Message);

}
void DisplayDecks(struct Game * game)
{

    int DeckCounts[7];

    for (int i=0; i<7; i++)
    {
        DeckCounts[i]=ListCount(game->Decks[i].cardList);

    }

    int highestRow= maximumValue(DeckCounts,7);


    char DisplayGrid[highestRow][7][3];
    for(int i=0; i<highestRow; i++)
    {
        for(int j=0; j<7; j++)
        {
            char tmp[2]="";
            strcpy(DisplayGrid[i][j],tmp);
        }

    }

    for (int i=0; i<7; i++)
    {

        AddDisplayDeck(game->Decks[i],DisplayGrid,i);
    }
    printf("\n");
    for (int i=0; i<7; i++)
    {
        printf("C%d\t",i+1);
    }

    printf("\n\n");

    for(int i=0; i<highestRow; i++)
    {
        for(int j=0; j<7; j++)
        {
            printf("%s\t",DisplayGrid[i][j]);

        }
        printf("\n");
    }




}



void AddDisplayDeck(struct Deck _deck,char DeckGrid[][7][3],int column)
{
    if(_deck.cardList!=NULL )
    {

        struct    Card *card=_deck.cardList;
        int counter=0;
        while (card!=NULL)
        {
            if(card->fliped==true)
            {

                strcpy(DeckGrid[counter][column],card->value);
            }
            else
            {
                char tmp[3]="[]";
                tmp[2]='\0';
                //tmp[0]='[';
                // tmp[1]=']';
                //tmp[2]='\0';
                strcpy(DeckGrid[counter][column],tmp);

            }

            card=card->Next;
            counter++;
        }
    }

}




void AddCardsToDeck(struct Deck Decks[],int DeckColumn,int cardCount,int flipedStartIndex)
{


    for (int i=0; i<cardCount; i++)
    {
        if(i==0)
        {
            Decks[DeckColumn].cardList=(struct Card*) malloc(sizeof(struct Card));
            Decks[DeckColumn].cardList->Next=NULL;
            strcpy(Decks[DeckColumn].cardList->value,RandomCardValue1());
            Decks[DeckColumn].cardList->color=Decks[DeckColumn].cardList->value[1];
            if(DeckColumn!=0)
            {
                Decks[DeckColumn].cardList->fliped=false;
            }
            else
            {
                Decks[DeckColumn].cardList->fliped=true;
            }

        }
        else
        {
            struct Card * card=(struct Card*) malloc(sizeof(struct Card));
            card->Next=NULL;
            char cardvalue[2];
            GenerateDiffDeckCard(Decks[DeckColumn].cardList,cardvalue);
            strcpy(card->value,cardvalue);
            card->color=card->value[1];

            if(i<flipedStartIndex)
            {
                card->fliped=false;
            }
            else
            {
                card->fliped=true;
            }
            AddCardToList(Decks[DeckColumn].cardList,card);
        }



    }



}




void GenerateDiffDeckCard(struct Card * cardList, char cardvalue[2])
{

    cardvalue=RandomCardValue1();
    while(strcmp(cardList->value,cardvalue)==0)
    {
        cardvalue=RandomCardValue1();
    }

}



void MoveCardToDeck(struct Game* game,int FinalDeckColumn,int currentDeckColumn,char data[2])
{
    struct   Card * card1=GetCard3(game->Decks[FinalDeckColumn].cardList);
    struct Card * card=GetCard1(game->Decks[currentDeckColumn].cardList,data);
    struct MoveSummary  moveSum= IsValidMove(card1,card);
    if(moveSum.isvalid==false)
    {


    }
    else
    {
        RemoveLastCard(game->Decks[currentDeckColumn].cardList);
        AddCardToList(game->Decks[FinalDeckColumn].cardList,card);

    }

}



void RemoveLastCard(struct Card*cardList)
{

    int listCounter=ListCount(cardList);
    int finalIndex=listCounter-2;
    struct Card* card3= GetCard(cardList,finalIndex);
    if(finalIndex>=0)
    {

        card3->Next=NULL;

    }
    else
    {
        card3=NULL;
    }


}

void ExitGame(){

    exit(0);
}