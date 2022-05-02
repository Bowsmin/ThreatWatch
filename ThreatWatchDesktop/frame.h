#pragma once
#include <wx/wxprec.h>
#include <wx/frame.h>
#include <wx/artprov.h>

#include <array>
#include <string>

#include "threats.h"
#include "frame.h"
#include "id.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class frame : public wxFrame
{
public:

    // Default parent constructor
    frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = wxFrameNameStr);
    ~frame();
    wxButton* m_btn1 = nullptr;
    wxButton* m_btn2 = nullptr;
    wxButton* m_btn3 = nullptr;
    wxButton* m_btn4 = nullptr;
    wxTextCtrl* m_txt1 = nullptr;
    wxListBox* m_list1 = nullptr;
    wxComboBox* m_comb1 = nullptr;
    wxComboBox* m_comb2 = nullptr;


private:
    // Threat Lvl Choices
    wxString theChoices1[5] = { _("None"), _("Low"), _("Medium"), _("High"), _("Critical") };
    // Threat Score Choices
    wxString theChoices2[10] = {_("1.0"), _("2.0"), _("3.0"), _("4.0"), _("5.0"), _("6.0"), _("7.0"), _("8.0"), _("9.0") , _("10") };

    // Button functions
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void onList(wxCommandEvent& event);
    void onAdd(wxCommandEvent& event);
    void onAddClicked(wxCommandEvent& event);
    void onRemoveClicked(wxCommandEvent& event);
    void onListClicked(wxCommandEvent& event);
    void onUpClicked(wxCommandEvent& event);
    // The threatList
    threats *threatList;


    DECLARE_EVENT_TABLE();
};

