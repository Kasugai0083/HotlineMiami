#include "Player.h"
#include "../../Engine/Input.h"
#include "../../Engine/Graphics.h"	


Player::Player()
{
}


Player::~Player()
{
}

void Player::Update()
{
	if (IsHeldKeyboard(DIK_W))
	{
		m_position.y -= CHASE_SPEED;
	}
}

void Player::Draw()
{
	DrawTexture(
		m_position.x,
		m_position.y,
		m_name.c_str(),
		128,
		0.f,
		1.f,
		1.f);
}
