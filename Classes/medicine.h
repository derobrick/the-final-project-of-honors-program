#pragma once
#ifndef __medicine_H__
#define __medicine_H__
#include "cocos2d.h"
#include "item.h"
using namespace cocos2d;
class medicine :public item                              //药水大类  继承自道具类
{
public:
	int get_HP();            //调用碰撞函数时需要以主角作为参数传递
private:
	const int HP = 0;
};
class big_medicine :public medicine                          //其中包含两种药水  加血量不同          
{
public:
	CREATE_FUNC(big_medicine);
private:
	const int HP = 500;
};
class small_medicine : public medicine
{
public:
	CREATE_FUNC(small_medicine);
private:
	const int HP = 100;
};
#endif
