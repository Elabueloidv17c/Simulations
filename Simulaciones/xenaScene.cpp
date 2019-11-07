#include "xenaScene.h"
#include "helper.h"


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

  for (sf::Sprite& sprite : m_sprites) {
    m_renderTarget->draw(sprite);
  }

  //Draw scene here

  m_renderTarget->display();

}

void
xenaScene::Initialize(RenderWindow* renderTarget, Color background, Timer* timer)
{
  m_renderTarget = renderTarget;
  m_backgroundColor = background;
  m_timer = timer;

  m_textures.emplace_back();

  if (!m_textures[0].loadFromFile("../sprites/rock.png"))
  {
    std::cout << "it failed";
  }

  sf::Vector2u originlaSize = m_textures[0].getSize();

  for (uint32_t i = 0; i < 10; ++i) {
    m_sprites.emplace_back();
    m_sprites[i].setTexture(m_textures[0]);
    // making the image a 100 by 100  image 
    sf::Vector2f NewScale = ReScale(originlaSize,100, 100);
    m_sprites[i].setScale(NewScale);

  }




  Vector2f screenSize = static_cast<Vector2f>(m_renderTarget->getSize());
  m_camera.Initialize(screenSize, 3000.0f, 10.0f, 20.0f, timer);

}
