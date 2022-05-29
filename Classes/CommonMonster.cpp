#include "CommonMonster.h"

Common::Common()
{
	this->m_Hp = 300;
	this->m_Attack = 70;
	this->m_Defense = 40;
	this->m_Gold = 50;
	this->m_Exp = 100;
}
Common::~Common()
{
}

bool Common::getSuck()
{
	return false;
}

bool Common::getCrit()
{
	return false;
}

void Monster::Attack(Player* player)
{
	//¼ÆËãÕæÊµÉËº¦
	int TrueDamage = (this->m_Attack - Player->m_Defense) > 0 ? (this->m_Attack - Player->m_Defense) : 1;
	Player->m_Hp -= TrueDamage;
}