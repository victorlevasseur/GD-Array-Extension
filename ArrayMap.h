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
