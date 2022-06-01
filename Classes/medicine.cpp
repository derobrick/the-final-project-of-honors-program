#include "medicine.h"
#include "cocos2d.h"
using namespace cocos2d;
void medicine::contact_medicine(Player* myplayer)
{
	myplayer->Get_Hp(this->HP);
	this->removeFromParentAndCleanup(true);
}