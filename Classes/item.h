#pragma once
#ifndef __item_H__
#define __item_H__
#include "cocos2d.h"
using namespace cocos2d;

class item :public Node                                 //����ĵ��ߴ���  ������� ҩˮ��Կ�ף�װ��������
{
public:
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
protected:
	Sprite* mySprite;

};
#endif
