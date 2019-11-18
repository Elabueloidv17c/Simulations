#pragma once
#include<fstream>
#include <string>
#include "Headers.h"

/**
*@brief keeps track of the dimension of the map
*/
struct sMapDim
{
  int32_t columns{ -1 };
  int32_t rows{ -1 };

  //constructors
  sMapDim() = default;
  sMapDim(int32_t newColumns, int32_t newRows) {
    this->columns = newColumns;
    this->rows = newRows;
  }

};


/** keeps track all data related with the map like where every entity 
* goes, how many rows and columns the map consist of, and parsing the data 
* of the map
*/
class cMap
{
public:// constructors 
  cMap() = default;
  ~cMap() = default;

public:// functions 
  /** prepares the map for use */
  bool 
  init(const std::string& FilePath);

  /** returns the dimensions */
  sMapDim
  getMapDimentions() const;

  size_t
  getPositionsCount() const;

  std::vector<Point>*
  getPositionsPtr();

  std::vector<Point>&
  getPositionsRef();

private:
  //* load the given file 
  bool
  loadFile(const std::string& FilePath);

  //* parses the file to get the information form it 
  void 
  Parse();

  int32_t
  returnColumnsMax(int32_t currentMax, int32_t currentCount);

private:
  //! stores the string that represents the map
  std::string 
  m_map;

  //! keeps track of how many columns and rows the map has.
  sMapDim
  m_mapDim;

  //! stores the positions of all the entity's positions
  std::vector<Point> 
  m_positionsOfEntitys;

};

