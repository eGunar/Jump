#include "Block.h"

Block::Block(int x, int y) : Entity(true, false, true)
{
	texture = TextureManager::LoadTexture("assets/brick.png");
	position.x = x;
	position.y = y;
	position.w = 32;
	position.h = 32;
}
