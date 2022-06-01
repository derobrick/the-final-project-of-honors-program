#pragma once
#ifndef __door_H__
#define __door_H__
#include "cocos2d.h"
using namespace cocos2d;

class door :public Node
{
public:
	Sprite* getSprite();                                   //门大类  包含地图门（阻挡主角通过，需要钥匙打开）
	 void bindSprite(Sprite* sprite);                               //包含关卡门（切换层数）
protected:
	Sprite* mySprite;

};
#endif

