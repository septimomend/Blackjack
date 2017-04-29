// Blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "Game.h"

using namespace std;

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

int main()
{
	cout << "\t\tBlackjack Console Game\n" << endl;
	cout << "For reading rules press 'r' else press any other button: ";
	char rules;
	cin >> rules;
	if (rules == 'r')
	{
		ifstream readme("rules.txt");
		string ruleStr;
		while (readme)
		{
			readme >> ruleStr;
			cout << ruleStr << " ";
		}
		cout << endl;
	}
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1-7) - ";
		cin >> numPlayers;
	}
	vector<string> names;
	string name;
	int number = 1;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter player number " << number << " name: ";
		cin >> name;
		names.push_back(name);
		number++;
	}
	cout << endl;
	// cycle of game
	//
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		system("cls");
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}
	cout << "Good luck!" << endl;
    return 0;
}

