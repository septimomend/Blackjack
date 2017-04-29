// Blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

using namespace std;

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

int main()
{
	cout << "\t\tBlackjack Console Game\n" << endl;
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1-7) - ";
		cin >> numPlayers;
	}
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		int number = 1;
		cout << "Enter player number " << number << " name: ";
		cin >> name;
		names.push_back(name);
		number++;
	}
	cout << endl;
	// cycle of game
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		system("cls");
		aGame.Play();
		cout << "/nDo you want to play again& (Y/N): ";
		cin >> again;
	}
	cout << "Good luck!" << endl;
    return 0;
}

