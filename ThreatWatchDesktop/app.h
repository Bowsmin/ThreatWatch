#pragma once

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/frame.h>
#include "threats.h"
#include "frame.h"
#include "id.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class app : public wxApp
{
public:
    app();
    virtual bool OnInit();
    ~app();
};

DECLARE_APP(app); //wxGetApp();

