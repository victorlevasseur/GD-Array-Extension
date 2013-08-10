#ifndef ARRAYTOOLS_H_INCLUDED
#define ARRAYTOOLS_H_INCLUDED

#include <string>
#include <vector>
#include <map>

#include "GDCpp/RuntimeScene.h"
#include "GDCpp/Project.h"

#include "ArrayValue.h"
#include "Array3D.h"
#include "ArrayMap.h"
#include "Array3DEventInfo.h"

typedef std::string ArrayNameType;

namespace arr
{
    void GD_EXTENSION_API InitArrays(RuntimeScene &scene);

    struct ArraysContainer
    {
        std::map<ArrayNameType, Array3D> m_3dArrays;
        std::map<ArrayNameType, ArrayMap> m_mapArrays;
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
        m_gameArrayContainer[game].m_mapArrays.clear();
        m_array3dEventInfos[game] = vec::Array3DEventInfoManager();
        #endif
    }

    inline Array3D& GetArray3D(Game *game, const std::string &name)
    {
        return m_gameArrayContainer[game].m_3dArrays[name];
    }

    inline ArrayMap& GetArrayMap(Game *game, const std::string &name)
    {
        return m_gameArrayContainer[game].m_mapArrays[name];
    }

    inline vec::Array3DEventInfoManager& GetArray3DEventInfo(Game *game)
    {
        return m_array3dEventInfos[game];
    }

    private:
        static ArrayManager *_singleton;

        std::map<Game*, ArraysContainer> m_gameArrayContainer;
        std::map<Game*, vec::Array3DEventInfoManager> m_array3dEventInfos;
    };

}


#endif // ARRAYTOOLS_H_INCLUDED

