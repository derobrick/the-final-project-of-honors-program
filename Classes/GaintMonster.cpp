#include "GaintMonster.h"

Gaint::Gaint()
{
	this->m_Hp = 500;
	this->m_Attack = 100;
	this->m_Defense = 100;
	this->m_Gold = 150;
	this->m_Exp = 300;
	this->suckRate = 40;
}
Gaint::~Gaint()
{
}
void Monster::Hpchange(int Hp) { this->m_Hp = m_Hp + Hp; }

bool Gaint::getSuck()
{
	if (isTriggle(suckRate))
	{
		return (this->m_Attack * 0.5);
	}
	return false;
}

bool Gaint::getCrit()
{
	return false;
}
bool Gaint::isTriggle(int rate)
{
	//ͨ��isTriggle�ж��Ƿ񴥷���Ч
	//���һ��1-100������
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
	//������Ѫ
	addHp = this->getSuck();
	if (addHp > 0)//��������ѪЧ��������Ѫ��
	{

	}
	//������ʵ�˺�
	int TrueDamage = (this->m_Attack - player->Look_Def()) > 0 ? (this->m_Attack - player->Look_Def()) : 1;
	player->Get_Hp(-TrueDamage);
	this->m_Hp += addHp;
}