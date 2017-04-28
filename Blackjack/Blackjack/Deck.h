// Deck.h >> definition of class Deck, representing deck of cards.
// Inherited from class Hand placed in Hand.h/.cpp files
#ifndef DECK_H
#define DECK_H
#include "stdafx.h"
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();
	void Generate(); // create standard deck of 52 cards
	void Shuffle(); // shuffle cards
	void Deal(Hand& aHand); // hand one card around
	void AdditionalCards(GenericPlayer& aGenericPlayer); // give additional cards for player
};

#endif // !DECK_H
