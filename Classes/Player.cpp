#include "Player.h"
Player::Player()
{
	m_Level = 1;
	m_Hp = 1000;
	m_MaxHp = 2000;
	m_Attack = 10;
	m_Defense = 10;
	m_Exp = 0;
	m_gold = 0;
	m_RedKey = 0;
	m_YellowKey = 0;
	m_BlueKey = 0;
}
Player::~Player(){}
bool Player:: init()
{
// 键盘事件监听
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(Player::Move(), this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return true;
}
void Player::Use_RedKey() { this->m_RedKey--; }  //使用道具
void Player::Use_BlueKey() { this->m_BlueKey--; }
void Player::Use_YellowKey() { this->m_YellowKey--; }
void Player::Use_gold(int gold) { this->m_gold = m_gold - gold; }

void Player::Get_RedKey() { this->m_RedKey++; }  //获得道具
void Player::Get_BlueKey() { this->m_BlueKey++; }
void Player::Get_YellowKey() { this->m_YellowKey++; }
void Player::Get_gold(int gold) { this->m_gold = m_gold + gold; }
void Player::Get_Hp(int Hp) 
{
	if (m_Hp + Hp > m_MaxHp)
		this->m_Hp = m_MaxHp;
	else
		this->m_Hp = m_Hp + Hp;
}
void Player::Get_Att(int Att) { this->m_Attack = m_Attack + Att; }
void Player::Get_Def(int Def) { this->m_Defense = m_Defense + Def; }


template<typename T> 
bool Player::fight(T monster)   //T是三种怪物的模板
{
	int t1 = this->m_Hp;//对血量进行备份
	int t2 = T::Get_Hp();
	while (1)
	{
		int TrueDamage = (this->m_Attack - T::Get_Defense()) > 0 ? (this->m_Attack - T::Get_Defense()) : 1;
		T::Hpchange(trueDamage);
		if (T::Get_Hp() <= 0)
		{
			this->m_gold += T::Get_Gold();
			this->m_Exp += T::Get_Experience();
			return true;    //打的过，进行战斗
		}
		T::Attack();
		if (this_Hp <= 0)
		{
			int t3 = T::Get_Hp;
			T::Hpchange(t2 - t3);//重置怪物血量
			this->m_Hp = t;
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
		auto moveBy = MoveBy::create(0.2f, Vec2(-32, 0));
		m_sprite->runAction(Sequence::create(moveBy, nullptr));
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_D:
	{
		auto moveBy = MoveBy::create(0.2f, Vec2(32, 0));
		m_sprite->runAction(Sequence::create(moveBy, nullptr));
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	case EventKeyboard::KeyCode::KEY_W:
	{
		auto moveBy = MoveBy::create(0.2f, Vec2(0, 32));
		m_sprite->runAction(Sequence::create(moveBy, nullptr));
		break;
	}
	case EventKeyboard::KeyCode::KEY_S:
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		auto moveBy = MoveBy::create(0.2f, Vec2(0, -32));
		m_sprite->runAction(Sequence::create(moveBy, nullptr));
		break;
	}
	default:
		break;
	}
}

		