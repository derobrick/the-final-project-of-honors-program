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
	Commonone();
	~Commonone();
	CREATE_FUNC(Commonone);
};
class Commontwo :public Common
{
	Commontwo();
	~Commontwo();
	CREATE_FUNC(Commontwo);
};