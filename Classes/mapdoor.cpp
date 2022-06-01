#include "mapdoor.h"
#include "cocos2d.h"
using namespace cocos2d;
void RedMapDoor::contact_RedMapDoor(Player* myplayer)
{
	if (myplayer->Look_RedKey() >= 0)
	{
		this->removeFromParentAndCleanup(true);
		myplayer->Use_RedKey();
	}
}
void YellowMapDoor::contact_YellowMapDoor(Player* myplayer)
{
	if (myplayer->Look_YellowKey() >= 0)
	{
		this->removeFromParentAndCleanup(true);
		myplayer->Use_YellowKey();
	}
}
void BlueMapDoor::contact_BlueMapDoor(Player* myplayer)
{
	if (myplayer->Look_BlueKey() >= 0)
	{
		this->removeFromParentAndCleanup(true);
		myplayer->Use_BlueKey();
	}
}