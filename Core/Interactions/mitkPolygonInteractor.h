#ifndef MITKPOLYGONINTERACTOR_H_HEADER_INCLUDED
#define MITKPOLYGONINTERACTOR_H_HEADER_INCLUDED

#include "mitkCommon.h"
#include <mitkInteractor.h>
#include "mitkLineInteractor.h"
#include "mitkPointInteractor.h"
#include <map>

namespace mitk
{
class DataTreeNode;

//##Documentation
//## @brief Interaction with a Polygon, a closed set of lines.
//## @ingroup Interaction
//## Interact with a Polygon. 
class PolygonInteractor : public Interactor
{
public:
  mitkClassMacro(PolygonInteractor, Interactor);
  
  typedef int IdType;
  typedef mitk::LineInteractor LineElement;
  typedef std::map<IdType, LineElement::Pointer> LineListType;
  typedef mitk::PointInteractor PointElement;
  typedef std::map<IdType, PointElement::Pointer> PointListType;
      
  //##Documentation
  //##@brief Constructor 
  PolygonInteractor(const char * type, DataTreeNode* dataTreeNode);

  //##Documentation
  //##@brief Destructor 
  virtual ~PolygonInteractor();

  //##Documentation
  //##@brief returns the Id of this Polygon
  int GetId();

protected:
  //##Documentation
  //## @brief Executes Side-Effects
  virtual bool ExecuteSideEffect(int sideEffectId, mitk::StateEvent const* stateEvent, int objectEventId, int groupEventId);

private:
  //##Documentation
  //## @brief lower Line Interactors 
  LineListType *m_LineList;

  //##Documentation
  //## @brief lower Line Interactors 
  PointListType *m_PointList;

  //##Documentation
  //## @brief id for a new Point; is increased after a creation of a new point
  int m_PointIdCount;

  //##Documentation
  //## @brief id for a new Line; is increased after a creation of a new Line
  int m_LineIdCount;
  
  //##Documentation
  //## @brief Identificationnumber of that Polygon
  int m_Id;

};
}
#endif /* MITKPOLYGONINTERACTOR_H_HEADER_INCLUDED */
