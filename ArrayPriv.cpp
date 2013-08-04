#include "ArrayPriv.h"

namespace arr
{
namespace priv
{

int GetDimFromAxisName(const std::string &axis)
{
    return (axis == "X" ? 1 : (axis == "Y" ? 2 : (axis == "Z" ? 3 : 0)));
}

}
}
