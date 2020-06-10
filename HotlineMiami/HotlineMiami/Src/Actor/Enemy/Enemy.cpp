#include "Enemy.h"
#include "../../Engine/Graphics.h"	


Enemy::Enemy(std::string name_)
{
	m_name = name_;
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
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

void Enemy::Chase(Actor* actor_)
{
	D3DXVECTOR2 target_pos = actor_->GetPos();

	if (target_pos.x > m_position.x)
	{
		m_position.x += CHASE_SPEED;
	}
	else if (target_pos.x < m_position.x)
	{
		m_position.x += CHASE_SPEED;
	}

	if (target_pos.y > m_position.y)
	{
		m_position.y = CHASE_SPEED;
	}
	else if (target_pos.x < m_position.x)
	{
		m_position.y += CHASE_SPEED;
	}

}


