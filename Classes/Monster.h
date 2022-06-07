#ifndef _Monster_H_
#define _Monster_H_
#include "cocos2d.h"   
#include "Player.h"
using namespace cocos2d;
class Monster :public NODE
{
public:
    //获取是否吸血
    virtual bool getSuck() = 0;
    //获取是否暴击
    virtual bool getCrit() = 0;

    int Get_Hp() { return m_Hp; }
    int Get_Attack() { return m_Attack; }
    int Get_Defense() { return m_Defense; }
    int Get_Gold() { return m_Gold; }
    int Get_Experience() { return m_Exp; }

    void Hpchange(int Hp);

    virtual void Attack(Player* player);
    Sprite* getSprite();               /*获取精灵对象*/
    void bindSprite(Sprite* sprite);     /*绑定精灵对象*/

protected:
    int m_Hp;    //血量
    int m_Attack;//攻击力
    int m_Defense;//防御力
    int m_Gold;//金币
    int m_Exp;//经验
    Sprite* m_sprite;
};
#endif;

