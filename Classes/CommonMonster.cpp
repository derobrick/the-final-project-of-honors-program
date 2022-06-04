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
void Monster::Hpchange(int Hp) { this->m_Hp = m_Hp + Hp; }

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
	int TrueDamage = (this->m_Attack - player->Look_Def()) > 0 ? (this->m_Attack - player->Look_Def()) : 1;
	player->Get_Hp(-TrueDamage);
}