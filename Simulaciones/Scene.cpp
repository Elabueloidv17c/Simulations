#include "Scene.h"

void
Scene::Initialize(RenderWindow* renderTarget, Color background, Timer* timer) {
  m_renderTarget = renderTarget;
  m_backgroundColor = background;
  m_timer = timer;

  Vector2f screenSize = static_cast<Vector2f>(m_renderTarget->getSize());
  m_camera.Initialize(screenSize, 3000.0f, 10.0f, 20.0f, timer);
}

void 
Scene::ProcessInput(const Event& event) {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
    sf::Mouse::isButtonPressed(sf::Mouse::Middle) ||
    sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
    m_mousePosition = Mouse::getPosition(*m_renderTarget);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    m_camera.MoveUp();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    m_camera.MoveLeft();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    m_camera.MoveDown();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    m_camera.MoveRight();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
    m_camera.ZoomIn();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
    m_camera.ZoomOut();
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {

  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {

  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {

  }
  else if (Event::Resized == event.type) {
    m_camera.Resize(static_cast<Vector2f>(m_renderTarget->getSize()));
  }
}

void 
Scene::Render() {
  m_renderTarget->clear(m_backgroundColor);

  //Draw scene here

  m_renderTarget->display();
}

void 
Scene::Destroy() {

}

void 
Scene::Update() {
  m_renderTarget->setView(*m_camera.GetView());
}
