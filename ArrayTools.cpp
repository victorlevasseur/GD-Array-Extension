

#include "ArrayTools.h"

namespace arr
{

    void GD_EXTENSION_API InitArrays(RuntimeScene &scene)
    {
        ArrayManager::getInstance()->ResetSceneArrays(&scene);
    }

    ArrayManager* ArrayManager::_singleton = 0;

    ArrayManager::ArrayManager()
    {

    }

}

