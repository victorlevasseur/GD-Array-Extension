/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

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
