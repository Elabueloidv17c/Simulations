#include "cEntity.h"

cEntity::cEntity(const sf::Sprite& otherSprite)
{
  m_sprite = otherSprite;
}

bool
cEntity::testCollision(cEntity& other)
{
  sf::FloatRect myBound = this->m_sprite.getGlobalBounds();//.intersects(other.getSprite().getGlobalBounds()); 

  return other.m_sprite.getGlobalBounds().intersects(myBound); 
}

void 
cEntity::init(const sf::Sprite& otherSprite)
{
  m_sprite = otherSprite;
}

sf::Sprite&
cEntity::getSprite()
{
  return m_sprite;
}

Point 
cEntity::getMapPosition() const
{
  return m_positionInMap;
}

void 
cEntity::setMapPosition(uint32_t x, uint32_t y)
{
  this->m_positionInMap.x = x;
  this->m_positionInMap.y = y;
}

void 
cEntity::setSpritePosition(float xPos, float yPos)
{
  m_sprite.setPosition(xPos, yPos);
}
