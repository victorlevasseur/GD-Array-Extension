#ifndef ARRAY3DEVENTINFO_H
#define ARRAY3DEVENTINFO_H

#include <stack>
#include <deque>

#include "ArrayValue.h"

namespace arr
{

namespace threeDim
{

struct GD_EXTENSION_API Array3DEventInfo
{
    Array3DEventInfo() : currentX(0), currentY(0), currentZ(0), current() {};

    int currentX;
    int currentY;
    int currentZ;

    Value current;
};

class GD_EXTENSION_API Array3DEventInfoManager
{

public:
    Array3DEventInfoManager();
    ~Array3DEventInfoManager();

    Array3DEventInfo& GetEventInfo();
    Array3DEventInfo& PushNewEventInfo(int currentX, int currentY, int currentZ, Value current);
    void PopEventInfo();

private:
    std::stack<Array3DEventInfo> m_eventInfoStack;
    Array3DEventInfo m_badEventInfo;
};

}

}

#endif // ARRAY3DEVENTINFO_H
