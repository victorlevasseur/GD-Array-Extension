#include "Extension.h"
#include "JsExtension.h"

#include "ArrayTools.h"
#include "Array3DEvent.h"

void Extension::DeclareArray3D()
{
    #if defined(GD_IDE_ONLY)

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

    /// Clear

    AddAction("3D_Clear",
              _("Clear"),
              _("Clear an array.\nNote that"),
              _("Clear the array _PARAM0_"),
              _("3D Array"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Array Name"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::threeDim::Clear")
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
}

#if defined(GD_IDE_ONLY)

void JsExtension::DeclareArray3D()
{

}

#endif
