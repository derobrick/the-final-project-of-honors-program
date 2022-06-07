#ifndef _Player_H_
#define _Player_H_
#include "cocos2d.h"    
#include "Entity.h"
using namespace cocos2d;
class Player :public Entity
{
public:
	Player();
	~Player();
	CREATE_FUNC(Player);
	virtual bool init();
	int Look_RedKey() { return m_RedKey; }  //显示数值
	int Look_BlueKey() { return m_BlueKey; }
	int Look_YellowKey() { return m_YellowKey; }
	int Look_Hp() { return m_Hp; }
	int Look_Lv() { return m_Level; }
	int Look_Exp() { return m_Exp; }
	int Look_Att() { return m_Attack; }
	int Look_Def() { return m_Defense; }
	int Look_gold() { return m_gold; }
	  
	void Use_RedKey(); //使用道具
	void Use_BlueKey();
	void Use_YellowKey();
	void Use_gold(int gold);

	void Get_RedKey();//获得道具
	void Get_BlueKey();
	void Get_YellowKey();
	void Get_gold(int gold);
	void Get_Hp(int Hp);
	void Get_Att(int Att);
	void Get_Def(int Def);
	void Get_Exp(int Exp);

	template<typename T>
	bool fight(T monster);//战斗
	void Move(EventKeyboard::KeyCode keyCode, Event* event);//行走

private:
	int m_Level;//等级
	int m_Hp;    //血量
	int m_MaxHp;//最大血量
	int m_Attack;//攻击力
	int m_Defense;//防御力
	int m_Exp;//经验
	int m_gold;//金币
	int m_RedKey;//红钥匙
	int m_YellowKey;//黄钥匙
	int m_BlueKey;//蓝钥匙
};
#endif;


	