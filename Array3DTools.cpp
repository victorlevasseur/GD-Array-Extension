/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#include "Array3DTools.h"

#include "ArrayTools.h"
#include "Array3D.h"
#include "ArrayPriv.h"

namespace arr
{

namespace threeDim
{

double GetValueAsNumber(const std::string &name, int d1, int d2, int d3, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    return vecArray.GetValueAsNumber(d1, d2, d3);
}

void SetValueAsNumber(const std::string &name, int d1, int d2, int d3, double value, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    vecArray.SetValue(value, d1, d2, d3);
}

std::string GD_EXTENSION_API GetValueAsString(const std::string &name, int d1, int d2, int d3, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    return vecArray.GetValueAsText(d1, d2, d3);
}

void GD_EXTENSION_API SetValueAsString(const std::string &name, int d1, int d2, int d3, const std::string &text, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    vecArray.SetValue(text, d1, d2, d3);
}

void GD_EXTENSION_API InsertValueAsNumber(const std::string &name, const std::string &dim, int index, double value, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    Value val(value);
    vecArray.Insert(priv::GetDimFromAxisName(dim), index, val);
}

void GD_EXTENSION_API InsertValueAsString(const std::string &name, const std::string &dim, int index, const std::string &text, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    Value val(text);
    vecArray.Insert(priv::GetDimFromAxisName(dim), index, val);
}

void GD_EXTENSION_API RemoveValue(const std::string &name, const std::string &dim, int index, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    vecArray.Remove(priv::GetDimFromAxisName(dim), index);
}

void GD_EXTENSION_API Clear(const std::string &name, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    vecArray.Clear();
}

int GD_EXTENSION_API GetWidth(const std::string &name, RuntimeScene &scene)
{
    return ArrayManager::GetInstance()->GetArray3D(scene.game, name).GetSize(1);
}

int GD_EXTENSION_API GetHeight(const std::string &name, RuntimeScene &scene)
{
    return ArrayManager::GetInstance()->GetArray3D(scene.game, name).GetSize(2);
}

int GD_EXTENSION_API GetDepth(const std::string &name, RuntimeScene &scene)
{
    return ArrayManager::GetInstance()->GetArray3D(scene.game, name).GetSize(3);
}

void GD_EXTENSION_API SetSize(const std::string &name, int d1Size, int d2Size, int d3Size, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::GetInstance()->GetArray3D(scene.game, name);

    vecArray.Resize(d1Size, d2Size, d3Size);
}

int GD_EXTENSION_API GetCurrentX(RuntimeScene &scene)
{
    return arr::ArrayManager::GetInstance()->GetArray3DEventInfo(scene.game).GetEventInfo().currentX;
}

int GD_EXTENSION_API GetCurrentY(RuntimeScene &scene)
{
    return arr::ArrayManager::GetInstance()->GetArray3DEventInfo(scene.game).GetEventInfo().currentY;
}

int GD_EXTENSION_API GetCurrentZ(RuntimeScene &scene)
{
    return arr::ArrayManager::GetInstance()->GetArray3DEventInfo(scene.game).GetEventInfo().currentZ;
}

double GD_EXTENSION_API GetCurrentAsNumber(RuntimeScene &scene)
{
    return arr::ArrayManager::GetInstance()->GetArray3DEventInfo(scene.game).GetEventInfo().current.GetAsNumber();
}

std::string GD_EXTENSION_API GetCurrentAsString(RuntimeScene &scene)
{
    return arr::ArrayManager::GetInstance()->GetArray3DEventInfo(scene.game).GetEventInfo().current.GetAsText();
}


}

}

