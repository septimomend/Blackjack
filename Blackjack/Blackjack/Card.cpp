#include "stdafx.h"
#include "Card.h"

using namespace std;

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{
}

int Card::GetValue() const
{
	int value = 0;
	if (m_IsFaceUp) // if card is face down it's false
	{
		value = m_Rank; // value of card rank
		// value is equal 10 for open cards
		if (value > 10)
			value = 10;
	}
	return value;
}

void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp); // overturning card
}