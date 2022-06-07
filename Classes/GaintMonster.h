#pragma once
#include"Monster.h"
class Gaint :public Monster
{
public:
	Gaint();
	~Gaint();
	//获取是否吸血
	virtual bool getSuck();
	//获取是否暴击
	virtual bool getCrit();
	int suckRate;
	//传入概率 判断是否触发
	bool isTriggle(int rate);
	virtual void Attack(Player* player);
	CREATE_FUNC(Gaint);
};
