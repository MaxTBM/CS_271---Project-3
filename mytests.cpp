#include <iostream>
#include <string>
#include "HashMap.cpp"
#include "customexceptions.hpp"

using namespace std;

int HashMap_sanity_check()
{
    int fail = 0;
    
    cout << "Testing HashMap class:" << endl;
    HashMap<int, int> map_int;
    HashMap<string, string> map_string;
    HashMap<double, double> map_double;

    // Test insert and operator=
    map_int.insert(1213, 10);
    map_int.insert(211, -20);
    map_int.insert(-12, 31);
    if (map_int[1213] != 10 || map_int[211] != -20 || map_int[-12] != 31)
    {
        fail += 1;
        cout << "Test 1 failed." << endl;
    }
    else
    {
        cout << "Test 1 passed." << endl;
    }

    map_string.insert("one", "aaaas");
    map_string.insert("two", "bbbbs");
    map_string.insert("three", "ccccs");
    if (map_string["one"] != "aaaas" || map_string["two"] != "bbbbs" || map_string["three"] != "ccccs")
    {
        fail += 1;
        cout << "Test 2 failed." << endl;
    }
    else
    {
        cout << "Test 2 passed." << endl;
    }

    map_double.insert(1.12, 652.2);
    map_double.insert(-34.1, -41.1);
    map_double.insert(112.11, 43.0);
    if (map_double[1.12] != 652.2 || map_double[-34.1] != -41.1 || map_double[112.11] != 43.0)
    {
        fail += 1;
        cout << "Test 3 failed." << endl;
    }
    else
    {
        cout << "Test 3 passed." << endl;
    }

    // Test insert overwrite
    map_int.insert(1213, 1210);
    if (map_int[1213] != 1210)
    {
        fail += 1;
        cout << "Test 4 failed." << endl;
    }
    else
    {
        cout << "Test 4 passed." << endl;
    }

    // Test operator[] exception
    try
    {
        int a = map_int[9999];
        fail += 1;
        cout << "Test 5 failed." << endl;
    }
    catch (const KeyNotFoundException &e)
    {
        cout << "Test 5 passed." << endl;
    }
    catch (...)
    {
        fail += 1;
        cout << "Test 5 failed." << endl;
    }

    // Test copy constructor
    HashMap<int, int> map_copy(map_int);
    if (map_copy[1213] != 1210 || map_copy[211] != -20 || map_copy[-12] != 31)
    {
        fail += 1;
        cout << "Test 6 failed." << endl;
    }
    else
    {
        cout << "Test 6 passed." << endl;
    }

    // Test assignment operator
    HashMap<int, int> map_assign;
    map_assign = map_int;
    if (map_assign[1213] != 1210 || map_assign[211] != -20 || map_assign[-12] != 31)
    {
        fail += 1;
        cout << "Test 7 failed." << endl;
    }
    else
    {
        cout << "Test 7 passed." << endl;
    }

    // Test search()
    auto result = map_int.search(1213);
    if (result == nullptr || result->second != 1210) {
        fail += 1;
        cout << "Test 8 failed." << endl;
    }
    else
    {
        cout << "Test 8 passed." << endl;
    }

    auto result_2 = map_int.search(9999);
    if (result_2 != nullptr) {
        fail += 1;
        cout << "Test 9 failed." << endl;
    }
    else
    {
        cout << "Test 9 passed." << endl;
    }

    // Test remove
    auto to_remove = map_int.search(1213);
    map_int.remove(to_remove);
    if (map_int.search(1213) != nullptr) {
        fail += 1;
        cout << "Test 10 failed." << endl;
    }
    else
    {
        cout << "Test 10 passed." << endl;
    }

    pair<int, int> to_remove_2(9999, 22222);
    pair<int, int>* to_remove_2_ptr = &to_remove_2;
    try {
        map_int.remove(to_remove_2_ptr);
        fail += 1;
        cout << "Test 11 failed." << endl;
    } catch (const KeyNotFoundException &e) {
        cout << "Test 11 passed." << endl;
    } catch (...) {
        fail += 1;
        cout << "Test 11 failed." << endl;
    }


    return fail;
}

int main()
{
    int hashmap_test = HashMap_sanity_check();
    cout << "-> "<< hashmap_test << " tests failed." << endl;
    cout << "-> "<< 11 - hashmap_test << " tests passed." << endl;
};
