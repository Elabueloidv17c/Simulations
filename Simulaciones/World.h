#pragma once

#include "Headers.h"
#include "Scene.h"
#include "xenaScene.h"

class World
{
  RenderWindow*	
  m_renderTarget;

  //Scene        
  
  //m_scene;

  xenaScene
    m_scene;

  Timer*
  m_timer;

 public:

  void					
  Initialize(RenderWindow* renderTarget, Timer* timer);
  
  void
  ProcessInput(const Event& event);
  
  void
  Destroy();
  
  void
  Update();
  
  void
  Render();

  World() = default;
  ~World() = default;
};

