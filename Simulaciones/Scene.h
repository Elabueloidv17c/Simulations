#pragma once

#include "Headers.h"
#include "Camera.h"

class Scene
{
  // esto es para que las clases derivadas puede acceder a estos miembros 
protected:
  RenderWindow*	
  m_renderTarget;

  Timer*
  m_timer;

  Color
  m_backgroundColor;

  Camera
  m_camera;

  Vector2i
  m_mousePosition;

public:
  
  virtual void				
  Initialize(RenderWindow* renderTarget, Color background, Timer* timer);

  void				
  ProcessInput(const Event& event);
  // la hice virtual para poder crear mi propia ecena 
  virtual void				
  Render();
  
  void				
  Destroy();
  
  void				
  Update();

  Scene() = default;
  ~Scene() = default;
};

