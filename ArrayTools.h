#ifndef ARRAYTOOLS_H_INCLUDED
#define ARRAYTOOLS_H_INCLUDED

#include <string>
#include <vector>
#include <map>

#include <GDCpp/RuntimeScene.h>

#include "ArrayValue.h"
#include "Array3D.h"
#include "ArrayMap.h"

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

    static ArrayManager *getInstance ()
    {
        if (NULL == _singleton)
        {
            _singleton =  new ArrayManager;
        }

        return _singleton;
    }

    static void kill ()
    {
        if (NULL != _singleton)
        {
            delete _singleton;
            _singleton = NULL;
        }
    }

    inline void ResetSceneArrays(RuntimeScene *scene)
    {
        if(m_sceneContainer.count(scene) == 0)
            return;

        m_sceneContainer[scene].m_3dArrays.clear();
        m_sceneContainer[scene].m_mapArrays.clear();
    }

    inline Array3D& GetArray3D(RuntimeScene *scene, const std::string &name)
    {
        return m_sceneContainer[scene].m_3dArrays[name];
    }

    inline ArrayMap& GetArrayMap(RuntimeScene *scene, const std::string &name)
    {
        return m_sceneContainer[scene].m_mapArrays[name];
    }

    private:
        static ArrayManager *_singleton;

        std::map<RuntimeScene*, ArraysContainer> m_sceneContainer;
    };

}


#endif // ARRAYTOOLS_H_INCLUDED

