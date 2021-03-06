/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#if defined(GD_IDE_ONLY)

#include "JsExtension.h"

#include "GDCore/Tools/Version.h"
#include <boost/version.hpp>
#include <iostream>
#include <wx/intl.h>
//Ensure the wxWidgets macro "_" returns a std::string
#if defined(_)
    #undef _
#endif
#define _(s) std::string(wxGetTranslation((s)).mb_str())

JsExtension::JsExtension() : gd::PlatformExtension()
{
    SetExtensionInformation("Array",
                            _("Array"),
                            _("Extension to store values and text inside arrays."),
                            "Victor Levasseur",
                            "zlib/libpng License ( Open Source )");

    CloneExtension("Game Develop C++ platform", "Array");

    DeclareArray3D();
    DeclareDictionary();

    StripUnimplementedInstructionsAndExpressions(); //Unimplemented things are listed here:
}

JsExtension::~JsExtension()
{

}

/**
 * Used by Game Develop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" gd::PlatformExtension * GD_EXTENSION_API CreateGDJSExtension() {
    return new JsExtension;
}

/**
 * Used by Game Develop to destroy the extension class
 * -- Do not need to be modified. --
 */
extern "C" void GD_EXTENSION_API DestroyGDJSExtension(gd::PlatformExtension * p) {
    delete p;
}
#endif
