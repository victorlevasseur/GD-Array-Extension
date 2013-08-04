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
