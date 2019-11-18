#pragma once
#include "Headers.h"

static sf::Vector2f
ReScale(sf::Vector2u& originalScale,
  uint32_t newSizeX,
  uint32_t  newSizeY)
{

  float xScale = newSizeX / (float)originalScale.x;;
  float yScale = newSizeY / (float)originalScale.y;;

  return sf::Vector2f(xScale, yScale);
}


