#include "cMap.h"
#include <sstream>
#include <functional>

bool
cMap::init(const std::string& FilePath)
{
  if (!loadFile(FilePath))
  {
    return false;
  }
  else
  {
    Parse();
  }

  return true;
}

sMapDim
cMap::getMapDimentions() const
{
  return m_mapDim;
}

size_t 
cMap::getPositionsCount() const
{
  return m_positionsOfEntitys.size();
}

std::vector<Point>* 
cMap::getPositionsPtr()
{
  return &m_positionsOfEntitys;
}

std::vector<Point>&
cMap::getPositionsRef()
{
  return std::ref(m_positionsOfEntitys).get();
}

bool
cMap::loadFile(const std::string& FilePath)
{
  std::ifstream fileStream(FilePath);
  if (fileStream.is_open())
  {
    std::stringstream SStream;
    SStream << fileStream.rdbuf();
    m_map = SStream.str();
    fileStream.close();
  }
  else {
    return false;
  }


  return true;
}

void
cMap::Parse()
{
  /* FORMAT
  ** here is the char that make up the format
  *  'R' or 'r' is the place where a rock is located relative to the map.
  *  ',' will be used to separate and count columns.
  *  ' ' white-space indicates that there is nothing in that particular row and column.
  *  '\n' new line char's will be used to separate and rows
  */
  m_mapDim.columns = 1;
  m_mapDim.rows = 1;
  int32_t  currentMaxColumns = 1;
  int32_t  currentColumnsCountOnRow = 1;

  std::cout << "Map \n" << m_map;

  for (auto iter = m_map.begin(); iter != m_map.end(); ++iter) {
    // create the positions rocks 
    if (*iter == 'R' || *iter == 'r') {
      m_positionsOfEntitys.emplace_back(Point(currentColumnsCountOnRow, m_mapDim.rows));
    }
    // count the rows 
    else if (*iter == '\n' || *iter == '\r') {
      m_mapDim.rows++;
      currentColumnsCountOnRow = 1;
    }
    else if (*iter == ',') {
      currentColumnsCountOnRow++;
      currentMaxColumns = returnColumnsMax(currentMaxColumns, currentColumnsCountOnRow);
    }

  }
  m_mapDim.columns = currentMaxColumns;


}

int32_t
cMap::returnColumnsMax(int32_t currentMax, int32_t currentCount)
{
  return  std::max(currentCount, currentMax);
}

