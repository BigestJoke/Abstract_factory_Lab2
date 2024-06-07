#include "Unit.h"

string Unit::generateShift(unsigned int level) const
{
    static const auto DEFAULT_SHIFT = " ";
    string result;
    for (unsigned int i = 0; i < level; ++i)
    {
        result += DEFAULT_SHIFT;
    }
    return result;
}
