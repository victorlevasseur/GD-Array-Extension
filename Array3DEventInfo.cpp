#include "Array3DEventInfo.h"

namespace arr
{

namespace threeDim
{

Array3DEventInfoManager::Array3DEventInfoManager()
{

}

Array3DEventInfoManager::~Array3DEventInfoManager()
{

}

Array3DEventInfo& Array3DEventInfoManager::GetEventInfo()
{
    if(m_eventInfoStack.empty())
    {
        return m_badEventInfo;
    }
    else
    {
        return m_eventInfoStack.top();
    }
}

Array3DEventInfo& Array3DEventInfoManager::PushNewEventInfo(int currentX, int currentY, int currentZ, Value current)
{
    Array3DEventInfo info;
    info.currentX = currentX;
    info.currentY = currentY;
    info.currentZ = currentZ;
    info.current = current;

    m_eventInfoStack.push(info);

    return m_eventInfoStack.top();
}

void Array3DEventInfoManager::PopEventInfo()
{
    if(!m_eventInfoStack.empty())
        m_eventInfoStack.pop();
}

}

}
