#include <iostream>
#include "deck.hpp"
#include <string>


using namespace std;

enum SUIT {CLUB, DIAMOND, HEART, SPADE};
enum VALUE {JOKER, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING};
void setBlackJackValues();
void displayCardInfo(Card);
//bool containsAce(Card);

int main()
{
    //makes the seed for time (can't put anywhere else)
    srand((int)time(0));
    Deck Bicycle;
    setBlackJackValues(Bicycle);
    bool gameWon = false;
    bool gamePlaying = true;
    const int SIZE = 20;
    Card playerCards[SIZE];
    Card dealerCards[SIZE];
    string userCommand;
    int playerSum = 0;
    int dealerSum = 0;
    int playerIndex = 2;
    int dealerIndex = 2;
    for(int i; i < 2; i++)
    {
        //dealer and player draw two cards
        playerCards[i] = Bicycle.dealCard();
        std::cout << "You: ";
        displayCardInfo(playerCards[i]);
        dealerCards[i] = Bicycle.dealCard();
        playerSum += playerCards[i].getValue();
        dealerSum += dealerCards[i].getValue();
    }
    if(dealerSum == 21)
    {
        gamePlaying = false;
        gameWon = false;
        std::cout << "Dealer got 21. You lose. \n";
    }
    while(gamePlaying)
    {
        if(playerSum == 21)
        {
            gamePlaying = false;
            gameWon = true;
        }
        else if(playerSum < 21)
        {
            std::cout << "Would you like you hit or stand? ";
            std::cout << "(type hit or stand)\n";
            std::cin >> userCommand;
            if(userCommand == "hit")
            {
                playerCards[playerIndex] = Bicycle.dealCard();
                std::cout << "You: ";
                displayCardInfo(playerCards[playerIndex]);
                playerSum += playerCards[playerIndex].getValue();
                playerIndex++;
            }
            else if(userCommand == "stand")
            {
                std::cout << "You stand. \n";
                std::cout << "Dealer: ";
                displayCardInfo(dealerCards[0]);
                displayCardInfo(dealerCards[1]);
                while(dealerSum <= 18)
                {
                    std::cout << "The dealer hit. ";
                    dealerCards[dealerIndex] = Bicycle.dealCard();
                    displayCardInfo(dealerCards[dealerIndex]);
                    dealerSum += dealerCards[dealerIndex].getValue();
                    dealerIndex++;
                }
                if(dealerSum > playerSum && dealerSum <= 21)
                {
                    gameWon = false;
                    gamePlaying = false;
                }
                else
                {
                    gameWon = true;
                    gamePlaying = false;
                }

            }
            else
            {
                std::cout << "Did not understand command.\n";
            }
        }
        else
        {
            std::cout << "You bust. The dealer had ";
            std::cout << dealerSum;
            gameWon = false;
            gamePlaying = false;
        }
    }
    if(gameWon){
        std::cout << "You won!\n";
    }
    else
    {
        std::cout <<"You lost.\n";
    }
    return 0;
}

void displayCardInfo(Card inputCard)
{
    std::cout << "delt a " << inputCard.getNameValue();
    std::cout << " of " << inputCard.getNameSuit() << ".\n";
}


void setBlackJackValues(Deck cardDeck)
{
    //sets the values of all the jacks, kings, and queens to 10
    for(int i = 0; i < 52; i++)
    {
        if(cardDeck.getCard(i).getValue > 10)
        {
            cardDeck.getCard(i).setValue(10);
        }
    }
}
