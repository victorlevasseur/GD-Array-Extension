#ifndef Array3D_H
#define Array3D_H

#include <deque>

#include "ArrayValue.h"

#define DO_NOT_RESIZE -1
#define ALL_DIMS 0

namespace arr
{

class Array3D
{
    typedef std::deque< std::deque< std::deque< Value > > > Array3D3Type;
    typedef std::deque< std::deque< Value > > Array3D2Type;
    typedef std::deque< Value > Array3D1Type;


    typedef std::deque< std::deque< std::deque< Value > > >::iterator IteratorDim1;
    typedef std::deque< std::deque< Value > >::iterator IteratorDim2;
    typedef std::deque< Value >::iterator IteratorDim3;

public:
    Array3D()
    {
        m_dimSize[0] = m_dimSize[1] = m_dimSize[2] = 0;
    };

    ~Array3D() {};

    inline Value& GetValue(int d1, int d2 = 0, int d3 = 0)
    {
        static Value badValue;

        if(IsIndexIn(d1, d2, d3))
        {
            return m_array[d1][d2][d3];
        }
        else
        {
            return badValue;
        }
    }

    inline double GetValueAsNumber(int d1, int d2 = 0, int d3 = 0)
    {
        if(IsIndexIn(d1, d2, d3))
        {
            return m_array[d1][d2][d3].GetAsNumber();
        }
        else
        {
            return 0;
        }
    };

    inline std::string GetValueAsText(int d1, int d2 = 0, int d3 = 0)
    {
        if(IsIndexIn(d1, d2, d3))
        {
            return m_array[d1][d2][d3].GetAsText();
        }
        else
        {
            return "";
        }
    };

    inline void SetValue(double value, int d1, int d2 = 0, int d3 = 0)
    {
        if(IsIndexIn(d1, d2, d3))
        {
            return m_array[d1][d2][d3].Set(value);
        }
    };

    inline void SetValue(const std::string &text, int d1, int d2 = 0, int d3 = 0)
    {
        if(IsIndexIn(d1, d2, d3))
        {
            return m_array[d1][d2][d3].Set(text);
        }
    };

    inline void Resize(int d1Size = DO_NOT_RESIZE, int d2Size = DO_NOT_RESIZE, int d3Size = DO_NOT_RESIZE)
    {
        int newD1Size = (d1Size == DO_NOT_RESIZE ? m_dimSize[0] : d1Size );
        int newD2Size = (d2Size == DO_NOT_RESIZE ? m_dimSize[1] : d2Size );
        int newD3Size = (d3Size == DO_NOT_RESIZE ? m_dimSize[2] : d3Size );

        m_dimSize[0] = newD1Size;
        m_dimSize[1] = newD2Size;
        m_dimSize[2] = newD3Size;

        m_array.resize(newD1Size);
        for(IteratorDim1 it = m_array.begin(); it != m_array.end(); it++)
        {
            it->resize(newD2Size);
            for(IteratorDim2 it2 = it->begin(); it2 != it->end(); it2++)
            {
                it2->resize(newD3Size);
            }
        }
    };

    inline unsigned int GetSize(int dim = ALL_DIMS) const
    {
        if(dim == ALL_DIMS)
        {
            return m_dimSize[0] * m_dimSize[1] * m_dimSize[2];
        }
        else
        {
            return m_dimSize[dim - 1];
        }
    }

    inline bool IsIndexIn(int d1, int d2 = 0, int d3 = 0)
    {
        return (m_dimSize[0] > d1 && m_dimSize[1] > d2 && m_dimSize[2] > d3);
    }

    inline void Insert(int dim, int index, Value &defaultValue)
    {
        if(dim == 1)
        {
            if(!IsIndexIn(index - 1, 0, 0))
                return;

            IteratorDim1 indexIt = m_array.begin();
            indexIt += index;

            m_array.insert(indexIt, Array3D2Type(m_dimSize[1], Array3D1Type(m_dimSize[2], defaultValue)));
            m_dimSize[0]++;
        }
        else if(dim == 2)
        {
            if(!IsIndexIn(0, index - 1, 0))
                return;

            for(IteratorDim1 it = m_array.begin(); it != m_array.end(); it++)
            {
                IteratorDim2 indexIt = it->begin();
                indexIt += index;

                it->insert(indexIt, Array3D1Type(m_dimSize[2], defaultValue));
            }

            m_dimSize[1]++;
        }
        else if(dim == 3)
        {
            if(!IsIndexIn(0, 0, index - 1))
                return;

            for(IteratorDim1 it = m_array.begin(); it != m_array.end(); it++)
            {
                for(IteratorDim2 it2 = it->begin(); it2 != it->end(); it2++)
                {
                    IteratorDim3 indexIt = it2->begin();
                    indexIt += index;

                    it2->insert(indexIt, defaultValue);
                }
            }

            m_dimSize[2]++;
        }
    }

    inline void Remove(int dim, int index)
    {
        if(index >= m_dimSize[dim - 1])
            return;

        if(dim == 1)
        {
            IteratorDim1 indexIt = m_array.begin();
            indexIt += index;

            m_array.erase(indexIt);

            m_dimSize[0]--;
        }
        else if(dim == 2)
        {
            for(IteratorDim1 it = m_array.begin(); it != m_array.end(); it++)
            {
                IteratorDim2 indexIt = it->begin();
                indexIt += index;

                it->erase(indexIt);
            }

            m_dimSize[1]--;
        }
        else if(dim == 3)
        {
            for(IteratorDim1 it = m_array.begin(); it != m_array.end(); it++)
            {
                for(IteratorDim2 it2 = it->begin(); it2 != it->end(); it2++)
                {
                    IteratorDim3 indexIt = it2->begin();
                    indexIt += index;

                    it2->erase(indexIt);
                }
            }

            m_dimSize[2]--;
        }
    }

    ///Extent the array if the index is not in it.
    inline void ExtentIfNecessary(int d1, int d2, int d3)
    {
        int newD1Size(GetSize(1)), newD2Size(GetSize(2)), newD3Size(GetSize(3));

        if(d1 >= GetSize(1))
        {
            newD1Size = d1 + 1;
        }
        if(d2 >= GetSize(2))
        {
            newD2Size = d2 + 1;
        }
        if(d3 >= GetSize(3))
        {
            newD3Size = d3 + 1;
        }

        Resize(newD1Size, newD2Size, newD3Size);
    }

private:
    Array3D3Type m_array;

    int m_dimSize[3];
};

}

#endif // Array3D_H
