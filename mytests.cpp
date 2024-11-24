#include <iostream>
#include <string>
#include "HashMap.hpp"
#include "customexceptions.hpp"

using namespace std;

int main1() {
    // Create a HashMap of string keys and integer values
    HashMap<string, int> map;

    // Insert some key-value pairs
    map.insert("apple", 5);
    map.insert("banana", 10);
    map.insert("orange", 7);

    // Test the [] operator (should retrieve values)
    cout << "apple: " << map["apple"] << endl;    // Expected: 5
    cout << "banana: " << map["banana"] << endl;  // Expected: 10
    cout << "orange: " << map["orange"] << endl;  // Expected: 7

    // Test inserting a new value with an existing key (should overwrite)
    map.insert("apple", 15);
    cout << "apple after overwrite: " << map["apple"] << endl; // Expected: 15

    // Test search() function (should return pointer to pair)
    pair<string, int>* result = map.search("banana");
    if (result) {
        cout << "Found banana: " << result->first << " -> " << result->second << endl; // Expected: banana -> 10
    } else {
        cout << "banana not found" << endl;
    }

    // Test remove() function
    result = map.search("orange");
    if (result) {
        map.remove(result);
        cout << "Removed orange" << endl;
    }
    
    // Test if "orange" was successfully removed
    result = map.search("orange");
    if (!result) {
        cout << "orange not found after removal" << endl; // Expected: orange not found after removal
    }

    // Test exception for non-existent key
    try {
        cout << "grape: " << map["grape"] << endl; // Should throw KeyNotFoundException
    } catch (const KeyNotFoundException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}

int main()
{
    HashMap<int, int> map;
    map.insert(1,1);
};
