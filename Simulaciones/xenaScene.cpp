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
  sf::Vector2u windowSize = m_renderTarget->getSize();
  m_entity[0].getSprite().setPosition(windowSize.x * .5f, windowSize.y * .5f);
  m_entity[1].getSprite().setPosition(windowSize.x * .5f, windowSize.y * 0.9f);
  m_entity[2].getSprite().setPosition(windowSize.x * .2f, windowSize.y * 0.9f);
  m_entity[3].getSprite().setPosition(windowSize.x * 0.75f, windowSize.y * 0.95f);

  m_entity[4].getSprite().setPosition(windowSize.x * .59f, windowSize.y * .5f);
  m_entity[5].getSprite().setPosition(windowSize.x * .68f, windowSize.y * .5f);
  m_entity[6].getSprite().setPosition(windowSize.x * .39f, windowSize.y * .5f);
  //m_entity[0].getSprite().setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
  //m_entity[0].getSprite().setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);


  for (cEntity& entity : m_entity) {
    m_renderTarget->draw(entity.getSprite());
  }


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

  for (uint32_t i = 0; i < 10; ++i)
  {
    sf::Sprite result(m_textures[0]);
    m_entity.push_back(result);

    sf::Vector2f NewScale = ReScale(originlaSize, 100, 100);
    m_entity[i].getSprite().setScale(NewScale);
    sf::Vector2f  newSize = sf::Vector2f(originlaSize.x * NewScale.x, originlaSize.y * NewScale.y);

    m_entity[i].getSprite().setOrigin(newSize.x, newSize.y * .5f);
  }

  Vector2f screenSize = static_cast<Vector2f>(m_renderTarget->getSize());
  m_camera.Initialize(screenSize, 3000.0f, 10.0f, 20.0f, timer);

}
