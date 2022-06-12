#pragma once
#ifndef __equipment_H__
#define __equipment_H__
#include "cocos2d.h"
#include "item.h"
#include"player.h"
using namespace cocos2d;
class equipment :public item
{
public:
	int get_Atk();
	int get_Def();
	//装备大类   包括两种 宝石和道具
private:                                                              //分别提供不同的攻击力以及防御力
	const int Atk = 0;                                                  //调用其碰撞事件时需要将主角作为参数
	const int Def = 0;
};
class sword :public equipment
{
public:
	CREATE_FUNC(sword);
private:
	const int Atk = 10;
	const int Def = 0;
};
class shield :public equipment
{
public:
	CREATE_FUNC(shield);
private:
	const int Atk = 0;
	const int Def = 10;
};
class Atk_gem :public equipment
{
public:
	CREATE_FUNC(Atk_gem);
private:
	const int Atk = 5;
	const int Def = 0;
};
class Def_gem :public equipment
{
public:
	CREATE_FUNC(Def_gem);
private:
	const int Atk = 0;
	const int Def = 10;
};
#endif
