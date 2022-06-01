#pragma once
#ifndef __mapdoor_H__
#define __mapdoor_H__
#include "cocos2d.h"
#include "door.h"
#include"Player.h"
using namespace cocos2d;
class mapdoor :public door                                //�ؿ��ż̳����Ŵ���
{
};
class BlueMapDoor :public mapdoor                        //���а������ֲ�ͬ��ɫ��
{
public:
	void contact_BlueMapDoor(Player* myplayer);           //��������ײ������ Ҫ������Ϊ���� ���ж��Ƿ�����Ӧ��Կ��
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
