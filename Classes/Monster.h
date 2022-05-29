#ifndef _Monster_H_
#define _Monster_H_
#include "cocos2d.h"   
using namespace cocos2d;
class Player;
class Monster
{
public:
    //获取是否吸血
    virtual bool getSuck() = 0;
    //获取是否暴击
    virtual bool getCrit() = 0;

    int Get_HP()const { return m_Hp; }
    int Get_Attack()const { return m_Attack; }
    int Get_Defense()const { return m_Defense; }

    void Attack(Player* player);

protected:
    int m_Hp;    //血量
    int m_Attack;//攻击力
    int m_Defense;//防御力
};
#endif;

