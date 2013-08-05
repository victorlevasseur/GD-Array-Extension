#include "Array3DTools.h"

#include "ArrayTools.h"
#include "Array3D.h"
#include "ArrayPriv.h"

namespace arr
{

namespace vec
{

double GetValueAsNumber(const std::string &name, int d1, int d2, int d3, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    return vecArray.GetValueAsNumber(d1, d2, d3);
}

void SetValueAsNumber(const std::string &name, int d1, int d2, int d3, double value, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    vecArray.SetValue(value, d1, d2, d3);
}

std::string GD_EXTENSION_API GetValueAsString(const std::string &name, int d1, int d2, int d3, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    return vecArray.GetValueAsText(d1, d2, d3);
}

void GD_EXTENSION_API SetValueAsString(const std::string &name, int d1, int d2, int d3, const std::string &text, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    vecArray.SetValue(text, d1, d2, d3);
}

void GD_EXTENSION_API InsertValueAsNumber(const std::string &name, const std::string &dim, int index, double value, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    Value val(value);
    vecArray.Insert(priv::GetDimFromAxisName(dim), index, val);
}

void GD_EXTENSION_API InsertValueAsString(const std::string &name, const std::string &dim, int index, const std::string &text, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    Value val(text);
    vecArray.Insert(priv::GetDimFromAxisName(dim), index, val);
}

void GD_EXTENSION_API RemoveValue(const std::string &name, const std::string &dim, int index, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    vecArray.Remove(priv::GetDimFromAxisName(dim), index);
}

int GD_EXTENSION_API GetWidth(const std::string &name, RuntimeScene &scene)
{
    return ArrayManager::getInstance()->GetArray3D(scene.game, name).GetSize(1);
}

int GD_EXTENSION_API GetHeight(const std::string &name, RuntimeScene &scene)
{
    return ArrayManager::getInstance()->GetArray3D(scene.game, name).GetSize(2);
}

int GD_EXTENSION_API GetDepth(const std::string &name, RuntimeScene &scene)
{
    return ArrayManager::getInstance()->GetArray3D(scene.game, name).GetSize(3);
}

void GD_EXTENSION_API SetSize(const std::string &name, int d1Size, int d2Size, int d3Size, RuntimeScene &scene)
{
    Array3D &vecArray = ArrayManager::getInstance()->GetArray3D(scene.game, name);

    vecArray.Resize(d1Size, d2Size, d3Size);
}


}

}

