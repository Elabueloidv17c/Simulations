#include "xenaScene.h"


xenaScene::xenaScene()
  :Scene()
{
}


void
xenaScene::Render()
{
  m_renderTarget->clear(m_backgroundColor);
  sf::CircleShape circle(100.0f);
  circle.setFillColor(sf::Color::Red);
  m_renderTarget->draw(circle);

  //Draw scene here

  m_renderTarget->display();

}

void 
xenaScene::Initialize(RenderWindow* renderTarget, Color background, Timer* timer)
{
  m_renderTarget = renderTarget;
  m_backgroundColor = background;
  m_timer = timer;

  Vector2f screenSize = static_cast<Vector2f>(m_renderTarget->getSize());
  m_camera.Initialize(screenSize, 3000.0f, 10.0f, 20.0f, timer);
  
}
