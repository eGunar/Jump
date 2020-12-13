#include "Block.h"

Block::Block() : Entity(true, false, true)
{
	texture = TextureManager::LoadTexture("assets/brick.png");
	position.x = 200;
	position.y = 200;
	position.w = 32;
	position.h = 32;
}
