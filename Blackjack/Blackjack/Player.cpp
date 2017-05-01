// Player.cpp >> definition of class Player defined in Player.h
#include "stdafx.h"
#include "Player.h"

using namespace std;

Player::Player(const string& name) : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::IsHitting() const
{
	cout << m_Name << ", do you want a hit? Press <Shift>+<Y>/<N>" << endl;
	/*char response;
	cin >> response;
	return (response == 'y' || response == 'Y'); // if player wants to hit and press 'y' or 'Y' return true, else return false*/
	switch (_getch())
	{
	case Y:
		return true;
		break;
	default:
		return false;
		break;
	}
}

void Player::Win() const
{
	cout << m_Name << " wins." << endl;
}

void Player::Lose() const
{
	cout << m_Name << " loses." << endl;
}

void Player::Push() const
{
	cout << m_Name << " pushes." << endl;
}