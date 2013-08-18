/*
Copyright (c) 2013 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef ARRAYTOOLS_H_INCLUDED
#define ARRAYTOOLS_H_INCLUDED

#include <string>
#include <vector>
#include <map>

#include "GDCpp/RuntimeScene.h"
#include "GDCpp/Project.h"

#include "ArrayValue.h"
#include "Array3D.h"
#include "Dictionary.h"
#include "Array3DEventInfo.h"

typedef std::string ArrayNameType;

namespace arr
{
    void GD_EXTENSION_API InitArrays(RuntimeScene &scene);

    struct ArraysContainer
    {
        std::map<ArrayNameType, Array3D> m_3dArrays;
        std::map<ArrayNameType, Dictionary> m_dicArrays;
    };

    class GD_EXTENSION_API ArrayManager
    {
    private:

    ArrayManager ();
    ~ArrayManager () {};

    public:

    static ArrayManager *GetInstance()
    {
        if (NULL == _singleton)
        {
            _singleton =  new ArrayManager;
        }

        return _singleton;
    }

    static void Kill()
    {
        if (NULL != _singleton)
        {
            delete _singleton;
            _singleton = NULL;
        }
    }

    inline void ResetSceneArrays(Game *game)
    {
        #if defined(GD_IDE_ONLY)
        if(m_gameArrayContainer.count(game) == 0)
            return;

        m_gameArrayContainer[game].m_3dArrays.clear();
        m_gameArrayContainer[game].m_dicArrays.clear();
        m_array3dEventInfos[game] = threeDim::Array3DEventInfoManager();
        #endif
    }

    inline Array3D& GetArray3D(Game *game, const std::string &name)
    {
        return m_gameArrayContainer[game].m_3dArrays[name];
    }

    inline Dictionary& GetDictionary(Game *game, const std::string &name)
    {
        return m_gameArrayContainer[game].m_dicArrays[name];
    }

    inline threeDim::Array3DEventInfoManager& GetArray3DEventInfo(Game *game)
    {
        return m_array3dEventInfos[game];
    }

    private:
        static ArrayManager *_singleton;

        std::map<Game*, ArraysContainer> m_gameArrayContainer;

        std::map<Game*, threeDim::Array3DEventInfoManager> m_array3dEventInfos;
    };

}


#endif // ARRAYTOOLS_H_INCLUDED

