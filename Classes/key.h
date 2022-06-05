#pragma once
#ifndef __key_H__
#define __key_H__
#include "cocos2d.h"
#include"player.h"
#include "item.h"
using namespace cocos2d;
class key :public item                                        //Կ���� �̳��Ե�����
{                                                             
};
class YellowKey :public key                                 //���ֲ�ͬ��ɫ��Կ�� �̳���Կ����
{
public:
	void contact_YellowKey(Player* myplayer);               //������ײ�¼�ʱ��������Ϊ����
	CREATE_FUNC(YellowKey);
};
class RedKey :public key
{
public:
	void contact_RedKey(Player* myplayer);
	CREATE_FUNC(RedKey);
};
class BlueKey :public key
{
public:
	void contact_BlueKey(Player* myplayer);
	CREATE_FUNC(BlueKey);
};
#endif
