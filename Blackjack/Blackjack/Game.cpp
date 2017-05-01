// Game.cpp >> definition of class Game placed in Game.h file
#include "stdafx.h"
#include "Game.h"

using namespace std;

Game::Game(const vector<string>& names)
{
	vector<string>::const_iterator pName;
	// create vector of players from vector of names. Create Player object for each name
	//
	for (pName = names.begin(); pName != names.end(); ++pName)
		m_Players.push_back(Player(*pName));
	// random generator
	//
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Generate();
	m_Deck.Shuffle();
}

Game::~Game()
{
}

void Game::Play()
{
	vector<Player>::iterator pPlayer;
	// deal two cards for everybody
	//
	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			m_Deck.Deal(*pPlayer);
		m_Deck.Deal(m_House);
	}
	m_House.FlipFirstCard(); // hide first diller's card
	// open all player's hands
	//
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		cout << *pPlayer << endl;
	cout << m_House << endl;
	// deal additional cards for players
	//
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.AdditionalCards(*pPlayer);
	}
	cout << "\nTable now:" << endl;
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		cout << *pPlayer << endl;
	m_House.FlipFirstCard(); // show diller's first card
	cout << endl << m_House;
	m_Deck.AdditionalCards(m_House); // deal additional cards for diller
	cout << endl;
	if (m_House.IsBusted())
	{
		// all players remained at game are winners
		//
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
				pPlayer->Win();
		}
	}
	else
	{
		// compare sum of remaining player's scores and sum of diller's scores
		//
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				if (pPlayer->GetTotal() > m_House.GetTotal())
					pPlayer->Win();
				else if (pPlayer->GetTotal() < m_House.GetTotal())
					pPlayer->Lose();
				else
					pPlayer->Push();
			}
		}
	}
	// clear all player's hands
	//
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		pPlayer->Clear();
	m_House.Clear();
}