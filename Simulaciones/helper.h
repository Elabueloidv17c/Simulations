#pragma once
#include "Headers.h"

static sf::Vector2f
ReScale(sf::Vector2u& originalScale,
  uint32_t newSizeX,
  uint32_t  newSizeY)
{
  float yScale;
  float xScale;
  if (originalScale.x >= newSizeX) {
    xScale = newSizeX / (float)originalScale.x;
  }
  else {

    xScale = newSizeX / (float)originalScale.x;
    //xScale = (originalScale.x / (float)newSizeX);
  }

  if (originalScale.y >= newSizeY) {
    yScale = newSizeY / (float)originalScale.y;
  }
  else {
    yScale = newSizeY / (float)originalScale.y;
  }

  return sf::Vector2f(xScale, yScale);
}


