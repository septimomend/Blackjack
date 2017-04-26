// class Hand works with collection of cards
#ifndef HAND_H
#define HAND_H
#include "Card.h"

class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Card* pCard); // add card to hand. Add pointer of Card object to vector
	void Clear(); // clear hand from cards
	int GetTotal() const; // gets value of card from 1 to 11
protected:
	std::vector<Card*> m_Cards; // collection of cards, save pointers of Card objects
};

#endif // !HAND_H
