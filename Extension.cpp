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

    /// Value at an index

    AddAction("3D_SetValueAsNumber",
              _("Set a value"),
              _("Set a value as a number at a specific index."),
              _("Do _PARAM4__PARAM5_ to the value of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_]"),
              _("3D Array"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("expression", _("X index"))
        .AddParameter("expression", _("Y index"), "", true)
        .AddParameter("expression", _("Z index"), "", true)
        .AddParameter("operator", _("Modification's sign"))
        .AddParameter("expression", _("Value"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::SetValueAsNumber")
                             .SetManipulatedType("number")
                             .SetAssociatedGetter("arr::threeDim::GetValueAsNumber")
                             .SetIncludeFile("Array/Array3DTools.h");

    AddCondition("3D_TestValueAsNumber",
                 _("Value at an index"),
                 _("Test the value (as number) at a specific index."),
                 _("The value of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_] is _PARAM4__PARAM5_"),
                 _("3D Array"),
                 "res/array24.png",
                 "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("expression", _("X index"))
        .AddParameter("expression", _("Y index"), "", true)
        .AddParameter("expression", _("Z index"), "", true)
        .AddParameter("relationalOperator", _("Comparison's sign"))
        .AddParameter("expression", _("Value"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetValueAsNumber")
                             .SetManipulatedType("number")
                             .SetIncludeFile("Array/Array3DTools.h");

    AddExpression("3D::At", _("Value at an index"), _("Value at an index"), _("3D Array"), "res/actions/rotate.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("expression", _("X index"))
        .AddParameter("expression", _("Y index"), "", true)
        .AddParameter("expression", _("Z index"), "", true)
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetValueAsNumber")
                             .SetIncludeFile("Array/Array3DTools.h");

    /// Text at an index

    AddAction("3D_SetValueAsText",
              _("Set a text"),
              _("Set a text at a specific index."),
              _("Do _PARAM4__PARAM5_ to the text of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_]"),
              _("3D Array"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("expression", _("X index"))
        .AddParameter("expression", _("Y index"), "", true)
        .AddParameter("expression", _("Z index"), "", true)
        .AddParameter("operator", _("Modification's sign"))
        .AddParameter("string", _("Text"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::SetValueAsString")
                             .SetManipulatedType("string")
                             .SetAssociatedGetter("arr::threeDim::GetValueAsString")
                             .SetIncludeFile("Array/Array3DTools.h");

    AddCondition("3D_TestValueAsText",
                 _("Text at an index"),
                 _("Test the text at a specific index."),
                 _("The text of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_] is _PARAM4__PARAM5_"),
                 _("3D Array"),
                 "res/array24.png",
                 "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("expression", _("X index"))
        .AddParameter("expression", _("Y index"), "", true)
        .AddParameter("expression", _("Z index"), "", true)
        .AddParameter("relationalOperator", _("Comparison's sign"))
        .AddParameter("string", _("Text"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetValueAsString")
                             .SetManipulatedType("string")
                             .SetIncludeFile("Array/Array3DTools.h");

    AddStrExpression("3D::At", _("Text at an index"), _("Text at an index"), _("3D Array"), "res/actions/rotate.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("expression", _("X index"))
        .AddParameter("expression", _("Y index"), "", true)
        .AddParameter("expression", _("Z index"), "", true)
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetValueAsString")
                             .SetIncludeFile("Array/Array3DTools.h");

    /// Insert a value (number or text)

    AddAction("3D_InsertValueAsNumber",
              _("Insert a value"),
              _("Insert a value (number) at a specific index."),
              _("Insert _PARAM3_ at the index _PARAM2_ on the axis _PARAM1_ of _PARAM0_"),
              _("3D Array"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("string", _("Axis (\"X\", \"Y\" or \"Z\")")).SetDefaultValue("\"X\"")
        .AddParameter("expression", _("Index in that axis"))
        .AddParameter("expression", _("Value"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::InsertValueAsNumber")
                             .SetIncludeFile("Array/Array3DTools.h");

    AddAction("3D_InsertValueAsText",
              _("Insert a text"),
              _("Insert a text at a specific index."),
              _("Insert _PARAM3_ at the index _PARAM2_ on the axis _PARAM1_ of _PARAM0_"),
              _("3D Array"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("string", _("Axis (\"X\", \"Y\" or \"Z\")")).SetDefaultValue("\"X\"")
        .AddParameter("expression", _("Index in that axis"))
        .AddParameter("string", _("Text"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::InsertValueAsString")
                             .SetIncludeFile("Array/Array3DTools.h");

    /// Remove a value

    AddAction("3D_RemoveValue",
              _("Remove an index"),
              _("Remove an index from the array."),
              _("Remove the index _PARAM2_ on the axis _PARAM1_ of _PARAM0_"),
              _("3D Array"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("string", _("Axis (\"X\", \"Y\" or \"Z\")")).SetDefaultValue("\"X\"")
        .AddParameter("expression", _("Index in that axis"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::RemoveValue")
                             .SetIncludeFile("Array/Array3DTools.h");

    /// Set size

    AddAction("3D_SetSize",
              _("Set size"),
              _("Set the size of an array.\nThis action is needed to create the array, otherwise the array is empty (size of 0 on X, Y and Z)."),
              _("Set the size of _PARAM0_ to _PARAM1_;_PARAM2_;_PARAM3_"),
              _("3D Array"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddParameter("expression", _("Width (size on X)"))
        .AddParameter("expression", _("Height (size on Y)"))
        .AddParameter("expression", _("Depth (size on Z)"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::SetSize")
                             .SetIncludeFile("Array/Array3DTools.h");

    /// Get width, height, depth

    AddExpression("3D::Width", _("Width of an array"), _("Width of an array"), _("3D Array"), "res/actions/rotate.png")

        .AddParameter("string", _("Array Name"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetWidth").SetIncludeFile("Array/Array3DTools.h");

    AddExpression("3D::Height", _("Height of an array"), _("Height of an array"), _("3D Array"), "res/actions/rotate.png")

        .AddParameter("string", _("Array Name"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetHeight").SetIncludeFile("Array/Array3DTools.h");

    AddExpression("3D::Depth", _("Depth of an array"), _("Depth of an array"), _("3D Array"), "res/actions/rotate.png")

        .AddParameter("string", _("Array Name"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetDepth").SetIncludeFile("Array/Array3DTools.h");

    /// Iterate event

    {
        gd::EventMetadata::CodeGenerator * arr3DCodeGen = new arr::threeDim::Array3DEvent::CodeGenerator;

        AddEvent("Array3DIterate",
                 _("Iterate in a 3D Array"),
                 _("Execute the event for each values contained in a 3D Array. You can access the value and its index by using dedicated expressions"),
                 "",
                 "res/function.png",
                 boost::shared_ptr<gd::BaseEvent>(new arr::threeDim::Array3DEvent))
        .SetCodeGenerator(boost::shared_ptr<gd::EventMetadata::CodeGenerator>(arr3DCodeGen));
    }

    AddExpression("3D::CurrentX",
                  _("Current X position in array"),
                  _("Return the current X position in the array (when you use the \"iterate through 3D array\" event)"),
                  _("3D Array"),
                  "res/function.png")

        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetCurrentX")
                             .SetIncludeFile("Array/Array3DTools.h");


    AddExpression("3D::CurrentY",
                  _("Current Y position in array"),
                  _("Return the current Y position in the array (when you use the \"iterate through 3D array\" event)"),
                  _("3D Array"),
                  "res/function.png")

        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetCurrentY")
                             .SetIncludeFile("Array/Array3DTools.h");


    AddExpression("3D::CurrentZ",
                  _("Current Z position in array"),
                  _("Return the current Z position in the array (when you use the \"iterate through 3D array\" event)"),
                  _("3D Array"),
                  "res/function.png")

        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetCurrentZ")
                             .SetIncludeFile("Array/Array3DTools.h");


    AddExpression("3D::Current",
                  _("Current value in array"),
                  _("Return the current value in the array (when you use the \"iterate through 3D array\" event)"),
                  _("3D Array"),
                  "res/function.png")

        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetCurrentAsNumber")
                             .SetIncludeFile("Array/Array3DTools.h");


    AddStrExpression("3D::Current",
                     _("Current text in array"),
                     _("Return the current text in the array (when you use the \"iterate through 3D array\" event)"),
                     _("3D Array"),
                     "res/function.png")

        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::GetCurrentAsString")
                             .SetIncludeFile("Array/Array3DTools.h");



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

