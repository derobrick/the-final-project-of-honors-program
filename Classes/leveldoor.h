#pragma once
#ifndef __leveldoor_H__
#define __leveldoor_H__
#include "cocos2d.h"
#include "door.h"
using namespace cocos2d;
class leveldoor :public door
{
public:
	void contact_leveldoor();

	void bindSpriteAndScene(Sprite* sprite,Scene* scene);  // �ؿ�����̳�������

	CREATE_FUNC(leveldoor);
protected:                                                                //��������İ󶨺���  ��Ҫ�����Լ�������Ϊ����
	 Scene* myScene;                                                      //���ú���л���ǰ�ĳ���
};


#endif
