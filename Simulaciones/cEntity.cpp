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
