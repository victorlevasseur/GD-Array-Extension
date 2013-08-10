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
