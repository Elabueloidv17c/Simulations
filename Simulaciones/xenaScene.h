#pragma once
#include "Scene.h"

/**
*@brief this class represents a scene with obstacles
*/

class xenaScene :
  public Scene 
{
public:
  xenaScene();
  ~xenaScene() = default;


public: 
  /*! renders an obstacle intended 
  for Xena chakram*/
  void
  Render() override;

  void
  Initialize(RenderWindow* renderTarget, Color background, Timer* timer) override;
  



};

