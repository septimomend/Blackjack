// Game.h >> declaration of class Game
// represent game Blackjack
#ifndef GAME_H
#define GAME_H
#include "stdafx.h"
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
public:
	Game(const std::vector<std::string>& names);
	~Game();
	void Play(); // play game
private:
	Deck m_Deck;
	House m_House;
	std::vector<Player> m_Players;
};

#endif // !GAME_H
