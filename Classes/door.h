#pragma once
#ifndef __door_H__
#define __door_H__
#include "cocos2d.h"
using namespace cocos2d;

class door :public Node
{
public:
	Sprite* getSprite();                                   //�Ŵ���  ������ͼ�ţ��赲����ͨ������ҪԿ�״򿪣�
	 void bindSprite(Sprite* sprite);                               //�����ؿ��ţ��л�������
protected:
	Sprite* mySprite;

};
#endif

