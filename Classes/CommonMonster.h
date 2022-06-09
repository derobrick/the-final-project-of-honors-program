#include"Monster.h"
class Common :public Monster 
{
public:
	//获取是否吸血
	virtual bool getSuck();
	//获取是否暴击
	virtual bool getCrit();
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