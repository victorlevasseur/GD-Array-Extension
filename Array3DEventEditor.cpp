/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#include "Array3DEventEditor.h"

#if defined(GD_IDE_ONLY)

#include "GDCore/IDE/CommonBitmapManager.h"
#include "GDCore/IDE/Dialogs/EditStrExpressionDialog.h"
#include "GDCpp/CommonTools.h"

//(*InternalHeaders(Array3DEventEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Array3DEventEditor)
const long Array3DEventEditor::ID_STATICTEXT1 = wxNewId();
const long Array3DEventEditor::ID_TEXTCTRL1 = wxNewId();
const long Array3DEventEditor::ID_BITMAPBUTTON1 = wxNewId();
const long Array3DEventEditor::ID_BUTTON1 = wxNewId();
const long Array3DEventEditor::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Array3DEventEditor,wxDialog)
	//(*EventTable(Array3DEventEditor)
	//*)
END_EVENT_TABLE()

Array3DEventEditor::Array3DEventEditor(wxWindow* parent, arr::threeDim::Array3DEvent & event_, gd::Project & game_, gd::Layout & scene_)
: eventEdited(event_), game(game_), scene(scene_)
{
	//(*Initialize(Array3DEventEditor)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Edit \"Iterate through an array\" event"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(323,86));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Array\'s name :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	arrayNameTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(arrayNameTextCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	editStrBt = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	editStrBt->SetDefault();
	FlexGridSizer2->Add(editStrBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	okBt = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cancelBt = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(cancelBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Array3DEventEditor::OneditStrBtClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Array3DEventEditor::OnokBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Array3DEventEditor::OncancelBtClick);
	//*)

	arrayNameTextCtrl->SetValue(eventEdited.GetArrayName().c_str());
	editStrBt->SetBitmap(gd::CommonBitmapManager::GetInstance()->texteBt);
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

void Array3DEventEditor::OneditStrBtClick(wxCommandEvent& event)
{
    gd::EditStrExpressionDialog dialog(this, ToString(arrayNameTextCtrl->GetValue()), game, scene);

    if(dialog.ShowModal() != 0)
    {
        arrayNameTextCtrl->SetValue(dialog.GetExpression().c_str());
    }
}

#endif

