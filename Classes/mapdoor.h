#pragma once
#ifndef __mapdoor_H__
#define __mapdoor_H__
#include "cocos2d.h"
#include "door.h"
using namespace cocos2d;
class mapdoor :public door                                //�ؿ��ż̳����Ŵ���
{
};
class BlueMapDoor :public mapdoor                        //���а������ֲ�ͬ��ɫ��
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
