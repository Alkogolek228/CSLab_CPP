#ifndef RB_SET_H
#define RB_SET_H

#include <iostream>
#include <utility>
#include "rb_map.h"
#include "rb_tree.h"

template <typename KeyType>
class Set : public Map<KeyType, char>
{
public:
    using Map<KeyType, char>::Map;
};


#endif // RB_SET_H
