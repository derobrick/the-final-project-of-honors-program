#ifndef _Monster_H_
#define _Monster_H_
#include "cocos2d.h"   
#include "Player.h"
using namespace cocos2d;
class Monster
{
public:
    //��ȡ�Ƿ���Ѫ
    virtual bool getSuck() = 0;
    //��ȡ�Ƿ񱩻�
    virtual bool getCrit() = 0;

    int Get_Hp()const { return m_Hp; }
    int Get_Attack()const { return m_Attack; }
    int Get_Defense()const { return m_Defense; }
    int Get_Gold()const { return m_Gold; }
    int Get_Experience()const { return m_Exp; }

    void Attack(Player* player);

protected:
    int m_Hp;    //Ѫ��
    int m_Attack;//������
    int m_Defense;//������
    int m_Gold;//���
    int m_Exp;//����
};
#endif;

