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
	int Look_RedKey() { return m_RedKey; }  //显示数值
	int Look_BlueKey() { return m_BlueKey; }
	int Look_YellowKey() { return m_YellowKey; }
	int Look_Hp() { return m_Hp; }
	int Look_Lv() { return m_Level; }
	int Look_Exp() { return m_Exp; }
	int Look_Att() { return m_Attack; }
	int Look_Def() { return m_Defense; }
	int Look_gold() { return m_gold; }
	int Look_stair() { return Enable_map; }
	  
	void Use_RedKey(); //使用道具
	void Use_BlueKey();
	void Use_YellowKey();
	void Use_gold(int gold);
	void Player::Use_Exp(int Exp);

	void Get_RedKey();//获得道具
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
	bool fight(T* monster);//战斗
	void Move(EventKeyboard::KeyCode keyCode, Event* event);//行走

	void setTiledMap(cocos2d::TMXTiledMap* map,cocos2d::Point Pos); 
	bool setTagPosition(float x, float y);                     //检查前方能否通过
	cocos2d::Point tileCoordForPostion(cocos2d::Point pos);   //将像素坐标转化为地图的格子坐标
	void action(int picture_name);
private:
	int m_Level;       //等级
	int m_Hp;          //血量
	int m_Attack;      //攻击力
	int m_Defense;     //防御力
	int m_Exp;         //经验
	int m_gold;        //金币
	int m_RedKey;      //红钥匙
	int m_YellowKey;   //黄钥匙
	int m_BlueKey;     //蓝钥匙
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


	