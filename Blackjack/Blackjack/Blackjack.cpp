// Blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "Game.h"
#define E 69
using namespace std;

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

int main()
{
	cout << "\t\t\3\4 Blackjack Console Game \5\6\n" << endl;
	cout << "For reading rules press <Shift>+<E>" << endl;
	ifstream readme("rules.txt");
	string ruleStr;
	switch (_getch())
	{
	case E:
		while (readme)
		{
			readme >> ruleStr;
			cout << ruleStr << " ";
		}
		cout << endl;
		break;
	default:
		break;
	}
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "\nHow many players? (1-7) - ";
		cin >> numPlayers;
	}
	system("cls");
	vector<string> names;
	string name;
	int number = 1;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter player's name #" << number << ": ";
		cin >> name;
		names.push_back(name);
		number++;
	}
	cout << endl;
	// cycle of game
	//
	Game aGame(names);
	bool again = true;
	system("cls");
	cout << "\t\t\3\4 Blackjack Console Game \5\6\n" << endl;
	aGame.Play();
	while (again)
	{
		cout << "\nPlay again? Press <Shift>+<Y>/<N>" << endl;
		switch (_getch())
		{
		case Y:
			system("cls");
			cout << "\t\t\3\4 Blackjack Console Game \5\6\n" << endl;
			aGame.Play();
			again = true;
			break;
		case N:
			again = false;
			cout << "\nAdieu!" << endl;
			break;
		}
	}
    return 0;
}

