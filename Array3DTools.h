/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef VECTORTOOLS_H
#define VECTORTOOLS_H

#include <string>

#include <GDCpp/RuntimeScene.h>

namespace arr
{

namespace threeDim
{

double GD_EXTENSION_API GetValueAsNumber(const std::string &name, int d1, int d2, int d3, RuntimeScene &scene);
void GD_EXTENSION_API SetValueAsNumber(const std::string &name, int d1, int d2, int d3, double value, RuntimeScene &scene);

std::string GD_EXTENSION_API GetValueAsString(const std::string &name, int d1, int d2, int d3, RuntimeScene &scene);
void GD_EXTENSION_API SetValueAsString(const std::string &name, int d1, int d2, int d3, const std::string &text, RuntimeScene &scene);

void GD_EXTENSION_API InsertValueAsNumber(const std::string &name, const std::string &dim, int index, double value, RuntimeScene &scene);
void GD_EXTENSION_API InsertValueAsString(const std::string &name, const std::string &dim, int index, const std::string &text, RuntimeScene &scene);

void GD_EXTENSION_API RemoveValue(const std::string &name, const std::string &dim, int index, RuntimeScene &scene);

int GD_EXTENSION_API GetWidth(const std::string &name, RuntimeScene &scene);
int GD_EXTENSION_API GetHeight(const std::string &name, RuntimeScene &scene);
int GD_EXTENSION_API GetDepth(const std::string &name, RuntimeScene &scene);
void GD_EXTENSION_API SetSize(const std::string &name, int d1Size, int d2Size, int d3Size, RuntimeScene &scene);

}

}

#endif // VECTORTOOLS_H
