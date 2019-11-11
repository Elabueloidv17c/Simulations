#pragma once
#include "SFML/Graphics.hpp"

class cEntity
{
public:
  cEntity(const sf::Sprite& otherSprite);
  ~cEntity() = default;


public:

  bool
  testCollision(cEntity &other);

  void
  init(const sf::Sprite& otherSprite);

  sf::Sprite& 
  getSprite();

private: 
  sf::Sprite
  m_sprite;

};


