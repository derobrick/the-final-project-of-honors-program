#include"Monster.h"
class Boss :public Monster
{
public:
	Boss();
	~Boss();
	//获取是否吸血
	virtual bool getSuck();
	//获取是否暴击
	virtual bool getCrit();
	int suckRate;
	int critRate;
	//传入概率 判断是否触发
	bool isTriggle(int rate);

	CREATE_FUNC(Boss);
};
