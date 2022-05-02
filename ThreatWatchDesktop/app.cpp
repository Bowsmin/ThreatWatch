
#include "app.h"


wxIMPLEMENT_APP(app); // Main

app::app()
{
    
}

bool app::OnInit()
{
    
    frame *theFrame = new frame(nullptr, window::id::MAINWINDOW, _("Threat Watch"));
    theFrame->Show(true);
    SetTopWindow(theFrame);
    return true;
}

app::~app()
{
}
