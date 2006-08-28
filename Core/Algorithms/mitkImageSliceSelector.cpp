/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile$
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/


#include "mitkImageSliceSelector.h"


//##ModelId=3E1A0A2E027F
void mitk::ImageSliceSelector::GenerateOutputInformation()
{
	mitk::Image::ConstPointer input  = this->GetInput();
	mitk::Image::Pointer output = this->GetOutput();

	itkDebugMacro(<<"GenerateOutputInformation()");

	output->Initialize(input->GetPixelType(), 2, input->GetDimensions());

  // initialize geometry
  output->SetGeometry(dynamic_cast<Geometry3D*>(input->GetSlicedGeometry(m_TimeNr)->GetGeometry2D(m_SliceNr)->Clone().GetPointer()));
  output->SetPropertyList(input->GetPropertyList()->Clone());
}

//##ModelId=3E1A0A320090
void mitk::ImageSliceSelector::GenerateData()
{
	SetSliceItem(GetSliceData(m_SliceNr, m_TimeNr, m_ChannelNr), 0);
}

//##ModelId=3E1B196A0188
mitk::ImageSliceSelector::ImageSliceSelector() : m_SliceNr(0), m_TimeNr(0), m_ChannelNr(0)
{
}


//##ModelId=3E1B196A01C4
mitk::ImageSliceSelector::~ImageSliceSelector()
{
}

void mitk::ImageSliceSelector::GenerateInputRequestedRegion()
{
  Superclass::GenerateInputRequestedRegion();

  mitk::ImageToImageFilter::InputImagePointer input =
    const_cast< mitk::ImageToImageFilter::InputImageType * > ( this->GetInput() );
  mitk::Image::Pointer output = this->GetOutput();

  Image::RegionType requestedRegion;
  requestedRegion = output->GetRequestedRegion();
  requestedRegion.SetIndex(2, m_SliceNr);
  requestedRegion.SetIndex(3, m_TimeNr);
  requestedRegion.SetIndex(4, m_ChannelNr);
  requestedRegion.SetSize(2, 1);
  requestedRegion.SetSize(3, 1);
  requestedRegion.SetSize(4, 1);

  input->SetRequestedRegion( & requestedRegion );
}
