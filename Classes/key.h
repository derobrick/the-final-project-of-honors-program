#pragma once
#ifndef __key_H__
#define __key_H__
#include "cocos2d.h"
#include "item.h"
using namespace cocos2d;
class key :public item                                        //Կ���� �̳��Ե�����
{
};
class YellowKey :public key                                 //���ֲ�ͬ��ɫ��Կ�� �̳���Կ����
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
