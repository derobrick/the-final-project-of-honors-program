#include"Monster.h"
class Common :public Monster 
{
public:
	Common();
	~Common();
	//��ȡ�Ƿ���Ѫ
	virtual bool getSuck();
	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();
	CREATE_FUNC(Common);
};