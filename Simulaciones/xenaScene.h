#pragma once
#include "Scene.h"
#include <vector>

/**
*@brief this class represents a scene with obstacles 
*
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
  
  // for all the sprites 
  std::vector<sf::Sprite> m_sprites;

  // for all the textures 
  std::vector<sf::Texture> m_textures;


};

