/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/
#include "mitkPlanarFigureControlPointStyleProperty.h"

mitk::PlanarFigureControlPointStyleProperty::PlanarFigureControlPointStyleProperty()
{
  this->AddEnumTypes();
  this->SetValue(static_cast<IdType>(Square));
}

mitk::PlanarFigureControlPointStyleProperty::PlanarFigureControlPointStyleProperty(const IdType &value)
{
  this->AddEnumTypes();
  if (this->IsValidEnumerationValue(value))
  {
    this->SetValue(value);
  }
  else
  {
    this->SetValue(static_cast<IdType>(Square));
  }
}

mitk::PlanarFigureControlPointStyleProperty::PlanarFigureControlPointStyleProperty(const std::string &value)
{
  this->AddEnumTypes();
  if (this->IsValidEnumerationValue(value))
  {
    this->SetValue(value);
  }
  else
  {
    this->SetValue(static_cast<IdType>(Square));
  }
}

void mitk::PlanarFigureControlPointStyleProperty::AddEnumTypes()
{
  this->AddEnum("Square", static_cast<IdType>(Square));
  this->AddEnum("Circle", static_cast<IdType>(Circle));
}

bool mitk::PlanarFigureControlPointStyleProperty::AddEnum(const std::string &name, const IdType &id)
{
  return Superclass::AddEnum(name, id);
}

mitk::PlanarFigureControlPointStyleProperty::Shape mitk::PlanarFigureControlPointStyleProperty::GetShape()
{
  return static_cast<mitk::PlanarFigureControlPointStyleProperty::Shape>(this->GetValueAsId());
}

void mitk::PlanarFigureControlPointStyleProperty::SetShape(mitk::PlanarFigureControlPointStyleProperty::Shape shape)
{
  this->SetValue(static_cast<IdType>(shape));
}

itk::LightObject::Pointer mitk::PlanarFigureControlPointStyleProperty::InternalClone() const
{
  itk::LightObject::Pointer result(new Self(*this));
  result->UnRegister();
  return result;
}
