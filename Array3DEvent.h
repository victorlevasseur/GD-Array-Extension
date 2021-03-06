/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

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

namespace threeDim
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
        virtual std::string Generate(gd::BaseEvent & event_, gd::EventsCodeGenerator & codeGenerator, gd::EventsCodeGenerationContext &context);
    };
};

}

}

#endif

#endif // ARRAY3DEVENT_H
