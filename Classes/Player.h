#ifndef _Player_H_
#define _Player_H_
#include "cocos2d.h"    
#include "Entity.h"
#include "floorscene.h"
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
	int Look_stair() { return Enable_map; }
	  
	void Use_RedKey(); //ʹ�õ���
	void Use_BlueKey();
	void Use_YellowKey();
	void Use_gold(int gold);
	void Player::Use_Exp(int Exp);

	void Get_RedKey();//��õ���
	void Get_BlueKey();
	void Get_YellowKey();
	void Get_gold(int gold);
	void Get_Hp(int Hp);
	void Get_Att(int Att);
	void Get_Def(int Def);
	void Get_Exp(int Exp);
	void Player::Get_Lv();
	void Get_stair() { this->Enable_map++; };

	template<typename T>
	bool fight(T* monster);//ս��
	void Move(EventKeyboard::KeyCode keyCode, Event* event);//����

	void setTiledMap(cocos2d::TMXTiledMap* map,cocos2d::Point Pos); 
	bool setTagPosition(float x, float y);                     //���ǰ���ܷ�ͨ��
	cocos2d::Point tileCoordForPostion(cocos2d::Point pos);   //����������ת��Ϊ��ͼ�ĸ�������
	void action(int picture_name);
private:
	int m_Level;       //�ȼ�
	int m_Hp;          //Ѫ��
	int m_Attack;      //������
	int m_Defense;     //������
	int m_Exp;         //����
	int m_gold;        //���
	int m_RedKey;      //��Կ��
	int m_YellowKey;   //��Կ��
	int m_BlueKey;     //��Կ��
	int Enable_map;
	cocos2d::TMXTiledMap* mymap;
	cocos2d::TMXLayer* wall;
	cocos2d::TMXLayer* monster;
	cocos2d::TMXLayer* key;
	cocos2d::TMXLayer* SAM;
	cocos2d::TMXLayer* door;
	cocos2d::TMXLayer* boss;
	cocos2d::Point Pos;
};
#endif;


	