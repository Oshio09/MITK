/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef QMITKDATANODECOLORMAPACTION_H
#define QMITKDATANODECOLORMAPACTION_H

#include <org_mitk_gui_qt_application_Export.h>

#include "QmitkAbstractDataNodeAction.h"

// qt
#include <QAction>

class MITK_QT_APP QmitkDataNodeColorMapAction : public QAction, public QmitkAbstractDataNodeAction
{
  Q_OBJECT

public:

  QmitkDataNodeColorMapAction(QObject* parent, berry::IWorkbenchPartSite::Pointer workbenchPartSite);
  QmitkDataNodeColorMapAction(QObject* parent, berry::IWorkbenchPartSite* workbenchPartSite);

  virtual ~QmitkDataNodeColorMapAction() override;

private Q_SLOTS:

  void OnMenuAboutShow();
  void OnActionTriggered(bool);

protected:

  virtual void InitializeAction() override;

};

#endif // QMITKDATANODECOLORMAPACTION_H
