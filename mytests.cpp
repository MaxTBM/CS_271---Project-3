#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include "HashMap.hpp"
#include "HashMap.cpp"
#include "customexceptions.hpp"

int main()
{
    // Test 1: Inserting and Removing elements
    HashMap<int, string> map;

    // Insert some key-value pairs
    map.insert(1, "Apple");
    map.insert(2, "Banana");
    map.insert(3, "Cherry");

    // Remove key 2
    pair<int, string>* result = map.search(2);
    if (result != nullptr)
    {
        map.remove(result);  // Try to remove the pair
        cout << "Key-value pair with key 2 removed successfully" << endl;
    }
    else
    {
        cout << "Key 2 not found, nothing to remove" << endl;
    }

    // After removal, try to search for the removed key (should be nullptr)
    result = map.search(2);
    if (result == nullptr)
    {
        cout << "Key 2 successfully removed" << endl;
    }

    return 0;
}
