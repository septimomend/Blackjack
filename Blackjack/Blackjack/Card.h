#ifndef CARD_H
#define CARD_H
#include "stdafx.h"

class Card
{
public:
	enum rank // rank of card
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING
	};
	enum suit // suit of card
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};
	friend std::ostream& operator<<(std::ostream& os, const Card& aCard); // overloading output operator
	Card(rank r = ACE, suit s = SPADES, bool ifu = true); // cnstr
	int GetValue() const; // return value of card from 1 to 11
	void Flip();  // overturning card
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

#endif // !CARD_H
