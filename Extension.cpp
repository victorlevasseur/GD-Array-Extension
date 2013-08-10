
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

#include "Array3DEvent.h"

/**
 * \brief This class declares information about the extension.
 */
class Extension : public ExtensionBase
{
public:

    /**
     * Constructor of an extension declares everything the extension contains : Objects, actions, conditions and expressions.
     */
    Extension()
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
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::InitArrays")
                                 .SetIncludeFile("Array/ArrayTools.h");

        /// Value at an index

        AddAction("3D_SetValueAsNumber",
                       _("Set a value"),
                       _("Set a value as a number at a specific index."),
                       _("Do _PARAM4__PARAM5_ to the value of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_]"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("expression", _("X index"))
            .AddParameter("expression", _("Y index"), "", true)
            .AddParameter("expression", _("Z index"), "", true)
            .AddParameter("operator", _("Modification's sign"))
            .AddParameter("expression", _("Value"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::SetValueAsNumber")
                                 .SetManipulatedType("number")
                                 .SetAssociatedGetter("arr::vec::GetValueAsNumber")
                                 .SetIncludeFile("Array/Array3DTools.h");

        AddCondition("3D_TestValueAsNumber",
                       _("Value at an index"),
                       _("Test the value (as number) at a specific index."),
                       _("The value of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_] is _PARAM4__PARAM5_"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("expression", _("X index"))
            .AddParameter("expression", _("Y index"), "", true)
            .AddParameter("expression", _("Z index"), "", true)
            .AddParameter("relationalOperator", _("Comparison's sign"))
            .AddParameter("expression", _("Value"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::GetValueAsNumber")
                                 .SetManipulatedType("number")
                                 .SetIncludeFile("Array/Array3DTools.h");

        AddExpression("3D::At", _("Value at an index"), _("Value at an index"), _("3D Array"), "res/actions/rotate.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("expression", _("X index"))
            .AddParameter("expression", _("Y index"), "", true)
            .AddParameter("expression", _("Z index"), "", true)
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::GetValueAsNumber").SetIncludeFile("Array/Array3DTools.h");

        /// Text at an index

        AddAction("3D_SetValueAsText",
                       _("Set a text"),
                       _("Set a text at a specific index."),
                       _("Do _PARAM4__PARAM5_ to the text of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_]"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("expression", _("X index"))
            .AddParameter("expression", _("Y index"), "", true)
            .AddParameter("expression", _("Z index"), "", true)
            .AddParameter("operator", _("Modification's sign"))
            .AddParameter("string", _("Text"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::SetValueAsString")
                                 .SetManipulatedType("string")
                                 .SetAssociatedGetter("arr::vec::GetValueAsString")
                                 .SetIncludeFile("Array/Array3DTools.h");

        AddCondition("3D_TestValueAsText",
                       _("Text at an index"),
                       _("Test the text at a specific index."),
                       _("The text of _PARAM0_[_PARAM1_;_PARAM2_;_PARAM3_] is _PARAM4__PARAM5_"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("expression", _("X index"))
            .AddParameter("expression", _("Y index"), "", true)
            .AddParameter("expression", _("Z index"), "", true)
            .AddParameter("relationalOperator", _("Comparison's sign"))
            .AddParameter("string", _("Text"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::GetValueAsString")
                                 .SetManipulatedType("string")
                                 .SetIncludeFile("Array/Array3DTools.h");

        AddStrExpression("3D::At", _("Text at an index"), _("Text at an index"), _("3D Array"), "res/actions/rotate.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("expression", _("X index"))
            .AddParameter("expression", _("Y index"), "", true)
            .AddParameter("expression", _("Z index"), "", true)
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::GetValueAsString").SetIncludeFile("Array/Array3DTools.h");

        /// Insert a value (number or text)

        AddAction("3D_InsertValueAsNumber",
                       _("Insert a value"),
                       _("Insert a value (number) at a specific position."),
                       _("Insert _PARAM3_ at the index _PARAM2_ in the axis _PARAM1_ of _PARAM0_"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("string", _("Dimension (\"X\", \"Y\" or \"Z\")")).SetDefaultValue("\"X\"")
            .AddParameter("expression", _("Index in that axis"))
            .AddParameter("expression", _("Value"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::InsertValueAsNumber")
                                 .SetIncludeFile("Array/Array3DTools.h");

        AddAction("3D_InsertValueAsText",
                       _("Insert a text"),
                       _("Insert a text at a specific position."),
                       _("Insert _PARAM3_ at the index _PARAM2_ in the axis _PARAM1_ of _PARAM0_"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("string", _("Dimension (\"X\", \"Y\" or \"Z\")")).SetDefaultValue("\"X\"")
            .AddParameter("expression", _("Index in that axis"))
            .AddParameter("string", _("Text"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::InsertValueAsString")
                                 .SetIncludeFile("Array/Array3DTools.h");

        /// Remove a value

        AddAction("3D_RemoveValue",
                       _("Remove an index"),
                       _("Remove an index from the array."),
                       _("Remove the index _PARAM2_ in the axis _PARAM1_ of _PARAM0_"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("string", _("Dimension (\"X\", \"Y\" or \"Z\")")).SetDefaultValue("\"X\"")
            .AddParameter("expression", _("Index in that axis"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::RemoveValue")
                                 .SetIncludeFile("Array/Array3DTools.h");

        /// Set size

        AddAction("3D_SetSize",
                       _("Set size"),
                       _("Set the size of an array.\nThis action is needed to create the array, otherwise the array is empty (size of 0 on X, Y and Z)."),
                       _("Set the size of _PARAM0_ to _PARAM1_;_PARAM2_;_PARAM3_"),
                       _("3D Array"),
                       "CppPlatform/Extensions/AESicon24.png",
                       "CppPlatform/Extensions/AESicon16.png")

            .AddParameter("string", _("Array Name"))
            .AddParameter("expression", _("Width (size on X)"))
            .AddParameter("expression", _("Height (size on Y)"))
            .AddParameter("expression", _("Depth (size on Z)"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::SetSize")
                                 .SetIncludeFile("Array/Array3DTools.h");

        /// Get width, height, depth

        AddExpression("3D::Width", _("Width of an array"), _("Width of an array"), _("3D Array"), "res/actions/rotate.png")

            .AddParameter("string", _("Array Name"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::GetWidth").SetIncludeFile("Array/Array3DTools.h");

        AddExpression("3D::Height", _("Height of an array"), _("Height of an array"), _("3D Array"), "res/actions/rotate.png")

            .AddParameter("string", _("Array Name"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::GetHeight").SetIncludeFile("Array/Array3DTools.h");

        AddExpression("3D::Depth", _("Depth of an array"), _("Depth of an array"), _("3D Array"), "res/actions/rotate.png")

            .AddParameter("string", _("Array Name"))
            .AddCodeOnlyParameter("currentScene", "")

            .codeExtraInformation.SetFunctionName("arr::vec::GetDepth").SetIncludeFile("Array/Array3DTools.h");

        /// Iterate event

        {
            gd::EventMetadata::CodeGenerator * arr3DCodeGen = new arr::vec::Array3DEvent::CodeGenerator;

            AddEvent("Array3DIterate",
                    _("Iterate in a 3D Array"),
                    _("Execute the event for each values contained in a 3D Array. You can access the value and its index by using dedicated expressions"),
                    "",
                    "res/function.png",
                    boost::shared_ptr<gd::BaseEvent>(new arr::vec::Array3DEvent))
                        .SetCodeGenerator(boost::shared_ptr<gd::EventMetadata::CodeGenerator>(arr3DCodeGen));
        }

        {
            class CodeGenerator : public gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator
            {
                virtual std::string GenerateCode(const std::vector<gd::Expression> & parameters, gd::EventsCodeGenerator & codeGenerator, gd::EventsCodeGenerationContext & context)
                {
                    codeGenerator.AddIncludeFile("Array/ArrayValue.h");

                    std::string code = "arr_currentX";

                    return code;
                };
            };

            gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator * codeGenerator = new CodeGenerator; //Need for code to compile

            AddExpression("3D::CurrentX",
                           _("Current X position in array"),
                           _("Return the current X position in the array (when you use the \"iterate through 3D array\" event"),
                           _("3D Array"),
                           "res/function.png")
                .codeExtraInformation.SetCustomCodeGenerator(boost::shared_ptr<gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator>(codeGenerator));
        }

        {
            class CodeGenerator : public gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator
            {
                virtual std::string GenerateCode(const std::vector<gd::Expression> & parameters, gd::EventsCodeGenerator & codeGenerator, gd::EventsCodeGenerationContext & context)
                {
                    codeGenerator.AddIncludeFile("Array/ArrayValue.h");

                    std::string code = "arr_currentY";

                    return code;
                };
            };

            gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator * codeGenerator = new CodeGenerator; //Need for code to compile

            AddExpression("3D::CurrentY",
                           _("Current Y position in array"),
                           _("Return the current Y position in the array (when you use the \"iterate through 3D array\" event"),
                           _("3D Array"),
                           "res/function.png")
                .codeExtraInformation.SetCustomCodeGenerator(boost::shared_ptr<gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator>(codeGenerator));
        }

        {
            class CodeGenerator : public gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator
            {
                virtual std::string GenerateCode(const std::vector<gd::Expression> & parameters, gd::EventsCodeGenerator & codeGenerator, gd::EventsCodeGenerationContext & context)
                {
                    codeGenerator.AddIncludeFile("Array/ArrayValue.h");

                    std::string code = "arr_currentZ";

                    return code;
                };
            };

            gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator * codeGenerator = new CodeGenerator; //Need for code to compile

            AddExpression("3D::CurrentZ",
                           _("Current Z position in array"),
                           _("Return the current Z position in the array (when you use the \"iterate through 3D array\" event"),
                           _("3D Array"),
                           "res/function.png")
                .codeExtraInformation.SetCustomCodeGenerator(boost::shared_ptr<gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator>(codeGenerator));
        }

        {
            class CodeGenerator : public gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator
            {
                virtual std::string GenerateCode(const std::vector<gd::Expression> & parameters, gd::EventsCodeGenerator & codeGenerator, gd::EventsCodeGenerationContext & context)
                {
                    codeGenerator.AddIncludeFile("Array/ArrayValue.h");

                    std::string code = "arr_current.GetAsNumber()";

                    return code;
                };
            };

            gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator * codeGenerator = new CodeGenerator; //Need for code to compile

            AddExpression("3D::Current",
                           _("Current value in array"),
                           _("Return the current value as number in the array (when you use the \"iterate through 3D array\" event"),
                           _("3D Array"),
                           "res/function.png")
                .codeExtraInformation.SetCustomCodeGenerator(boost::shared_ptr<gd::ExpressionMetadata::ExtraInformation::CustomCodeGenerator>(codeGenerator));
        }

        {
            class CodeGenerator : public gd::StrExpressionMetadata::ExtraInformation::CustomCodeGenerator
            {
                virtual std::string GenerateCode(const std::vector<gd::Expression> & parameters, gd::EventsCodeGenerator & codeGenerator, gd::EventsCodeGenerationContext & context)
                {
                    codeGenerator.AddIncludeFile("Array/ArrayValue.h");

                    std::string code = "arr_current.GetAsText()";

                    return code;
                };
            };

            gd::StrExpressionMetadata::ExtraInformation::CustomCodeGenerator * codeGenerator = new CodeGenerator; //Need for code to compile

            AddStrExpression("3D::Current",
                           _("Current text in array"),
                           _("Return the current value as text in the array (when you use the \"iterate through 3D array\" event"),
                           _("3D Array"),
                           "res/function.png")
                .codeExtraInformation.SetCustomCodeGenerator(boost::shared_ptr<gd::StrExpressionMetadata::ExtraInformation::CustomCodeGenerator>(codeGenerator));
        }


        #endif

        GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
    };
    virtual ~Extension()
    {
        arr::ArrayManager::Kill();
    };
};

/**
 * Used by Game Develop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension() {
    return new Extension;
}

/**
 * Used by Game Develop to destroy the extension class
 * -- Do not need to be modified. --
 */
extern "C" void GD_EXTENSION_API DestroyGDExtension(ExtensionBase * p) {
    delete p;
}

