// Player.h >> declaration of class Player
// represent player human
#ifndef PLAYER_H
#define PLAYER_H
#include "stdafx.h"
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
	Player(const std::string& name = "");
	virtual ~Player();
	virtual bool IsHitting() const; // show whether palyer want to continue take cards
	void Win() const; // if player win
	void Lose() const; // if palyer lose
	void Push() const; // when player and computer have equal number of scores this is push
};

#endif // !PLAYER_H
