#pragma once
#ifndef __key_H__
#define __key_H__
#include "cocos2d.h"
#include "item.h"
using namespace cocos2d;
class key :public item                                        //钥匙类 继承自道具类
{
};
class YellowKey :public key                                 //三种不同颜色的钥匙 继承自钥匙类
{
public:
	CREATE_FUNC(YellowKey);
};
class RedKey :public key
{
public:
	CREATE_FUNC(RedKey);
};
class BlueKey :public key
{
public:
	CREATE_FUNC(BlueKey);
};
#endif
