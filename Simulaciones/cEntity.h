#pragma once
#include "SFML/Graphics.hpp"
#include "Headers.h"

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

  Point
  getMapPosition()const;

  void 
  setMapPosition(uint32_t x, uint32_t y);

  void
  setSpritePosition(float xPos, float yPos);

private: 
  //! visual representation of the entity
  sf::Sprite
  m_sprite;

  //! keeps track of the position of the entity in the map 
  Point 
  m_positionInMap;

};


