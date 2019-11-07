#pragma once

//External dependences
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>

//Constants
#define	PI													3.141592f
#define HALF												0.5f
#define DOUBLE											2.0f

//This is used to short the type of some objects and functions
using std::vector;
using std::string;

using std::cout;
using std::cin;
using std::endl;
using std::cosf;
using std::sinf;

using sf::RectangleShape;
using sf::RenderWindow;
using sf::CircleShape;
using sf::VideoMode;
using sf::FloatRect;
using sf::Vector2u;
using sf::Vector2i;
using sf::Vector2f;
using sf::Texture;
using sf::Sprite;
using sf::Vertex;
using sf::Mouse;
using sf::Color;
using sf::Clock;
using sf::Event;
using sf::Font;
using sf::Text;
using sf::Time;
using sf::View;

//Structs
struct Point
{
  unsigned int x;
  unsigned int y;

  Point() = default;

  Point(unsigned int x, unsigned int y) {
    this->x = x;
    this->y = y;
  }
};

struct Size
{
  unsigned int width;
  unsigned int height;

  Size() = default;

  Size(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
  }
};

struct Rectangle
{
  Point position;
  Size size;

  Rectangle() = default;

  Rectangle(Point position, Size size) {
    this->position = position;
    this->size = size;
  }
};

struct WindowData
{
  unsigned int style;
  string name;
  Size size;

  WindowData(unsigned int style, string name, Size size) {
    this->style = style;
    this->name = name;
    this->size = size;
  }
};

namespace TIME {
  enum E {
    Microseconds,
    Miliseconds,
    Seconds
  };
}