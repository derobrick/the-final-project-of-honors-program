#pragma once
#ifndef __medicine_H__
#define __medicine_H__
#include "cocos2d.h"
#include "item.h"
#include"player.h"
using namespace cocos2d;
class medicine :public item                              //ҩˮ����  �̳��Ե�����
{
public:
	void contact_medicine(Player* myplayer);             //������ײ����ʱ��Ҫ��������Ϊ��������
private:
	const int HP = 0;
};
class big_medicine :public item                          //���а�������ҩˮ  ��Ѫ����ͬ          
{
public:
	CREATE_FUNC(big_medicine);
private: 
	const int HP = 500;
};
class small_medicine : public item
{
public:
	CREATE_FUNC(small_medicine);
private:
	const int HP = 100;
};
#endif
