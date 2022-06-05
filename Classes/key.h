#pragma once
#ifndef __key_H__
#define __key_H__
#include "cocos2d.h"
#include"player.h"
#include "item.h"
using namespace cocos2d;
class key :public item                                        //钥匙类 继承自道具类
{                                                             
};
class YellowKey :public key                                 //三种不同颜色的钥匙 继承自钥匙类
{
public:
	void contact_YellowKey(Player* myplayer);               //调用碰撞事件时将主角作为参数
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
