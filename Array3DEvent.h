#ifndef ARRAY3DEVENT_H
#define ARRAY3DEVENT_H

#if defined(GD_IDE_ONLY)

#include "GDCore/Events/Event.h"
#include "GDCore/Events/EventMetadata.h"
#include "GDCpp/CommonTools.h"
#include "GDCore/Events/ExpressionsCodeGeneration.h"
#include "GDCore/Events/EventsCodeGenerationContext.h"
#include "GDCore/Events/EventsCodeGenerator.h"
#include "GDCore/Events/Instruction.h"

class RuntimeScene;
namespace gd { class Instruction; }
class TiXmlElement;
class EventsEditorItemsAreas;
class EventsEditorSelection;
namespace gd { class Layout; }
namespace gd { class MainFrameWrapper; }
class wxWindow;

namespace arr
{

namespace vec
{

class GD_EXTENSION_API Array3DEvent : public gd::BaseEvent
{
public:
    Array3DEvent();
    Array3DEvent(const Array3DEvent &event);
    virtual ~Array3DEvent() {};

    Array3DEvent& operator=(const Array3DEvent & event);
    virtual gd::BaseEventSPtr Clone() const {return boost::shared_ptr<gd::BaseEvent>(new Array3DEvent(*this));}

    virtual bool IsExecutable() const {return true;}
    virtual bool CanHaveSubEvents() const {return true;}

    virtual const std::vector < gd::BaseEventSPtr > & GetSubEvents() const {return events;};
    virtual std::vector < gd::BaseEventSPtr > & GetSubEvents() {return events;};
    void SetSubEvents(std::vector < gd::BaseEventSPtr > & subEvents_) {events = subEvents_;};

    const std::vector < gd::Instruction > & GetConditions() const { return conditions; };
    std::vector < gd::Instruction > & GetConditions() { return conditions; };
    void SetConditions(std::vector < gd::Instruction > & conditions_) { conditions = conditions_; };

    const std::vector < gd::Instruction > & GetActions() const { return actions; };
    std::vector < gd::Instruction > & GetActions() { return actions; };
    void SetActions(std::vector < gd::Instruction > & actions_) { actions = actions_; };

    virtual std::vector < std::vector<gd::Instruction>* > GetAllConditionsVectors();
    virtual std::vector < std::vector<gd::Instruction>* > GetAllActionsVectors();

    virtual void SaveToXml(TiXmlElement * eventElem) const;
    virtual void LoadFromXml(gd::Project & project, const TiXmlElement * eventElem);

    virtual void Render(wxDC & dc, int x, int y, unsigned int width, gd::EventsEditorItemsAreas & areas, gd::EventsEditorSelection & selection, const gd::Platform & platform);

    virtual unsigned int GetRenderedHeight(unsigned int width, const gd::Platform & platform) const;

    virtual EditEventReturnType EditEvent(wxWindow* parent_, gd::Project & game_, gd::Layout & scene_, gd::MainFrameWrapper & mainFrameWrapper_);


    std::string GetArrayName() const;
    void SetArrayName(const std::string &name);

private:
    void Init(const Array3DEvent & event);

    gd::Expression arrayName;

    std::vector < gd::Instruction > conditions;
    std::vector < gd::Instruction > actions;
    std::vector < gd::BaseEventSPtr > events;

public:

    class CodeGenerator : public gd::EventMetadata::CodeGenerator
    {
        virtual std::string Generate(gd::BaseEvent & event_, gd::EventsCodeGenerator & codeGenerator, gd::EventsCodeGenerationContext &context)
        {
            arr::vec::Array3DEvent &event = dynamic_cast<arr::vec::Array3DEvent&>(event_);

            // Adding needed includes
            codeGenerator.AddIncludeFile("stack");
            codeGenerator.AddIncludeFile("Array/ArrayValue.h");
            codeGenerator.AddIncludeFile("Array/Array3D.h");
            codeGenerator.AddIncludeFile("Array/ArrayTools.h");

            //Adding the main code of the event
            std::string code("// 3D-Array Iterate Event\n");

            std::string arrayNameExpr;
            gd::CallbacksForGeneratingExpressionCode callbacks(arrayNameExpr, codeGenerator, context);
            gd::ExpressionParser parser(event.GetArrayName());
            parser.ParseStringExpression(codeGenerator.GetPlatform(), codeGenerator.GetProject(), codeGenerator.GetLayout(), callbacks);
            if (arrayNameExpr.empty()) arrayNameExpr = "\"\""; //If generation failed, we make sure output code is not empty.

            code += "arr::Array3D &currentArray = arr::ArrayManager::getInstance()->GetArray3D(runtimeContext->scene->game, " + arrayNameExpr + ");\n";
            code += "int arr_currentX;\n";
            code += "int arr_currentY;\n";
            code += "int arr_currentZ;\n";
            code += "arr::Value arr_current;\n";
            code += "for(unsigned int x = 0; x < currentArray.GetSize(1); x++)\n";
            code += "{\n";
            {
                code += "arr_currentX = x;\n";
                code += "for(unsigned int y = 0; y < currentArray.GetSize(2); y++)\n";
                code += "{\n";
                {
                    code += "arr_currentY = y;\n";
                    code += "for(unsigned int z = 0; z < currentArray.GetSize(3); z++)\n";
                    code += "{\n";
                    {
                        code += "arr_currentZ = z;\n";
                        code += "arr_current = currentArray.GetValue(x, y, z);";

                        // Generating condition/action/sub-event //
                        code += codeGenerator.GenerateConditionsListCode(event.GetConditions(), context);

                        std::string ifPredicat;
                        for (unsigned int i = 0;i<event.GetConditions().size();++i)
                        {
                            if (i!=0)
                                ifPredicat += " && ";
                            ifPredicat += "condition"+ToString(i)+"IsTrue";
                        }

                        if ( !ifPredicat.empty() ) code += "if (" +ifPredicat+ ")\n";

                        code += "{\n";
                        code += codeGenerator.GenerateActionsListCode(event.GetActions(), context);

                        if ( event.HasSubEvents() )
                        {
                            code += "\n{\n";
                            code += codeGenerator.GenerateEventsListCode(event.GetSubEvents(), context);
                            code += "}\n";
                        }

                        code += "}\n";
                        ///////////////////////////////////////////
                    }
                    code += "}\n";
                }
                code += "}\n";
            }
            code += "}\n";


            return code;
        }
    };
};

}

}

#endif

#endif // ARRAY3DEVENT_H
