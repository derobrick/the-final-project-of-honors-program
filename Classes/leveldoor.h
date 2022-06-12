#pragma once
#ifndef __leveldoor_H__
#define __leveldoor_H__
#include "cocos2d.h"
#include "door.h"
using namespace cocos2d;
class leveldoor :public door
{
public:

	void bindScene(Scene* scene);  // 关卡门类继承自门类

	CREATE_FUNC(leveldoor);
protected:                                                                //含有特殊的绑定函数  需要场景作为参数
	Scene* myScene;                                                      //调用后会切换当前的场景
};
#endif
