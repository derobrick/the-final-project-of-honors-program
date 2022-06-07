#ifndef _Monster_H_
#define _Monster_H_
#include "cocos2d.h"   
#include "Player.h"
using namespace cocos2d;
class Monster :public NODE
{
public:
    //��ȡ�Ƿ���Ѫ
    virtual bool getSuck() = 0;
    //��ȡ�Ƿ񱩻�
    virtual bool getCrit() = 0;

    int Get_Hp() { return m_Hp; }
    int Get_Attack() { return m_Attack; }
    int Get_Defense() { return m_Defense; }
    int Get_Gold() { return m_Gold; }
    int Get_Experience() { return m_Exp; }

    void Hpchange(int Hp);

    virtual void Attack(Player* player);
    Sprite* getSprite();               /*��ȡ�������*/
    void bindSprite(Sprite* sprite);     /*�󶨾������*/

protected:
    int m_Hp;    //Ѫ��
    int m_Attack;//������
    int m_Defense;//������
    int m_Gold;//���
    int m_Exp;//����
    Sprite* m_sprite;
};
#endif;

