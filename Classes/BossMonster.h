#include"Monster.h"
class Boss :public Monster
{
public:
	Boss();
	~Boss();
	//��ȡ�Ƿ���Ѫ
	virtual bool getSuck();
	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();
	int suckRate;
	int critRate;
	//������� �ж��Ƿ񴥷�
	bool isTriggle(int rate);
	virtual void Attack(Player* player);
	CREATE_FUNC(Boss);
};
