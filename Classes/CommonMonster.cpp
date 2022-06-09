#include "CommonMonster.h"

Commonone::Commonone()
{
	this->m_Hp = 300;
	this->m_Attack = 70;
	this->m_Defense = 40;
	this->m_Gold = 50;
	this->m_Exp = 100;
}
Commonone::~Commonone()
{
}

Commontwo::Commontwo()
{
	this->m_Hp = 200;
	this->m_Attack = 60;
	this->m_Defense = 50;
	this->m_Gold = 50;
	this->m_Exp = 100;
}
Commontwo::~Commontwo()
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

void Common::Attack(Player* player)
{
	//¼ÆËãÕæÊµÉËº¦
	int TrueDamage = (this->m_Attack - player->Look_Def()) > 0 ? (this->m_Attack - player->Look_Def()) : 1;
	player->Get_Hp(-TrueDamage);
}