#pragma once

#include "Headers.h"
#include "Camera.h"

class Scene
{
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
  
  void				
  Initialize(RenderWindow* renderTarget, Color background, Timer* timer);

  void				
  ProcessInput(const Event& event);

  void				
  Render();
  
  void				
  Destroy();
  
  void				
  Update();

  Scene() = default;
  ~Scene() = default;
};

