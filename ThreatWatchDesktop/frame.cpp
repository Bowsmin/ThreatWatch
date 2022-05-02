#include "frame.h"

// Event table to handle events and functions
BEGIN_EVENT_TABLE(frame, wxFrame)
    EVT_MENU(wxID_NEW, frame::onAdd)
    EVT_BUTTON(10001, onAddClicked)
    EVT_BUTTON(10002, onRemoveClicked)
    EVT_BUTTON(10003, onListClicked)
    EVT_BUTTON(10004, onUpClicked)
END_EVENT_TABLE()

// Main frame of the gui
frame::frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name): 
    wxFrame(parent, id, title, pos, size, style ,name)
{
    // Setting window size, no settings added
    wxWindow::SetSize(800, 600);
    threatList = new threats();

    // Creation of the buttons
    m_btn1 = new wxButton(this, 10001, "Add", wxPoint(10, 120), wxSize(80, 30));
    m_btn2 = new wxButton(this, 10002, "Remove", wxPoint(110, 120), wxSize(80, 30));
    m_btn3 = new wxButton(this, 10003, "Sort by Threat Level", wxPoint(210, 120), wxSize(125, 30));
    m_btn4 = new wxButton(this, 10004, "Update", wxPoint(350, 120), wxSize(125, 30));
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "Threat Name", wxPoint(10, 10), wxSize(300, 30));
    m_comb2 = new wxComboBox(this, wxID_ANY, "Threat Score", wxPoint(10, 50), wxSize(300, 30), 10, theChoices2, 0, wxDefaultValidator, _("Threat Score"));
    m_comb1 = new wxComboBox(this, wxID_ANY, "Threat Level", wxPoint(10, 90), wxSize(300, 30), 5, theChoices1, 0, wxDefaultValidator, _("ThreatLvl"));
    m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 160), wxSize(300, 300));


    wxMenu* menuFile = new wxMenu;
    menuFile->AppendSeparator();

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    wxMenuItem* addItem = new wxMenuItem(menuFile, wxID_NEW, _("Add"));
    menuFile->Append(addItem);

    menuFile->AppendSeparator();

    wxMenuItem* quitItem = new wxMenuItem(menuFile, wxID_EXIT);
    quitItem->SetBitmap(wxArtProvider::GetBitmap("wxART_QUIT"));
    menuFile->Append(quitItem);




    Bind(wxEVT_MENU, &frame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &frame::OnAbout, this, wxID_ABOUT);
}

frame::~frame()
{
}

// Closes program on exit press
void frame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

// On About
void frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a simple threat info program created by Josiah Anderson",
        "About This App", wxOK | wxICON_INFORMATION);
}

void frame::onList(wxCommandEvent& event) {
    wxMessageBox("MainWindow::onList");
}

void frame::onAdd(wxCommandEvent& event)
{
    
}

// When add is clicked, it will add the values to threatList and to the wxWidgetsList
void frame::onAddClicked(wxCommandEvent& event)
{
    wxString str1 = m_txt1->GetValue();

    if (str1 == "Threat Name" || str1 == "") {
        wxMessageBox("Input a threat name");
        return;
    }

    wxString str2 = m_comb1->GetStringSelection();
    wxString str3 = m_comb2->GetStringSelection();
    std::string cStr1 = std::string(str1.mb_str());
    std::string cStr2 = std::string(str2.mb_str());

    // Converts wxString to double
    double value;
    str3.ToDouble(&value);


    std::string outStr;

    // Attempts to add to the map, will catch error
    try {
        threatList->add(cStr1, value, cStr2);
    }
    catch (invalidThreatLvlException) {
        wxMessageBox("Please select threat level");
    }

    // Clears the list
    m_list1->Clear();
    // Not the best way of doing this... Loops through the threatList map and appends it to the wxList
    for (auto i = threatList->threatList.begin(); i != threatList->threatList.end(); i++) {
        outStr = i->first + ", " + i->second.threatLvl + ", " + std::to_string(i->second.threatScore);
        wxString wOutStr(outStr.c_str(), wxConvUTF8);
        m_list1->AppendString(wOutStr);
    }
    // Updates the program
    Update();
}

// To remove an item
void frame::onRemoveClicked(wxCommandEvent& event)
{

    wxString wxSelect;
    std::string selection;
    std::string outStr;
    int count = -1;

    if (threatList->threatList.empty()) {
        wxMessageBox("List is empty");
        return;
    }

    else {
        // Get the selection from the wxList
        try {
            wxSelect = m_list1->GetStringSelection();
            selection = std::string(wxSelect.mb_str());
        }
        catch (std::exception& e) {
            wxMessageBox("Nothing selected from the list");
        }

        // Get the name of the selection
        for (int i = 0; i < selection.size(); i++) {
            if (isspace(selection[i])) {
                break;
            }
            count++;
        }
        // Resize with count so we can run it through the threatList remove
        std::string remove = selection;
        remove.resize(count);

        threatList->remove(remove);

        // Clear the wxList
        m_list1->Clear();

        // Add back to the wxList


        for (auto i = threatList->threatList.begin(); i != threatList->threatList.end(); i++) {
            outStr = i->first + ", " + i->second.threatLvl + ", " + std::to_string(i->second.threatScore);
            wxString wOutStr(outStr.c_str(), wxConvUTF8);
            m_list1->AppendString(wOutStr);
        }
        // Update frame
        Update();
    }

}

// Button to sort the list
void frame::onListClicked(wxCommandEvent& event)
{
    std::string outStr;
    // Calls threatList sort
    threatList->sort();
    // Clears the list
    m_list1->Clear();

    // Adds back to wxList
    for (auto i = threatList->threatList.begin(); i != threatList->threatList.end(); i++) {
        outStr = i->first + ", " + i->second.threatLvl + ", " + std::to_string(i->second.threatScore);
        wxString wOutStr(outStr.c_str(), wxConvUTF8);
        m_list1->AppendString(wOutStr);
    }
    // Updates
    Update();
}

// Update button function
void frame::onUpClicked(wxCommandEvent& event)
{

    wxString wxSelect;
    std::string selection;
    int count = -1;

    if (threatList->threatList.empty()) {
        wxMessageBox("List is empty");
        return;
    }
    else {
        // Gets the selection from wxList
        try {
            wxSelect = m_list1->GetStringSelection();
            selection = std::string(wxSelect.mb_str());
        }
        catch (std::exception& e) {
            wxMessageBox("Nothing selected from the list");
        }

        // Gets the name of said selection
        for (int i = 0; i < selection.size(); i++) {
            if (isspace(selection[i])) {
                break;
            }
            count++;
        }

        // Resizes for use of name on threatList
        std::string update = selection;
        update.resize(count);

        // Grabs the other two boxes
        wxString str2 = m_comb1->GetStringSelection();
        wxString str3 = m_comb2->GetStringSelection();
        std::string cStr2 = std::string(str2.mb_str());

        // Converst wxString to double
        double value;
        str3.ToDouble(&value);


        std::string outStr;

        // Calls threatlist Edit
        try {
            threatList->edit(update, value, cStr2);
        }
        catch (invalidThreatLvlException) {
            wxMessageBox("Please select threat level");
        }

        // Clears list
        m_list1->Clear();
        // Adds to list
        for (auto i = threatList->threatList.begin(); i != threatList->threatList.end(); i++) {
            outStr = i->first + ", " + i->second.threatLvl + ", " + std::to_string(i->second.threatScore);
            wxString wOutStr(outStr.c_str(), wxConvUTF8);
            m_list1->AppendString(wOutStr);
        }
        // Updates
        Update();
    }
}

