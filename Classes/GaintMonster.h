#pragma once
#include"Monster.h"
class Gaint :public Monster
{
public:
	
	//��ȡ�Ƿ���Ѫ
	virtual bool getSuck();
	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();
	int suckRate;
	//������� �ж��Ƿ񴥷�
	bool isTriggle(int rate);

};

class Gaintone :public Gaint
{
	Gaintone();
	~Gaintone();
	CREATE_FUNC(Gaintone);
};
class Gainttwo :public Gaint
{
	Gainttwo();
	~Gainttwo();
	CREATE_FUNC(Gainttwo);
};

