class Card
{
public:
    Card(value, suit);
    ~Card();
    int getSuit() const {return suit;};
    int getValue() const {return value;};
    void setSuit(int newSuit);
    void setValue(int newValue);
private:
    int value;
    int suit;
}

Card::Card(startValue, startSuit)
{
    /* initialize card with values */
    value = startValue;
    suit = startSuit;
}

Card::~Card()
{
    //do nothing
}

Card::setSuit(int newSuit)
{
    suit = newSuit;
}

Card::setValue(int value)
{
    value = newValue;
}

class Deck
{
public:
    Deck();
    ~Deck();
    //void shuffle();
    void initializeDeck();
    //void deal();
private:
    Card allCards[52];
}

Deck::Deck()
{

}

Deck::initializeDeck()
{
    enum VALUE {JOKER, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
        EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum SUIT {CLUB, DIAMOND, HEART, SPADE};
    int deckIndex = 0;
    for(int j = CLUB; j <= SPADE; j++) //this loop sets the card suit
    {
        for(int i = ACE; i <= KING; i++) // this loop sets the card value
        {
            allCards[deckIndex].setValue(i);
            allCards[deckIndex].setSuit(j);
            deckIndex++;
        }
    }
}
