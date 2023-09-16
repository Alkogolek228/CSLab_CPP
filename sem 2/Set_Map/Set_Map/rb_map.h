#include "rb_tree.h"

template<typename Key, typename T, typename Compare = std::less<Key>>
class rb_map
{
public:
    typedef std::pair<Key, T> value_type;
    typedef rb_tree<value_type> tree_type;
    typedef typename tree_type::iterator iterator;

private:
    tree_type rbTree;

public:
    // Constructors
    rb_map() {}

    template<typename Iterator_>
    rb_map(Iterator_ begin, Iterator_ end) : rbTree(begin, end) {}

    // Utility functions
    iterator begin()
    {
        return rbTree.begin();
    }

    iterator end()
    {
        return rbTree.end();
    }

    bool empty() const
    {
        return rbTree.empty();
    }

    size_t size() const
    {
        return rbTree.size;
    }

    iterator find(const Key& key)
    {
        value_type searchItem;
        searchItem.first = key;

        iterator it = rbTree.begin();
        while (it != rbTree.end())
        {
            if (Compare()(it->value.first, key))
            {
                ++it;
            }
            else if (Compare()(key, it->value.first))
            {
                break;
            }
            else
            {
                return it;
            }
        }

        return rbTree.end();
    }

    std::pair<iterator, bool> insert(const value_type& value)
    {
        iterator it = find(value.first);
        if (it != rbTree.end())
        {
            return std::make_pair(it, false); // Key already exists
        }

        iterator insertedIt = rbTree.insert(value);
        return std::make_pair(insertedIt, true);
    }

    void clear()
    {
        rbTree.clear();
    }

    // Overloading operators
    T& operator[](const Key& key)
    {
        iterator it = find(key);
        if (it != rbTree.end())
        {
            return it->value.second;
        }

        value_type newValue;
        newValue.first = key;
        it = rbTree.insert(newValue);
        return it->value.second;
    }

    std::string print()
    {
        return rbTree.print();
    }
};