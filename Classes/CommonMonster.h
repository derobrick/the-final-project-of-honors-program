#include"Monster.h"
class Common :public Monster 
{
public:
	//��ȡ�Ƿ���Ѫ
	virtual bool getSuck();
	//��ȡ�Ƿ񱩻�
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