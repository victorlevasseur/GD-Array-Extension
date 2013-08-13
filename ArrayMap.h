/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef ARRAYMAP_H
#define ARRAYMAP_H

#include <map>
#include <string>
#include "ArrayValue.h"

namespace arr
{

class ArrayMap
{

public:
    ArrayMap() {};
    ~ArrayMap() {};

    inline double GetValueAsNumber(const std::string &key)
    {
        return m_array[key].GetAsNumber();
    }

    inline std::string GetValueAsString(const std::string &key)
    {
        return m_array[key].GetAsText();
    }

    inline void SetValue(const std::string &key, double value)
    {
        m_array[key].Set(value);
    }

    inline void SetValue(const std::string &key, const std::string &value)
    {
        m_array[key].Set(value);
    }

    inline void RemoveKey(const std::string &key)
    {
        if(m_array.count(key) != 0)
            m_array.erase(key);
    }

private:
    std::map<std::string, Value> m_array;

};

}

#endif // ARRAYMAP_H
