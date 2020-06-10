#pragma once

#include "Object.h"
#include <map>
#include <string>
#include <vector>

class ActorManager
{
public:
	ActorManager();
	~ActorManager();

	void Add(std::string name_);
	void Update();
	void Draw();

private:
	std::vector<Actor*> m_object;
};

