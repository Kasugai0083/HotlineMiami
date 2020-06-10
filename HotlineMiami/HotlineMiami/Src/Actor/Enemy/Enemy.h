#pragma once
#include "../Actor.h"
#include <string>

class Enemy :
	public Actor
{
public:
	Enemy(std::string name_);
	~Enemy();

	void Update() override;
	void Draw() override;
	void Chase(Actor* actor_);
private:
};

