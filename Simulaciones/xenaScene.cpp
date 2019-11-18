#include "xenaScene.h"
#include "helper.h"
// std includes 
#include <cassert>


xenaScene::xenaScene()
  :Scene()
{
}


void
xenaScene::Render()
{
  m_renderTarget->clear(m_backgroundColor);

  sf::Vector2u windowSize = m_renderTarget->getSize();

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

  bool isSucceful = this->loadTextures();

  if (!isSucceful)
  {
    assert(isSucceful == true);
  }

  isSucceful = this->loadMap("..//map//test.txt");

  if (!isSucceful)
  {
    assert(isSucceful == true);
  }

  this->loadBricks();

  for (size_t i = 0; i < 4; ++i) {

    sf::Sprite result(m_textures[1]);
    m_entity.push_back(result);
  }


  Vector2f screenSize = static_cast<Vector2f>(m_renderTarget->getSize());

  auto LastEntity = m_entity.end();
  LastEntity--;

  constexpr float SizeFactor = 1.3f;

  for (size_t i = 0; i < 2; ++i)
  {
    sf::Vector2u originalSize = m_textures[1].getSize();

    (*LastEntity).getSprite().setPosition(0, 0);
    sf::Vector2f NewScale;

    (i % 2 == 0) ? NewScale = ReScale(originalSize, screenSize.x * SizeFactor, 10)
      : NewScale = ReScale(originalSize, 10, screenSize.y * SizeFactor);

    (*LastEntity).getSprite().setScale(NewScale);
    LastEntity--;
  }

  sf::Vector2u TextureSize = m_textures[1].getSize();
  (*LastEntity).getSprite().setPosition(screenSize.x * SizeFactor, 0);
  (*LastEntity).getSprite().setScale(ReScale(TextureSize, 10, screenSize.y * SizeFactor));
  LastEntity--;
  (*LastEntity).getSprite().setPosition(0, screenSize.y * SizeFactor);
  (*LastEntity).getSprite().setScale(ReScale(TextureSize, screenSize.x * SizeFactor, 10));


  m_camera.Initialize(screenSize, 3000.0f, 10.0f, 20.0f, timer);
}

bool xenaScene::loadTextures()
{
  m_textures.emplace_back();
  m_textures.emplace_back();

  if (!m_textures[0].loadFromFile("../sprites/rock.png"))
  {
    std::cerr << "it failed";
    return false;
  }

  if (!m_textures[1].loadFromFile("../sprites/brick_wall.png")) {

    std::cerr << "it failed";
    return false;
  }
  return true;
}

bool
xenaScene::loadMap(const char* mapFile)
{
  return m_map.init(mapFile);
}

void
xenaScene::loadBricks()
{
  sf::Vector2u originlaSize = m_textures[0].getSize();

  Vector2f screenSize = static_cast<Vector2f>(m_renderTarget->getSize());
  sMapDim mapDimentions = m_map.getMapDimentions();

  //! to calculate the position of a entity in screen coordinates 
  const float xMinimalScreenPos = screenSize.x / (float)mapDimentions.columns;
  const float yMinimalScreenPos = screenSize.y / (float)mapDimentions.rows;

  auto& PositionsContianer = m_map.getPositionsRef();
  for (size_t i = 0; i < m_map.getPositionsCount(); ++i)
  {
    sf::Sprite result(m_textures[0]);
    m_entity.push_back(result);

    sf::Vector2f NewScale = ReScale(originlaSize, 100, 100);
    m_entity[i].getSprite().setScale(NewScale);
    sf::Vector2f  newSize = sf::Vector2f(originlaSize.x * NewScale.x, originlaSize.y * NewScale.y);

    // calculate position in map space 
    m_entity[i].getSprite().setOrigin(newSize.x, newSize.y * .5f);
    m_entity[i].setMapPosition(PositionsContianer[i].x, PositionsContianer[i].y);

    // calculate positions in screen space 
    Point EntityPos = m_entity[i].getMapPosition();
    m_entity[i].setSpritePosition(EntityPos.x * xMinimalScreenPos, EntityPos.y * yMinimalScreenPos);
  }
}

void 
xenaScene::calculateWallSize()
{
  Vector2f screenSize = static_cast<Vector2f>(m_renderTarget->getSize());

  auto LastEntity = m_entity.end();
  LastEntity--;

  constexpr float SizeFactor = 1.3f;

  for (size_t i = 0; i < 2; ++i)
  {
    sf::Vector2u originalSize = m_textures[1].getSize();

    (*LastEntity).getSprite().setPosition(0, 0);
    sf::Vector2f NewScale;

    (i % 2 == 0) ? NewScale = ReScale(originalSize, screenSize.x * SizeFactor, 10)
      : NewScale = ReScale(originalSize, 10, screenSize.y * SizeFactor);

    (*LastEntity).getSprite().setScale(NewScale);
    LastEntity--;
  }

  sf::Vector2u TextureSize = m_textures[1].getSize();
  (*LastEntity).getSprite().setPosition(screenSize.x * SizeFactor, 0);
  (*LastEntity).getSprite().setScale(ReScale(TextureSize, 10, screenSize.y * SizeFactor));
  LastEntity--;
  (*LastEntity).getSprite().setPosition(0, screenSize.y * SizeFactor);
  (*LastEntity).getSprite().setScale(ReScale(TextureSize, screenSize.x * SizeFactor, 10));
}
