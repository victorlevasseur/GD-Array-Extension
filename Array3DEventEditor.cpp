#include "Array3DEventEditor.h"

#if defined(GD_IDE_ONLY)

#include "GDCpp/CommonTools.h"

//(*InternalHeaders(Array3DEventEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Array3DEventEditor)
const long Array3DEventEditor::ID_STATICTEXT1 = wxNewId();
const long Array3DEventEditor::ID_TEXTCTRL1 = wxNewId();
const long Array3DEventEditor::ID_BUTTON1 = wxNewId();
const long Array3DEventEditor::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Array3DEventEditor,wxDialog)
	//(*EventTable(Array3DEventEditor)
	//*)
END_EVENT_TABLE()

Array3DEventEditor::Array3DEventEditor(wxWindow* parent, arr::vec::Array3DEvent & event_, gd::Project & game_, gd::Layout & scene_)
: eventEdited(event_), game(game_), scene(scene_)
{
	//(*Initialize(Array3DEventEditor)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Edit \"Iterate through an array\" event"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Array\'s name :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	arrayNameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(arrayNameTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	okBt = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cancelBt = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(cancelBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Array3DEventEditor::OnokBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Array3DEventEditor::OncancelBtClick);
	//*)

	arrayNameTextCtrl->SetValue(eventEdited.GetArrayName().c_str());
}

Array3DEventEditor::~Array3DEventEditor()
{
	//(*Destroy(Array3DEventEditor)
	//*)
}

void Array3DEventEditor::OnokBtClick(wxCommandEvent& event)
{
    eventEdited.SetArrayName(ToString(arrayNameTextCtrl->GetValue()));

    EndModal(1);
}

void Array3DEventEditor::OncancelBtClick(wxCommandEvent& event)
{
    EndModal(0);
}

#endif
