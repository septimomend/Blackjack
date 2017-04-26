// GenericPlayer.cpp >> declaration of class defined in GenericPlayer.h
#include "GenericPlayer.h"

using namespace std;

GenericPlayer::GenericPlayer(string name) : m_Name(name)
{
}

GenericPlayer::~GenericPlayer()
{
}

bool GenericPlayer::IsBusted() const
{
	return (GetTotal() > 21); // return true or false when player sum of cards is more 21 scores
}

void GenericPlayer::Bust() const
{
	cout << m_Name << " busts." << endl;
}