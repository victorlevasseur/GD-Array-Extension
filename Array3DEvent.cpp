#include "Array3DEvent.h"

#if defined(GD_IDE_ONLY)

#include "GDCore/Events/Serialization.h"
#include "GDCpp/RuntimeScene.h"
#include "GDCpp/CommonTools.h"
#include "GDCore/Events/EventsCodeGenerationContext.h"
#include "GDCore/Events/EventsCodeGenerator.h"
#include "GDCore/Events/EventsCodeNameMangler.h"
#include "GDCpp/XmlMacros.h"
#include "GDCpp/tinyxml/tinyxml.h"
#include "GDCore/IDE/EventsRenderingHelper.h"
#include "GDCore/IDE/EventsEditorItemsAreas.h"
#include "GDCore/IDE/EventsEditorSelection.h"

#include "Array3DEventEditor.h"

namespace gd { class Project; }

namespace arr
{

namespace vec
{

Array3DEvent::Array3DEvent() : gd::BaseEvent(), arrayName("")
{

}

Array3DEvent::Array3DEvent(const Array3DEvent &event) : gd::BaseEvent(event)
{
    Init(event);
}

Array3DEvent& Array3DEvent::operator=(const Array3DEvent & event)
{
    if(this != &event)
    {
        gd::BaseEvent::operator=(event);
        Init(event);
    }

    return *this;
}

std::vector < std::vector<gd::Instruction>* > Array3DEvent::GetAllConditionsVectors()
{
    std::vector < std::vector<gd::Instruction>* > allConditions;
    allConditions.push_back(&conditions);

    return allConditions;
}

std::vector < std::vector<gd::Instruction>* > Array3DEvent::GetAllActionsVectors()
{
    std::vector < std::vector<gd::Instruction>* > allActions;
    allActions.push_back(&conditions);

    return allActions;
}

void Array3DEvent::SaveToXml(TiXmlElement * elem) const
{
    TiXmlElement * conditionsElem = new TiXmlElement( "Conditions" );
    elem->LinkEndChild( conditionsElem );
    gd::EventsListSerialization::SaveConditions(conditions, conditionsElem);

    TiXmlElement * actionsElem = new TiXmlElement( "Actions" );
    elem->LinkEndChild( actionsElem );
    gd::EventsListSerialization::SaveActions(actions, actionsElem);

    if ( !GetSubEvents().empty() )
    {
        TiXmlElement * subeventsElem;
        subeventsElem = new TiXmlElement( "Events" );
        elem->LinkEndChild( subeventsElem );

        gd::EventsListSerialization::SaveEventsToXml(events, subeventsElem);
    }

    GD_CURRENT_ELEMENT_SAVE_ATTRIBUTE_STRING("name", GetArrayName());
}

void Array3DEvent::LoadFromXml(gd::Project & project, const TiXmlElement * elem)
{
    if ( elem->FirstChildElement( "Conditions" ) != NULL )
        gd::EventsListSerialization::OpenConditions(project, conditions, elem->FirstChildElement( "Conditions" ));
    else
        std::cout << "Aucune informations sur les conditions d'un évènement";

    if ( elem->FirstChildElement( "Actions" ) != NULL )
        gd::EventsListSerialization::OpenActions(project, actions, elem->FirstChildElement( "Actions" ));
    else
        std::cout << "Aucune informations sur les actions d'un évènement";

    if ( elem->FirstChildElement( "Events" ) != NULL )
        gd::EventsListSerialization::LoadEventsFromXml(project, events, elem->FirstChildElement( "Events" ));

    std::string arrayName_;
    GD_CURRENT_ELEMENT_LOAD_ATTRIBUTE_STRING("name", arrayName_);
    SetArrayName(arrayName_);
}

void Array3DEvent::Render(wxDC & dc, int x, int y, unsigned int width, gd::EventsEditorItemsAreas & areas, gd::EventsEditorSelection & selection, const gd::Platform & platform)
{
	gd::EventsRenderingHelper * renderingHelper = gd::EventsRenderingHelper::GetInstance();
    int border = renderingHelper->instructionsListBorder;
    const int functionTextHeight = 20;

    //Draw header rectangle
    wxRect headerRect(x, y, width, functionTextHeight);
    renderingHelper->DrawNiceRectangle(dc, headerRect);

    //Name
    dc.SetFont( renderingHelper->GetNiceFont().Bold()  );
    dc.SetTextForeground(wxColour(0,0,0));
    wxString caption = _("Iterate through ") + (GetArrayName() != "" ? GetArrayName() : _("(Not defined)")) + _(" on XYZ");
    dc.DrawText( caption, x + 4, y + 3 );

    //Draw conditions rectangle
    wxRect rect(x, y+functionTextHeight, renderingHelper->GetConditionsColumnWidth()+border, GetRenderedHeight(width, platform)-functionTextHeight);
    renderingHelper->DrawNiceRectangle(dc, rect);

    //Draw actions and conditions
    renderingHelper->DrawConditionsList(conditions, dc,
                                        x+border,
                                        y+functionTextHeight+border,
                                        renderingHelper->GetConditionsColumnWidth()-border, this, areas, selection, platform);
    renderingHelper->DrawActionsList(actions, dc,
                                     x+renderingHelper->GetConditionsColumnWidth()+border,
                                     y+functionTextHeight+border,
                                     width-renderingHelper->GetConditionsColumnWidth()-border*2, this, areas, selection, platform);
}

unsigned int Array3DEvent::GetRenderedHeight(unsigned int width, const gd::Platform & platform) const
{
    if ( eventHeightNeedUpdate )
    {
        gd::EventsRenderingHelper * renderingHelper = gd::EventsRenderingHelper::GetInstance();
        int border = renderingHelper->instructionsListBorder;
        const int functionTextHeight = 20;

        //Get maximum height needed
        int conditionsHeight = renderingHelper->GetRenderedConditionsListHeight(conditions, renderingHelper->GetConditionsColumnWidth()-border*2, platform);
        int actionsHeight = renderingHelper->GetRenderedActionsListHeight(actions, width-renderingHelper->GetConditionsColumnWidth()-border*2, platform);

        renderedHeight = (( conditionsHeight > actionsHeight ? conditionsHeight : actionsHeight ) + functionTextHeight)+border*2;
        eventHeightNeedUpdate = false;
    }

    return renderedHeight;
}

gd::BaseEvent::EditEventReturnType Array3DEvent::EditEvent(wxWindow* parent_, gd::Project & game_, gd::Layout & scene_, gd::MainFrameWrapper & mainFrameWrapper_)
{
    Array3DEventEditor dialog(parent_, *this, game_, scene_);
    if ( dialog.ShowModal() == 0 ) return Cancelled;

    return ChangesMade;
}

std::string Array3DEvent::GetArrayName() const
{
    return arrayName.GetPlainString();
}

void Array3DEvent::SetArrayName(const std::string &name)
{
    arrayName = gd::Expression(name);
}

void Array3DEvent::Init(const Array3DEvent & event)
{
    events = CloneVectorOfEvents(event.events);
    conditions = event.conditions;
    actions = event.actions;

    arrayName = event.arrayName;
}

}

}

#endif
