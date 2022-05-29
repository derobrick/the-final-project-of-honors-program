#ifndef _Monster_H_
#define _Monster_H_
#include "cocos2d.h"   
using namespace cocos2d;
class Player;
class Monster
{
public:
    //��ȡ�Ƿ���Ѫ
    virtual bool getSuck() = 0;
    //��ȡ�Ƿ񱩻�
    virtual bool getCrit() = 0;

    int Get_HP()const { return m_Hp; }
    int Get_Attack()const { return m_Attack; }
    int Get_Defense()const { return m_Defense; }

    void Attack(Player* player);

protected:
    int m_Hp;    //Ѫ��
    int m_Attack;//������
    int m_Defense;//������
};
#endif;

