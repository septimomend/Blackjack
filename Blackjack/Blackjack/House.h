// House.h >> declaration of class House inherited from class GenericPlayer (GenericPlayer.h/.cpp)
// class House represents dealer (casino, computer-player).
#ifndef HOUSE_H
#define HOUSE_H
#include "stdafx.h"
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const std::string& name = "House");
	virtual ~House();
	virtual bool IsHitting() const;  // show whether palyer want to continue take cards
	void FlipFirstCard(); // overturning first card
};


#endif // !HOUSE_H
