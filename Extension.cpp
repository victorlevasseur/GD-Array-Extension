/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#include "Extension.h"

#include "GDCpp/ExtensionBase.h"
#include "GDCore/Tools/Version.h"
#include "GDCore/Events/ExpressionsCodeGeneration.h"
#include "GDCore/Events/EventsCodeGenerationContext.h"
#include "GDCore/Events/EventsCodeGenerator.h"
#include "GDCore/Events/EventMetadata.h"
#include <boost/version.hpp>

#if defined(GD_IDE_ONLY)
#include "GDCore/Events/Instruction.h"
#endif // defined

#include "ArrayTools.h"
#include "Array3DEvent.h"

Extension::Extension() : ExtensionBase()
{
    SetExtensionInformation("Array",
                            _("Array"),
                            _("Extension to store values and text inside arrays."),
                            "Victor Levasseur",
                            "zlib/libpng License ( Open Source )");

#if defined(GD_IDE_ONLY)

    /// Reset all arrays of a scene (do it at the beginning)

    AddAction("Init",
              _("Initialize"),
              _("Initialize the scene's arrays.\nThis action need to be executed at the beginning of the scene before any actions related to the arrays."),
              _("Initialize arrays"),
              _("Array"),
              "res/array24.png",
              "res/array.png")

        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::InitArrays")
        .SetIncludeFile("Array/ArrayTools.h");

    DeclareArray3D();

#endif

    GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
}

Extension::~Extension()
{
    arr::ArrayManager::Kill();
}


/**
 * Used by Game Develop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension()
{
    return new Extension;
}

/**
 * Used by Game Develop to destroy the extension class
 * -- Do not need to be modified. --
 */
extern "C" void GD_EXTENSION_API DestroyGDExtension(ExtensionBase * p)
{
    delete p;
}

