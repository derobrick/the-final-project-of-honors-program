#pragma once
#include"Monster.h"
class Gaint :public Monster
{
public:
	Gaint();
	~Gaint();
	//��ȡ�Ƿ���Ѫ
	virtual bool getSuck();
	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();
	int suckRate;
	//������� �ж��Ƿ񴥷�
	bool isTriggle(int rate);
	virtual void Attack(Player* player);
	CREATE_FUNC(Gaint);
};
