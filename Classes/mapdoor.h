#pragma once
#ifndef __mapdoor_H__
#define __mapdoor_H__
#include "cocos2d.h"
#include "door.h"
#include"Player.h"
using namespace cocos2d;
class mapdoor :public door                                //关卡门继承自门大类
{
};
class BlueMapDoor :public mapdoor                        //其中包含三种不同颜色门
{
public:
	void contact_BlueMapDoor(Player* myplayer);           //调用其碰撞函数是 要以主角为参数 并判断是否含有相应的钥匙
};
class RedMapDoor :public mapdoor
{
public:

	void contact_RedMapDoor(Player* myplayer);
};
class YellowMapDoor :public mapdoor
{
public:
	void contact_YellowMapDoor(Player* myplayer);
};


#endif
