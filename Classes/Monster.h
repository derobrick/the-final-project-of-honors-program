#ifndef _Monster_H_
#define _Monster_H_
#include "cocos2d.h"   
#include "Player.h"
using namespace cocos2d;
class Monster
{
public:
    //获取是否吸血
    virtual bool getSuck() = 0;
    //获取是否暴击
    virtual bool getCrit() = 0;

    int Get_Hp()const { return m_Hp; }
    int Get_Attack()const { return m_Attack; }
    int Get_Defense()const { return m_Defense; }
    int Get_Gold()const { return m_Gold; }
    int Get_Experience()const { return m_Exp; }

    void Attack(Player* player);

protected:
    int m_Hp;    //血量
    int m_Attack;//攻击力
    int m_Defense;//防御力
    int m_Gold;//金币
    int m_Exp;//经验
};
#endif;

