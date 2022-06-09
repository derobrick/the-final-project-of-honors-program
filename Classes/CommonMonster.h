#include"Monster.h"
class Common :public Monster 
{
public:
	//获取是否吸血
	virtual bool getSuck();
	//获取是否暴击
	virtual bool getCrit();
	virtual void Attack(Player* player);
};

class Commonone :public Common
{
public:
	Commonone();
	~Commonone();
	CREATE_FUNC(Commonone);
};
class Commontwo :public Common
{
public:
	Commontwo();
	~Commontwo();
	CREATE_FUNC(Commontwo);
};