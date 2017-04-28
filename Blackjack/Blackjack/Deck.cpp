// Deck.cpp >> definition of class Deck.h
#include "stdafx.h"
#include "Deck.h"

using namespace std;

Deck::Deck()
{
	m_Cards.reserve(52);
	Generate();
}

Deck::~Deck()
{
}

void Deck::Generate()
{
	Clear();
	// create standard deck
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back()); // send copy of adress of aHand to the end of vector
		m_Cards.pop_back(); // and delete this pointer
	}
	else
		cout << "> Deal(): Out of cards. Unable to deal." << endl;
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	cout << endl;
	// continue to deal cards until player is not busted or player want to hit one more card
	// 
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		if (aGenericPlayer.IsBusted())
			aGenericPlayer.Bust;
	}
}