#include "equipment.h"
#include "cocos2d.h"
using namespace cocos2d;
void equipment::equipment_contact(Player* myplayer)      
{
	myplayer->Get_Att(this->Atk);
	myplayer->Get_Def(this->Def);
	this->removeFromParentAndCleanup(true);
}