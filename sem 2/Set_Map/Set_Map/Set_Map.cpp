#include <iostream>
#include "rb_set.h"


int main() {

    rb_map<int, int> map;
    map.insert({1, 1});
    map.insert({ 2, 2 });
    map.insert({ 3, 3 });
    rb_set<int> set;
    set.insert({1,1});
    //std::cout << map.find(2);
}
