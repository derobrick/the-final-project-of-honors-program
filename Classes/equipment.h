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
	//װ������   �������� ��ʯ�͵���
private:                                                              //�ֱ��ṩ��ͬ�Ĺ������Լ�������
	const int Atk = 0;                                                  //��������ײ�¼�ʱ��Ҫ��������Ϊ����
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
