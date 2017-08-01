#include <iostream>
#include <string>
#include "deck.hpp"

int calculateDeckSum(Deck&);
bool containsAce(Deck&, int&);
void blackJackInterpret(Deck&);
void showCardValue(Card);
void blackJackDeal(Deck &playerHand, Deck &gameDeck,
                    int &playerSum, bool showValue);
int main()
{
    srand((int)time(0));
    Deck Bicycle(true);
    blackJackInterpret(Bicycle);
    Deck Player(false);
    Deck Dealer(false);
    string playerInput;
    int playerSum;
    int dealerSum;
    for(int i = 0; i < 2; i++)
    {
        // deal the dealer and the player two cards
        std::cout << "You were ";
        blackJackDeal(Player, Bicycle, playerSum, true);
        blackJackDeal(Dealer, Bicycle, dealerSum, false);
    }
    bool gameWon = false;
    while(true)
    {
        if(playerSum > 21)
        {
            std::cout << "You bust.\n";
            break;
        }
        else if(playerSum == 21)
        {
            gameWon = true;
            break;
        }
        else
        {
            std::cout << "would you like to hit? (type \"hit\" to hit ";
            std::cout << "or \"stand\" to stand.) \n";
            std::cin >> playerInput;
            if(playerInput == "hit")
            {
                std::cout << "You were ";
                blackJackDeal(Player, Bicycle, playerSum, true);
            }
            else if(playerInput == "stand")
            {
                std::cout << "You stand.\nThe dealer has been ";
                for(int i = 0; i < 2; i++)
                {
                    showCardValue(Dealer.getCard(i));
                }
                std::cout << "The dealer is about to draw.\n";
                while(dealerSum < 18)
                {
                    std::cout << "The dealer was ";
                    blackJackDeal(Dealer, Bicycle, dealerSum, true);
                }
                if(dealerSum > 21)
                {
                    std::cout << "The dealer bust!\n";
                    gameWon = true;
                    break;
                }
                if(dealerSum > playerSum)
                {
                    gameWon = false;
                    break;
                }
                else
                {
                    gameWon = true;
                    break;
                }

            }
            else
            {
                std::cout << "Did not understand input.";
            }
        }
    }
    if(gameWon)
    {
        std::cout << "You won!\n";
    }
    else
    {
        std::cout << "You lost.\n";
    }
}

int calculateDeckSum(Deck &rInputDeck)
{
    int deckSum = 0;
    int size = rInputDeck.getDeckSize();
    Card currentCard;
    int aceIndex; // this value is changed by reference in containsAce()
    for(int i = 0; i <= size; i++)
    {
        // get the subsequent card
        currentCard = rInputDeck.getCard(i);
        // add its value to the running total
        deckSum += currentCard.getValue();
    }
    // if the total amount is greater than 21, and contains an ace
    if(deckSum > 21 && containsAce(rInputDeck, aceIndex))
    {
        //store card in variable
        currentCard = rInputDeck.getCard(aceIndex);
        //set card value to one
        currentCard.setValue(1);
        //recalculate the sum of the deck
        deckSum = calculateDeckSum(rInputDeck);
    }
    //std::cout << "Deck sum is " << deckSum << "\n";
    return deckSum;
}

void blackJackInterpret(Deck &cardDeck)
{
    //sets the values of all the jacks, kings, and queens to 10
    //and the aces to 11
    int size = cardDeck.getDeckSize();
    Card tempCard;
    for(int i = 0; i < size; i++)
    {
        tempCard = cardDeck.getCard(i);
        if(tempCard.getValue() > 10)
        {
            tempCard.setValue(10);
        }
        if(tempCard.getValue() == 1)
        {
            tempCard.setValue(11);
        }
        cardDeck.setCard(i, tempCard);
    }
}

bool containsAce(Deck &inputDeck, int &rAceIndex )
{
    int size = inputDeck.getDeckSize();
    Card currentCard;
    bool aceFound = false;
    for (int i = 0; i <= size; i++)
    {
        if(currentCard.getValue() == 11)
        {
            aceFound = true;
            //changes variable outside of function through reference
            rAceIndex = i;
        }
    }
    return aceFound;
}

void showCardValue(Card inputCard)
{
    std::cout << "dealt a " << inputCard.getNameValue();
    std::cout << " of " << inputCard.getNameSuit() << ".\n";
}

void blackJackDeal(Deck &playerHand, Deck &gameDeck,
                    int &playerSum, bool showValue)
{
    Card cardDelt;
    cardDelt = gameDeck.dealCard();
    playerHand.setTopCard(cardDelt);
    if(showValue)
    {
        showCardValue(cardDelt);
    }
    playerSum = calculateDeckSum(playerHand);
}
