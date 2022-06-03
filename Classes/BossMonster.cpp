#include "BossMonster.h"

Boss::Boss()
{
	this->m_Hp = 1000;
	this->m_Attack = 200;
	this->m_Defense = 200;
	this->m_Gold = 500;
	this->m_Exp = 500;
	this->suckRate = 50;
	this->critRate = 50;
}

Boss::~Boss()
{
}

void Monster::Hpchange(int Hp) { this->m_Hp = m_Hp + Hp; }

bool Boss::getSuck()
{
	if (isTriggle(suckRate))
	{
		return (this->m_Attack * 0.5);
	}
	return false;
}

bool Boss::getCrit()
{
	if (isTriggle(critRate))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Boss::isTriggle(int rate)
{
	//通过isTriggle判断是否触发特效
	//随机一个1-100的数字
	//srand( (unsigned)time(NULL) )
	srand(time(0));
	int num = rand() % 100 + 1;
	if (num < rate)
		return true;
	else
		return false;
}

void Monster::Attack(Player* player)
{
	int addHp = 0;
	bool isCrit = false;
	//计算吸血
	addHp = this->getSuck();
	//计算暴击
	isCrit = this->getCrit();
	if (isCrit)//触发了暴击效果，造成双倍伤害
	{
		m_Attack *= 2;
	}
	if (addHp > 0)//触发了吸血效果，增加血量
	{

	}
	//计算真实伤害
	int TrueDamage = (this->m_Attack - Player->m_Defense) > 0 ? (this->m_Attack - Player->m_Defense) : 1;
	Player->Get_Hp() -= TrueDamage;
	this->m_Hp += addHp;
}