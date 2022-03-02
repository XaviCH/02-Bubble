#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include "Sprite.h"
#include "TileMap.h"


// Entity is basically a Sprite that represents the entity. As such it has
// all properties it needs to track its movement and collisions.


class Entity 
{

public:
	virtual void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram);
	virtual void update(int deltaTime);
	virtual void render();

	virtual void setTileMap(TileMap* tileMap);
	virtual void setPosition(const glm::vec2& pos);

protected:
	bool bCollidable, bCollided;
	unsigned int enviroment;

	glm::ivec2 tileMapDispl;
	glm::vec2 pos, vel, acc;
	Texture spritesheet;
	Sprite* sprite;
	TileMap* map;

};


#endif


