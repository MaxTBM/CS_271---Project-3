#include <iostream>
#include <string>
#include "HashMap.cpp"
#include "customexceptions.hpp"

using namespace std;

int main()
{   
    HashMap<int, int> map;
    map.insert(1, 122);
    try {
        cout << map[99];
    } catch (const KeyNotFoundException& e) {
        cout << e.what() << endl;
    }
};
