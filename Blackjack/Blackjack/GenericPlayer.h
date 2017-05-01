// GenericPlayer.h >> declaration of class GenericPlayer. 
// This abstract class that represent common elements of human-player and computer-player
#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include "stdafx.h"
#include "Hand.h"

class GenericPlayer : public Hand
{
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
public:
	GenericPlayer(const std::string name = "");
	virtual ~GenericPlayer(); // dstr is auto virtal because this is inheritanced from class Hand. I just write virtual for remember it
	virtual bool IsHitting() const = 0; // show whether palyer want to continue take cards. This is pure virtual function means
										// that I will declare it in inheritance  classes with different declaration
	bool IsBusted() const; // return value when player have a bust - sum is more 21
	void Bust() const; // declare that player have a bust
protected:
	std::string m_Name;
};


#endif // !GENERICPLAYER_H
