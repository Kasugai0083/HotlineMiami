#pragma once
#include "../Actor.h"
#include <string>

class Player :
	public Actor
{
public:
	Player(std::string name_);
	~Player();

	void Update() override;
	void Draw() override;

private:

};

