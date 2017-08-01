#include <cstdlib>
#include <ctime>

using namespace std;

enum SUIT {CLUB, DIAMOND, HEART, SPADE};
enum VALUE {JOKER, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING};

int random(int start, int end);

class Card
{
public:
    //Card(int startValue, int startSuit);
    //~Card();
    int getSuit() const {return suit;};
    int getValue() const {return value;};
    void setSuit(int newSuit) {suit = newSuit;};
    void setValue(int newValue) {value = newValue;};
    void interpretCard();
    string getNameValue() const {return nameValue;};
    string getNameSuit() const {return nameSuit;};
private:
    int value;
    int suit;
    string nameValue;
    string nameSuit;
};
/*
Card::Card(int startValue, int startSuit)
{
    initialize card with values
    value = startValue;
    suit = startSuit;
}

Card::~Card()
{
    //do nothing
}
*/
void Card::interpretCard()
{
    switch(suit)
    {
        case CLUB:
            nameSuit = "Clubs";
            break;
        case DIAMOND:
            nameSuit = "Diamonds";
            break;
        case HEART:
            nameSuit = "Hearts";
            break;
        case SPADE:
            nameSuit = "Spades";
            break;
        default:
            nameSuit = "Jokers";
    }
    switch(value)
    {
        case ACE:
            nameValue = "ace";
            break;
        case TWO:
            nameValue = "two";
            break;
        case THREE:
            nameValue = "three";
            break;
        case FOUR:
            nameValue = "four";
            break;
        case FIVE:
            nameValue = "five";
            break;
        case SIX:
            nameValue = "six";
            break;
        case SEVEN:
            nameValue = "seven";
            break;
        case EIGHT:
            nameValue = "eight";
            break;
        case NINE:
            nameValue = "nine";
            break;
        case TEN:
            nameValue = "ten";
            break;
        case JACK:
            nameValue = "Jack";
            break;
        case QUEEN:
            nameValue = "Queen";
            break;
        case KING:
            nameValue = "King";
            break;
        default:
            nameValue = "joker";
    }
}

class Deck
{
public:
    Deck(bool);
    ~Deck();
    Card dealCard();
    Card getCard(int index) const{return cardSlots[index];};
    void setCard(int index, Card inputCard){cardSlots[index] = inputCard;};
    void setTopCard(Card);
    void showDeck();
    int getDeckSize() const {return deckSize;};
private:
    Card cardSlots[52];
    int deckSize;
};

Deck::Deck(bool fullDeck)
{
    if(fullDeck) //if the user specified for the deck to be full
    {
        //fills every card with a value
        deckSize = 0;
        for(int j = CLUB; j <= SPADE; j++) //this loop sets the card suit
        {
            for(int i = ACE; i <= KING; i++) // this loop sets the card value
            {
                cardSlots[deckSize].setValue(i);
                cardSlots[deckSize].setSuit(j);
                cardSlots[deckSize].interpretCard();
                deckSize++;
            }
        }
    }
    else
    {
        deckSize = 0; //sets the top card to be the first one.
    }
}

Deck::~Deck()
{
    //destructor
}


Card Deck::dealCard()
{
    int cardIndex = random(0,51);
    // eventually remove card from stack for realism
    return cardSlots[cardIndex];
}

void Deck::setTopCard(Card topCard)
{
    // if the deck isn't full, set the top card to inputted card
    if(deckSize < 52)
    {
        cardSlots[deckSize] = topCard;
        deckSize++;
    }
}
void Deck::showDeck()
{
     // method is only to ensure the deck was loaded properly.
    int deckIndex = 0;
    for(int j = CLUB; j <= SPADE; j++) //this loop gets the card suit
    {
        for(int i = ACE; i <= KING; i++) // this loop gets the card value
        {
            std::cout << "The " << deckIndex + 1 << " card value is ";
            std::cout << cardSlots[deckIndex].getValue() << ",";
            std::cout << " and the suit is ";
            std::cout << cardSlots[deckIndex].getSuit() << ".\n";
            deckIndex++;
        }
    }
}


int random(int start, int end)
{
    int r = (rand() % end) + start;
	return r;
}
