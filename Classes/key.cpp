#include "key.h"
#include "cocos2d.h"
using namespace cocos2d;
void YellowKey::contact_YellowKey(Player* myplayer)
{
	myplayer->Get_YellowKey();
	this->removeFromParentAndCleanup(true);
}
void RedKey::contact_RedKey(Player* myplayer)
{
	myplayer->Get_RedKey();
	this->removeFromParentAndCleanup(true);
}
void BlueKey::contact_BlueKey(Player* myplayer)
{
	myplayer->Get_BlueKey();
	this->removeFromParentAndCleanup(true);
}