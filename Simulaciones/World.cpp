#include "World.h"
#include "Scene.h"

void 
World::Initialize(RenderWindow* renderTarget, Timer* timer) {
  m_timer = timer;

  m_renderTarget = renderTarget;
  m_scene.Initialize(m_renderTarget, Color(0, 0, 128, 255), timer);
}

void 
World::ProcessInput(const Event& event) {
  m_scene.ProcessInput(event);
}

void 
World::Destroy() {
  m_scene.Destroy();
}

void 
World::Update() {
  m_scene.Update();
}

void 
World::Render() {
  m_scene.Render();
}
