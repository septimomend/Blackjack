#include "stdafx.h"
#include "House.h"

using namespace std;

House::House(const string& name) : GenericPlayer(name)
{
}

House::~House()
{
}

bool House::IsHitting() const
{
	return (GetTotal() <= 16); // if there is less of 16 scores hit the card
}

void House::FlipFirstCard()
{
	// check excistense of card
	//
	if (!(m_Cards.empty()))
		m_Cards[0]->Flip();
	else
		cout << "> FlipFirstCard(): No card to flip." << endl;
}