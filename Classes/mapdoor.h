#pragma once
#ifndef __mapdoor_H__
#define __mapdoor_H__
#include "cocos2d.h"
#include "door.h"
using namespace cocos2d;
class mapdoor :public door                                //关卡门继承自门大类
{
};
class BlueMapDoor :public mapdoor                        //其中包含三种不同颜色门
{
public:
	CREATE_FUNC(BlueMapDoor);
};
class RedMapDoor :public mapdoor
{
public:
	CREATE_FUNC(RedMapDoor);
};
class YellowMapDoor :public mapdoor
{
public:
	CREATE_FUNC(YellowMapDoor);
};


#endif
