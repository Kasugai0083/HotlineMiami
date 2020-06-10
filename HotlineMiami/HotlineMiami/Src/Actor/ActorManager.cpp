#include "ActorManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"


ActorManager::ActorManager()
{
}


ActorManager::~ActorManager()
{
}

void ActorManager::Add(std::string name_)
{

	std::string test;

	if (name_ == "Player") 
	{
		m_object.push_back = new Player*;
	}
	else if (name_ == "Enemy")
	{
		m_object.push_back = new Enemy(test);
	}
}

void ActorManager::Update()
{
	for (auto i : m_object)
	{
		
	}
}

void ActorManager::Draw()
{
	for (auto i : m_object)
	{

	}
}


