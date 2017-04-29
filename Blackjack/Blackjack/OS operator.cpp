// OS operator.cpp >> overriding output stream operator
#include "stdafx.h"
#include "Card.h"
#include "GenericPlayer.h"

using namespace std;

ostream& operator<<(ostream& os, const Card& aCard)
{
	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" }; // first is 0 because rank begins from 1
	const string SUIT[] = { "c", "d", "h", "s" };
	if (aCard.m_IsFaceUp)
		os << RANKS[aCard.m_Rank] << SUIT[aCard.m_Suit];
	else
		os << "XX";
	return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty())
	{
		for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard)
			os << *(*pCard) << "\t";
		if (aGenericPlayer.GetTotal() != 0)
			cout << "(" << aGenericPlayer.GetTotal() << ")";
	}
	else
		os << "<empty>";
	return os;
}