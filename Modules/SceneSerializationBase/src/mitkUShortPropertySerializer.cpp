/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef mitkUShortPropertySerializer_h_included
#define mitkUShortPropertySerializer_h_included

#include "mitkBasePropertySerializer.h"

#include "mitkProperties.h"

namespace mitk
{
  class UShortPropertySerializer : public BasePropertySerializer
  {
  public:
    mitkClassMacro(UShortPropertySerializer, BasePropertySerializer);
    itkFactorylessNewMacro(Self) itkCloneMacro(Self)

      TiXmlElement *Serialize() override
    {
      if (const UShortProperty *prop = dynamic_cast<const UShortProperty *>(m_Property.GetPointer()))
      {
        auto element = new TiXmlElement("unsigned");
        element->SetAttribute("value", static_cast<unsigned short>(prop->GetValue()));
        return element;
      }
      else
        return nullptr;
    }

    BaseProperty::Pointer Deserialize(TiXmlElement *element) override
    {
      if (!element)
        return nullptr;

      unsigned int value;
      if (element->QueryUnsignedAttribute("value", &value) == TIXML_SUCCESS)
      {
        return UShortProperty::New(static_cast<unsigned short>(value)).GetPointer();
      }
      else
      {
        return nullptr;
      }
    }

  protected:
    UShortPropertySerializer() {}
    ~UShortPropertySerializer() override {}
  };

} // namespace

// important to put this into the GLOBAL namespace (because it starts with 'namespace mitk')
MITK_REGISTER_SERIALIZER(UShortPropertySerializer);

#endif
