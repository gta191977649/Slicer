// .NAME vtkSlicerApplicationSettingsInterface
// .SECTION Description
// Slicer specific ApplicationSettingsInterface. Provides a user
// interface to set/view application settings.
//

#ifndef __vtkSlicerApplicationSettingsInterface_h
#define __vtkSlicerApplicationSettingsInterface_h

#include "vtkSlicerBaseGUIWin32Header.h"
#include "vtkKWApplicationSettingsInterface.h"

class vtkKWFrameWithLabel;
class vtkKWEntryWithLabel;
class vtkKWLoadSaveButtonWithLabel;
class vtkKWCheckButton;

class VTK_SLICER_BASE_GUI_EXPORT vtkSlicerApplicationSettingsInterface
  : public vtkKWApplicationSettingsInterface
{
public:
  static vtkSlicerApplicationSettingsInterface* New();
  vtkTypeRevisionMacro(vtkSlicerApplicationSettingsInterface,vtkKWApplicationSettingsInterface);

  // Description:
  // Create the widget.
  virtual void Create();
  
  // Description:
  // Refresh the interface given the current value of the Window and its
  // views/composites/widgets.
  virtual void Update();

  // Description:
  // Callbacks for the Module application settings. Internal, do not use.
  virtual void ModulePathCallback(char *);
  virtual void HomeModuleCallback(char *name);
  virtual void TemporaryDirectoryCallback();

  // Description:
  // Callbacks for the Slicer application settings
  virtual void ConfirmDeleteCallback(int state);
  
protected:
  vtkSlicerApplicationSettingsInterface();
  ~vtkSlicerApplicationSettingsInterface();

  
private:
  vtkSlicerApplicationSettingsInterface(const vtkSlicerApplicationSettingsInterface&); // Not implemented
  void operator=(const vtkSlicerApplicationSettingsInterface&); // Not Implemented

  vtkKWFrameWithLabel *SlicerSettingsFrame;
  vtkKWCheckButton  *ConfirmDeleteCheckButton;
  
  vtkKWFrameWithLabel *ModuleSettingsFrame;
  vtkKWEntryWithLabel *HomeModuleEntry;
  vtkKWEntryWithLabel *ModulePathEntry;
  vtkKWLoadSaveButtonWithLabel *TemporaryDirectoryButton;
};


#endif
