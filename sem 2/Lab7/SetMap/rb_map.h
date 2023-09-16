template <typename KeyType, typename ValueType>
class rb_map : public rb_tree<std::pair<const KeyType, ValueType>>
{
public:
    typedef typename rb_tree<std::pair<const KeyType, ValueType>>::value_type value_type;

    using rb_tree<std::pair<const KeyType, ValueType>>::rb_tree;

    // Insert key-value pair into the map
    iterator insert(const KeyType& key, const ValueType& value)
    {
        return rb_tree<std::pair<const KeyType, ValueType>>::insert(std::make_pair(key, value));
    }

    // Find the value associated with the given key
    ValueType& find(const KeyType& key)
    {
        iterator it = rb_tree<std::pair<const KeyType, ValueType>>::find(std::make_pair(key, ValueType()));
        if (it != end())
            return (*it).second;
        else
            throw std::out_of_range("Key not found in the map.");
    }

    // Check if the map contains the given key
    bool contains(const KeyType& key)
    {
        return rb_tree<std::pair<const KeyType, ValueType>>::find(std::make_pair(key, ValueType())) != end();
    }
};

template <typename KeyType>
class rb_set : public rb_map<KeyType, char>
{
public:
    using rb_map<KeyType, char>::rb_map;
};
