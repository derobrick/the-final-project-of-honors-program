#include"Monster.h"
class Boss :public Monster
{
public:
	//��ȡ�Ƿ���Ѫ
	virtual bool getSuck();
	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();
	int suckRate;
	int critRate;
	//������� �ж��Ƿ񴥷�
	bool isTriggle(int rate);

};
class Bossone :public Boss
{
	Bossone();
	~Bossone();
	CREATE_FUNC(Bossone);
};
class Bosstwo :public Boss
{
	Bosstwo();
	~Bosstwo();
	CREATE_FUNC(Bosstwo);
};
