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
	int Look_RedKey() { return m_RedKey; }  //��ʾ��ֵ
	int Look_BlueKey() { return m_BlueKey; }
	int Look_YellowKey() { return m_YellowKey; }
	int Look_Hp() { return m_Hp; }
	int Look_Lv() { return m_Level; }
	int Look_Exp() { return m_Exp; }
	int Look_Att() { return m_Attack; }
	int Look_Def() { return m_Defense; }
	int Look_gold() { return m_gold; }
	  
	void Use_RedKey(); //ʹ�õ���
	void Use_BlueKey();
	void Use_YellowKey();
	void Use_gold(int gold);

	void Get_RedKey();//��õ���
	void Get_BlueKey();
	void Get_YellowKey();
	void Get_gold(int gold);
	void Get_Hp(int Hp);
	void Get_Att(int Att);
	void Get_Def(int Def);
	void Get_Exp(int Exp);

	template<typename T>
	bool fight(T monster);//ս��
	void Move(EventKeyboard::KeyCode keyCode, Event* event);//����

private:
	int m_Level;//�ȼ�
	int m_Hp;    //Ѫ��
	int m_MaxHp;//���Ѫ��
	int m_Attack;//������
	int m_Defense;//������
	int m_Exp;//����
	int m_gold;//���
	int m_RedKey;//��Կ��
	int m_YellowKey;//��Կ��
	int m_BlueKey;//��Կ��
};
#endif;


	