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
	bool introduce = true;
	while (introduce)
	{
		system("cls");
		cout << "Warning! \nBefore clicking proposed by game keys, please, enable CapsLock." << endl;
		cout << "\nFor reading rules press <E>" << endl;
		cout << "\nOr press any key to play game." << endl;
		ifstream readme("rules.txt");
		string ruleStr;
		switch (_getch())
		{
		case E:
			system("cls");
			while (readme)
			{
				readme >> ruleStr;
				cout << ruleStr << " ";
			}
			cout << endl;
			cout << "\nPress any key to return back." << endl;
			_getch();
			break;
		default:
			introduce = false;
			system("cls");
			break;
		}
	}
	int numPlayers = 0;
	cout << "\t\t\3\4 Blackjack Console Game \5\6\n" << endl;
	cout << "Welcome to my virtual casino, ladies and gentlemen. Now we play Blackjack. Join us!\n" << endl;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "\nHow many of you are there? There are only 7 places, sorry if someone is missing. (1-7) - ";
		cin >> numPlayers;
	}
	vector<string> names;
	string name;
	int number = 1;
	cout << endl;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "So, player num. " << number << ", introduce yourself, please: ";
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
		cout << "\nPlay again? Press <Y>/<N>" << endl;
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
			cout << "\nGood luck, ladies and gentlemen!" << endl;
			break;
		}
	}
    return 0;
}

