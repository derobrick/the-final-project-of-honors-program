#include"Monster.h"
class Common :public Monster 
{
public:
	Common();
	~Common();
	//获取是否吸血
	virtual bool getSuck();
	//获取是否暴击
	virtual bool getCrit();
	virtual void Attack(Player* player);
	CREATE_FUNC(Common);
};