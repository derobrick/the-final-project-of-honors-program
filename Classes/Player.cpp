#include "Player.h"
#include "GaintMonster.h"
#include "CommonMonster.h"
#include "key.h"
#include "medicine.h"
#include "equipment.h"
#include "leveldoor.h"
#include "mapdoor.h"
Player::Player()
{
	m_Level = 1;
	m_Hp = 100000;
	m_Attack = 10000;
	m_Defense = 10;
	m_Exp = 0;
	m_gold = 0;
	m_RedKey = 0;
	m_YellowKey = 10;
	m_BlueKey = 0;
	Enable_map = 1;
}
Player::~Player(){}
bool Player:: init()
{
// 键盘事件监听
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(Player::Move, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	return true;
}
void Player::Use_RedKey() { this->m_RedKey--; }  //使用道具
void Player::Use_BlueKey() { this->m_BlueKey--; }
void Player::Use_YellowKey() { this->m_YellowKey--; }
void Player::Use_gold(int gold) { this->m_gold = m_gold - gold; }
void Player::Use_Exp(int Exp) { this->m_Exp = m_Exp - Exp; }

void Player::Get_RedKey() { this->m_RedKey++; }  //获得道具
void Player::Get_BlueKey() { this->m_BlueKey++; }
void Player::Get_YellowKey() { this->m_YellowKey++; }
void Player::Get_gold(int gold) { this->m_gold = m_gold + gold; }
void Player::Get_Hp(int Hp) {this->m_Hp = m_Hp + Hp;}
void Player::Get_Att(int Att) { this->m_Attack = m_Attack + Att; }
void Player::Get_Def(int Def) { this->m_Defense = m_Defense + Def; }
void Player::Get_Exp(int Exp) { this->m_Exp = m_Exp + Exp; }
void Player::Get_Lv() { this->m_Level++; }


template<typename T> 
bool Player::fight(T* monster)   //T是三种怪物的模板
{
	int t1 = this->m_Hp;//对血量进行备份
	int t2 = monster->Get_Hp();
	while (1)
	{
		int TrueDamage = (this->m_Attack - monster->Get_Defense()) > 0 ? (this->m_Attack - monster->Get_Defense()) : 1;
		monster->Hpchange(TrueDamage);
		if (monster->Get_Hp() <= 0)
		{
			this->m_gold += monster->Get_Gold();
			this->m_Exp += monster->Get_Experience();
			return true;    //打的过，进行战斗
		}
		monster->Attack(this);
		if (this->m_Hp <= 0)
		{
			int t3 = monster->Get_Hp();
			monster->Hpchange(t2 - t3);//重置怪物血量
			this->m_Hp = t1;
			return false; //主角打不过，则不进行战斗,将血量重置为之前的血量
		}
	}
}


void Player::Move(EventKeyboard::KeyCode keyCode, Event* event) 
{
	switch (keyCode) 
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	case EventKeyboard::KeyCode::KEY_A:
	{
		cocos2d::Size spriteSize = m_sprite->getContentSize();
		if (setTagPosition(Pos.x - spriteSize.width, Pos.y)) {		
			auto moveBy = MoveBy::create(0.2f, Vec2(-m_sprite->getContentSize().width, 0));
			m_sprite->runAction(Sequence::create(moveBy, nullptr));
			action(4);
			Pos.x -= m_sprite->getContentSize().width;

		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_D:
	{
		cocos2d::Size spriteSize = m_sprite->getContentSize();
		if (setTagPosition(Pos.x + spriteSize.width, Pos.y)) {
			auto moveBy = MoveBy::create(0.2f, Vec2(m_sprite->getContentSize().width, 0));
			m_sprite->runAction(Sequence::create(moveBy, nullptr));
			action(8);
			Pos.x += m_sprite->getContentSize().width;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	case EventKeyboard::KeyCode::KEY_W:
	{
		cocos2d::Size spriteSize = m_sprite->getContentSize();
		if (setTagPosition(Pos.x, Pos.y + spriteSize.height)) {
			auto moveBy = MoveBy::create(0.2f, Vec2(0, m_sprite->getContentSize().height));
			m_sprite->runAction(Sequence::create(moveBy, nullptr));
			action(12);
			Pos.y += m_sprite->getContentSize().height;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_S:
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		cocos2d::Size spriteSize = m_sprite->getContentSize();
		if (setTagPosition(Pos.x, Pos.y - spriteSize.height)) {
			auto moveBy = MoveBy::create(0.2f, Vec2(0, -m_sprite->getContentSize().height));
			m_sprite->runAction(Sequence::create(moveBy, nullptr));
			action(0);
			Pos.y -= m_sprite->getContentSize().height;
		}
		break;
	}
	default:
		break;
	}
}

void Player::setTiledMap(cocos2d::TMXTiledMap* map,cocos2d::Point Pos) {
	this->mymap = map;
	this->Pos = Pos;
	this->wall = mymap->getLayer("wall");
	this->monster = mymap->getLayer("monster");
	this->key = mymap->getLayer("key");
	this->SAM = mymap->getLayer("SAM");
	this->door = mymap->getLayer("door");
}
bool Player::setTagPosition(float x, float y) {
    
	cocos2d::Point dstPos = cocos2d::Point(x, y);
	/*获取主角当前的格子*/
	cocos2d::Point tiledPos = tileCoordForPostion(cocos2d::Point(dstPos.x, dstPos.y));
	/*获取地图上的标识*/
	int walltiledGid = wall->getTileGIDAt(tiledPos);
	int monstertiledGid = monster->getTileGIDAt(tiledPos);
	int keytiledGid = key->getTileGIDAt(tiledPos);
	int SAMtiledGid = SAM->getTileGIDAt(tiledPos);
	int doortiledGid = door->getTileGIDAt(tiledPos);
	if (walltiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(walltiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Collidable") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Collidable");
			if (prop.asString().compare("1") == 0) {
				return false;
			}
		}
	}
	if (monstertiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(monstertiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Gaintone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Gaintone");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Gaintone* mymonster = Gaintone::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */

				return false;
			}
		}
		if (propertiesMap.find("Gainttwo") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Gainttwo");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Gainttwo* mymonster = Gainttwo::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */
				return false;
			}
		}
		if (propertiesMap.find("Commonone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Commonone");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Commonone* mymonster = Commonone::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */
				return false;
			}
		}
		if (propertiesMap.find("Commontwo") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("Commontwo");
			if (prop.asString().compare("1") == 0) {
				/*检测能否打得过*/
				Commontwo* mymonster = Commontwo::create();
				if (this->fight(mymonster) == true)
				{
					monster->removeTileAt(tiledPos);
				}
				/*              */
				return false;
			}
		}
	}
	if (keytiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(keytiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("YellowKey") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("YellowKey");
			if (prop.asString().compare("1") == 0) {
				/*获得黄钥匙*/
				this->Get_YellowKey();
				/*          */
				key->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("BlueKey") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("BlueKey");
			if (prop.asString().compare("1") == 0) {
				/*获得蓝钥匙*/
				this->Get_BlueKey();
				/*          */
				key->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("RedKey") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("RedKey");
			if (prop.asString().compare("1") == 0) {
				/*获得红钥匙*/
				this->Get_RedKey();
				key->removeTileAt(tiledPos);
				return false;
			}
		}
	}
	if (SAMtiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(SAMtiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("redmedicine") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("redmedicine");
			if (prop.asString().compare("1") == 0) {
				/*获得红色血瓶*/
				this->Get_Hp(500);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("bluemedicine") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("bluemedicine");
			if (prop.asString().compare("1") == 0) {
				/*获得蓝色血瓶*/
				this->Get_Hp(1000);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("redstone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("redstone");
			if (prop.asString().compare("1") == 0) {
				/*获得红色宝石*/
				this->Get_Att(20);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("bluestone") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("bluestone");
			if (prop.asString().compare("1") == 0) {
				/*获得蓝色宝石*/
				this->Get_Def(20);
				/*          */
				SAM->removeTileAt(tiledPos);
				return false;
			}
		}
	}
	if (doortiledGid != 0) {
		cocos2d::Value properties = mymap->getPropertiesForGID(doortiledGid);
		cocos2d::ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("YellowDoor") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("YellowDoor");
			if (prop.asString().compare("1") == 0) {
				/*遇到黄色门*/
				if (this->Look_YellowKey() > 0)
				{
					this->Use_YellowKey();
					door->removeTileAt(tiledPos);
				}
				/*          */
				return false;
			}
		}
		if (propertiesMap.find("BlueDoor") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("BlueDoor");
			if (prop.asString().compare("1") == 0) {
				/*遇到蓝色门*/
				if (this->Look_BlueKey() > 0)
				{
					this->Use_BlueKey();
					door->removeTileAt(tiledPos);
				}
				/*          */
				return false;
			}
		}
		if (propertiesMap.find("RedDoor") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("RedDoor");
			if (prop.asString().compare("1") == 0) {
				/*遇到红色门*/
				if (this->Look_RedKey() > 0)
				{
					door->removeTileAt(tiledPos);
					this->Use_RedKey();
				}
				/*          */
				return false;
			}
		}
		if (propertiesMap.find("StairsDown") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("StairsDown");
			if (prop.asString().compare("1") == 0) {
				/*遇到向下的楼梯*/

				/*          */
				door->removeTileAt(tiledPos);
				return false;
			}
		}
		if (propertiesMap.find("StairsUp") != propertiesMap.end()) {
			cocos2d::Value prop = propertiesMap.at("StairsUp");
			if (prop.asString().compare("1") == 0) {
				/*遇到向上的楼梯*/
				this->Get_stair();
				/*          */
				door->removeTileAt(tiledPos);
				return false;
			}
		}
	}
	return true;
}

cocos2d::Point Player::tileCoordForPostion(cocos2d::Point pos) {
	cocos2d::Size mapTieldNum = mymap->getMapSize();
	cocos2d::Size tiledSize = m_sprite->getContentSize();
	int x = static_cast<int>(pos.x / tiledSize.width);
	int y = static_cast<int>(pos.y / tiledSize.height);
	y = static_cast<int>(mapTieldNum.height - y - 1);
	return cocos2d::Point(static_cast<float>(x), static_cast<float>(y));
}
void Player::action(int picture_name) {
	auto* animation = cocos2d::Animation::create();
	for (int i = 0; i < 4; ++i, picture_name++) {
		char action[10] = { 0 };
		sprintf(action, "%d.png", picture_name);
		animation->addSpriteFrameWithFile(action);
	}
	animation->setLoops(1);
	animation->setDelayPerUnit(0.1f);
	auto action = cocos2d::Animate::create(animation);
	m_sprite->runAction(action);
}


		