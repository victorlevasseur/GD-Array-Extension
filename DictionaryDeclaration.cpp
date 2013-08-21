#include "Extension.h"
#include "JsExtension.h"

#include "ArrayTools.h"

void Extension::DeclareDictionary()
{
    #if defined(GD_IDE_ONLY)

    AddAction("Dic_SetValueAsNumber",
              _("Set a value"),
              _("Set a value as a number in a dictionary."),
              _("Do _PARAM2__PARAM3_ to the value of the key _PARAM1_ of _PARAM0_"),
              _("Dictionary"),
              "res/array24.png",
              "res/array.png")

        .AddParameter("string", _("Dictionary Name"))
        .AddParameter("string", _("Key"))
        .AddParameter("operator", _("Modification's sign"))
        .AddParameter("expression", _("Value"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::dic::SetValueAsNumber")
                             .SetManipulatedType("number")
                             .SetAssociatedGetter("arr::dic::GetValueAsNumber")
                             .SetIncludeFile("Array/DictionaryTools.h");

    AddCondition("Dic_TestValueAsNumber",
                 _("Value of a key"),
                 _("Test the value (as number) of a specific key in a dictionary."),
                 _("The value of the key _PARAM1_ of _PARAM0_ is _PARAM2__PARAM3_"),
                 _("Dictionary"),
                 "res/array24.png",
                 "res/array.png")

        .AddParameter("string", _("Dictionary Name"))
        .AddParameter("string", _("Key"))
        .AddParameter("relationalOperator", _("Comparison's sign"))
        .AddParameter("expression", _("Value"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::dic::GetValueAsNumber")
                             .SetManipulatedType("number")
                             .SetIncludeFile("Array/DictionaryTools.h");

    AddExpression("Dic::Get", _("Value of a key"), _("Value of a key"), _("Dictionary"), "res/actions/rotate.png")

        .AddParameter("string", _("Dictionary Name"))
        .AddParameter("string", _("Key"))
        .AddCodeOnlyParameter("currentScene", "")

        .codeExtraInformation.SetFunctionName("arr::dic::GetValueAsNumber")
                             .SetIncludeFile("Array/DictionaryTools.h");

    #endif
}

#if defined(GD_IDE_ONLY)

void JsExtension::DeclareDictionary()
{

}

#endif
