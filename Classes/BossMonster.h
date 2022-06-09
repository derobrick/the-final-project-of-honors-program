#include"Monster.h"
class Boss :public Monster
{
public:
	//获取是否吸血
	virtual bool getSuck();
	//获取是否暴击
	virtual bool getCrit();
	int suckRate;
	int critRate;
	//传入概率 判断是否触发
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
