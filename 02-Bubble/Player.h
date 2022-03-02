#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Entity.h"

// Player is basically a Sprite that represents the player. As such it has
// all properties it needs to track its movement, jumping, and collisions.


class Player : public Entity
{

public:

	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram);
	void update(int deltaTime);
	void render();

private:
	bool bJumping;
	int jumpAngle, startY;

};


#endif // _PLAYER_INCLUDE


