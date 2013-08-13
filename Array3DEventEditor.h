/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

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

		Array3DEventEditor(wxWindow* parent, arr::threeDim::Array3DEvent & event_, gd::Project & game_, gd::Layout & scene_);
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

		arr::threeDim::Array3DEvent & eventEdited;
		gd::Project & game;
		gd::Layout & scene;

		DECLARE_EVENT_TABLE()
};

#endif

#endif
