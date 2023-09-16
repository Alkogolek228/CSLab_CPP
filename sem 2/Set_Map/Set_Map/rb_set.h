#include "rb_map.h"

template <typename KeyType>
class rb_set : public rb_map<KeyType, char>
{
public:
    using rb_map<KeyType, char>::rb_map;
};
