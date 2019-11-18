#pragma once
#include "Scene.h"
#include "cEntity.h"
#include "cMap.h"

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
  
protected:

  bool
  loadTextures();

  bool
  loadMap(const char* mapFile);

  void
  loadBricks();

private:// variables 

  // for all the sprites 
  std::vector<cEntity>
  m_entity;

  // for all the textures 
  std::vector<sf::Texture>
  m_textures;

  cMap m_map;
  
};

