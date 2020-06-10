#pragma once

#include "ActorData.h"
#include <d3dx9.h>

class Actor
{
public:
	Actor();
	~Actor();

	virtual void Update() = 0;
	virtual void Draw() = 0;

	D3DXVECTOR2 GetPos() { return m_position; }

protected:
	D3DXVECTOR2 m_position;
	std::string m_name;

};

