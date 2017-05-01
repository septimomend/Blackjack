// Hand.cpp >> definition of class Hand
#include "stdafx.h"
#include "Hand.h"

using namespace std;

Hand::Hand()
{
	m_Cards.reserve(7); // reserving space in vector
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	vector<Card*>::iterator iter = m_Cards.begin();
	// pass all vector and delete memory on heap
	//
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete *iter;
		*iter = 0;
	}
	m_Cards.clear(); // clear vector of pointers
}

int Hand::GetTotal() const
{
	if (m_Cards.empty()) // if no one card in hand return 0
		return 0;
	if (m_Cards[0]->GetValue() == 0) // if first card is 0 - card face is down
		return 0;
	// sum of all cards, every ace is 1 score
	//
	int total = 0; 
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		total += (*iter)->GetValue();
	// check whether hand holds ace
	//
	bool containAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
			containAce = true;
	}
	// if hand holds ace and sum of cards is small - ace is 11 scores
	//
	if (containAce && total <= 11)
		total += 10; // add 10 scores because we already have 1 score for every ace
	return total;
}