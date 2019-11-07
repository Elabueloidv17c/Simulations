#pragma once

#include "Headers.h"
#include "Timer.h"

class Camera
{
  View m_camera;
  float m_movementSpeed;
  float m_rotationSpeed;
  float m_zoomSpeed;
 
  Timer* m_timer;

 public:

   View*
   GetView();

   void
   Initialize(Vector2f size, float movementSpeed, float rotationSpeed, 
              float zoomSpeed, Timer* timer);

   void 
   Resize(Vector2f size);

   void 
   MoveUp();

   void 
   MoveDown();

   void 
   MoveLeft();

   void 
   MoveRight();

   void 
   ZoomIn();

   void 
   ZoomOut();

   Camera() = default;
   ~Camera() = default;
};

