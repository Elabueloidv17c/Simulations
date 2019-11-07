#pragma once
#include "Headers.h"
#include "World.h"
#include "Timer.h"

class Application
{
  RenderWindow	
  m_window;
  
  Event					
  m_event;

  Timer					
  m_timer;

  World
  m_world;

 public:
   
  void 
  Run();

  void					
  Initialize(WindowData window);
  
  void
  ProcessInput();
  
  void
  Destroy();
  
  void
  Update();
  
  void
  Render();
};

