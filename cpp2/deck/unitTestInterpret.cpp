#include <iostream>
#include "deck.hpp"

void blackJackInterpret(Deck&);

int main()
{
    Deck testDeck(true);
    testDeck.showDeck();
    blackJackInterpret(testDeck);
    testDeck.showDeck();

    return 0;
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
