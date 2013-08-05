#ifndef ARRAY3DEVENTEDITOR_H
#define ARRAY3DEVENTEDITOR_H

#include "Array3DEvent.h"

#if defined(GD_IDE_ONLY)

//(*Headers(Array3DEventEditor)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Array3DEventEditor: public wxDialog
{
	public:

		Array3DEventEditor(wxWindow* parent, arr::vec::Array3DEvent & event_, gd::Project & game_, gd::Layout & scene_);
		virtual ~Array3DEventEditor();

		//(*Declarations(Array3DEventEditor)
		wxStaticText* StaticText1;
		wxButton* cancelBt;
		wxTextCtrl* arrayNameTextCtrl;
		wxBitmapButton* editStrBt;
		wxButton* okBt;
		//*)

	protected:

		//(*Identifiers(Array3DEventEditor)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BITMAPBUTTON1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Array3DEventEditor)
		void OnokBtClick(wxCommandEvent& event);
		void OncancelBtClick(wxCommandEvent& event);
		void OneditStrBtClick(wxCommandEvent& event);
		//*)

		arr::vec::Array3DEvent & eventEdited;
		gd::Project & game;
		gd::Layout & scene;

		DECLARE_EVENT_TABLE()
};

#endif

#endif
