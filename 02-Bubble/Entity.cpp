#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

#include "Entity.h"
#include "Game.h"

#define TIME_TO_SECONDS 0.001f

void Entity::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram)
{

	spritesheet.createEmptyTexture(32,32);
	if (sprite == nullptr) sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(1.f, 1.f), &spritesheet, &shaderProgram);


	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + pos.x), float(tileMapDispl.y + pos.y)));
}

void Entity::update(int deltaTime)
{
	float sec = TIME_TO_SECONDS * deltaTime;

	sprite->update(deltaTime);
	Enviroment::apply(enviroment,this); // aplicará los efectos del ambiente a la entidad, la entidad debera enlazarse primero con el ambiente

	glm::vec2 newPos = pos + vel * sec + acc * 0.5f * sec * sec;
	vel = vel + acc * sec * 2.f;
	acc = { 0.f,0.f }; // reiniciamos la acc, en nuestro programa actua como la fuerza en cada momento

	if (bCollidable) bCollided = map->evaluateCollision(pos, glm::ivec2(32,32), &newPos);

	setPosition(newPos);
}

void Entity::render()
{
	sprite->render();
}

void Entity::setTileMap(TileMap* tileMap)
{
	map = tileMap;
}

void Entity::setPosition(const glm::vec2& pos)
{
	this->pos = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + pos.x), float(tileMapDispl.y + pos.y)));
}
