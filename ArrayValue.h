/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef ARRAYVALUE_H
#define ARRAYVALUE_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

namespace arr
{

class Value
{
public:
    Value() : m_valueNbr(0), m_valueTxt(""), m_nbrDirty(false), m_txtDirty(false) {};
    Value(double val) : m_valueNbr(val), m_valueTxt(""), m_nbrDirty(false), m_txtDirty(true) {};
    Value(std::string val) : m_valueNbr(0), m_valueTxt(val), m_nbrDirty(true), m_txtDirty(false) {};

    ~Value() {};

    inline double GetAsNumber() const
    {
        if(m_nbrDirty)
        {
            m_valueNbr = atof(m_valueTxt.c_str());
            m_nbrDirty = false;
        }

        return m_valueNbr;
    };

    inline std::string GetAsText() const
    {
        if(m_txtDirty)
        {
            std::stringstream os;
            os << m_valueNbr;
            m_valueTxt = os.str();
            m_txtDirty = false;
        }

        return m_valueTxt;
    };

    inline void Set(double number)
    {
        m_txtDirty = true;
        m_valueNbr = number;
    };

    inline void Set(std::string text)
    {
        m_nbrDirty = true;
        m_valueTxt = text;
    };


private:
    mutable double m_valueNbr;
    mutable std::string m_valueTxt;

    mutable bool m_nbrDirty;
    mutable bool m_txtDirty;
};

}

#endif // ARRAYVALUE_H
