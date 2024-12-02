#include <iostream>
#include <string>
#include "HashMap.cpp"
#include "HashMapTree.cpp"
#include "Set.cpp"
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
        fail++;
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
        fail++;
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
        fail++;
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
        fail++;
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
        fail++;
        cout << "Test 5 failed." << endl;
    }
    catch (const key_not_found_exception &e)
    {
        cout << "Test 5 passed." << endl;
    }
    catch (...)
    {
        fail++;
        cout << "Test 5 failed." << endl;
    }

    // Test copy constructor
    HashMap<int, int> map_copy(map_int);
    if (map_copy[1213] != 1210 || map_copy[211] != -20 || map_copy[-12] != 31)
    {
        fail++;
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
        fail++;
        cout << "Test 7 failed." << endl;
    }
    else
    {
        cout << "Test 7 passed." << endl;
    }

    // Test search()
    auto result = map_int.search(1213);
    if (result == nullptr || result->second != 1210) {
        fail++;
        cout << "Test 8 failed." << endl;
    }
    else
    {
        cout << "Test 8 passed." << endl;
    }

    auto result_2 = map_int.search(9999);
    if (result_2 != nullptr) {
        fail++;
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
        fail++;
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
    } catch (const key_not_found_exception &e) {
        cout << "Test 11 passed." << endl;
    } catch (...) {
        fail += 1;
        cout << "Test 11 failed." << endl;
    }


    return fail;
}

int HashMapTree_sanity_check() {
    int fail = 0;

    cout << "Testing HashMapTree class:" << endl;
    HashMapTree<int, int> map_int;
    HashMapTree<string, string> map_string;
    HashMapTree<double, double> map_double;

    // Test insert and operator[]
    map_int.insert(1213, 10);
    map_int.insert(211, -20);
    map_int.insert(-12, 31);
    if (map_int[1213] != 10 || map_int[211] != -20 || map_int[-12] != 31) {
        fail += 1;
        cout << "Test 1 failed." << endl;
    } else {
        cout << "Test 1 passed." << endl;
    }

    map_string.insert("one", "aaaas");
    map_string.insert("two", "bbbbs");
    map_string.insert("three", "ccccs");
    if (map_string["one"] != "aaaas" || map_string["two"] != "bbbbs" || map_string["three"] != "ccccs") {
        fail += 1;
        cout << "Test 2 failed." << endl;
    } else {
        cout << "Test 2 passed." << endl;
    }

    map_double.insert(1.12, 652.2);
    map_double.insert(-34.1, -41.1);
    map_double.insert(112.11, 43.0);
    if (map_double[1.12] != 652.2 || map_double[-34.1] != -41.1 || map_double[112.11] != 43.0) {
        fail += 1;
        cout << "Test 3 failed." << endl;
    } else {
        cout << "Test 3 passed." << endl;
    }

    // Test insert overwrite
    map_int.insert(1213, 1210);
    if (map_int[1213] != 1210) {
        fail += 1;
        cout << "Test 4 failed." << endl;
    } else {
        cout << "Test 4 passed." << endl;
    }

    // Test operator[] for inserting a new key with default value
    if (map_int[9999] != int()) { // Should insert with default value
        fail += 1;
        cout << "Test 5 failed." << endl;
    } else {
        cout << "Test 5 passed." << endl;
    }

    // Test copy constructor
    HashMapTree<int, int> map_copy(map_int);
    if (map_copy[1213] != 1210 || map_copy[211] != -20 || map_copy[-12] != 31) {
        fail += 1;
        cout << "Test 6 failed." << endl;
    } else {
        cout << "Test 6 passed." << endl;
    }

    // Test assignment operator
    HashMapTree<int, int> map_assign;
    map_assign = map_int;
    if (map_assign[1213] != 1210 || map_assign[211] != -20 || map_assign[-12] != 31) {
        fail += 1;
        cout << "Test 7 failed." << endl;
    } else {
        cout << "Test 7 passed." << endl;
    }

    // Test search()
    auto result = map_int.search(1213);
    if (result == nullptr || result->second != 1210) {
        fail += 1;
        cout << "Test 8 failed." << endl;
    } else {
        cout << "Test 8 passed." << endl;
    }

    auto result_2 = map_int.search(9999);
    if (result_2 == nullptr || result_2->second != int()) { // Should return the default-initialized node
        fail += 1;
        cout << "Test 9 failed." << endl;
    } else {
        cout << "Test 9 passed." << endl;
    }

    // Test remove
    auto to_remove = map_int.search(1213);
    map_int.remove(to_remove);
    if (map_int.search(1213) != nullptr) {
        fail += 1;
        cout << "Test 10 failed." << endl;
    } else {
        cout << "Test 10 passed." << endl;
    }

    // Test remove on non-existent key
    pair<int, int> to_remove_2(999, 22222);
    pair<int, int>* to_remove_2_ptr = &to_remove_2;
    try {
        map_int.remove(to_remove_2_ptr);
        fail += 1;
        cout << "Test 11 failed." << endl;
    } catch (const key_not_found_exception& e) {
        cout << "Test 11 passed." << endl;
    } catch (...) {
        fail += 1;
        cout << "Test 11 failed." << endl;
    }

    return fail;
}

int Set_sanity_check()
{
    int fail = 0;

    cout << "Testing Set class:" << endl;
    Set<int> set_int;
    Set<string> set_string;
    Set<double> set_double;

    // Test insert and search
    set_int.insert(10);
    set_int.insert(20);
    set_int.insert(30);
    if (!set_int.search(10) || !set_int.search(20) || !set_int.search(30)) {
        fail += 1;
        cout << "Test 1 failed." << endl;
    } else {
        cout << "Test 1 passed." << endl;
    }

    set_string.insert("apple");
    set_string.insert("banana");
    set_string.insert("cherry");
    if (!set_string.search("apple") || !set_string.search("banana") || !set_string.search("cherry")) {
        fail += 1;
        cout << "Test 2 failed." << endl;
    } else {
        cout << "Test 2 passed." << endl;
    }

    set_double.insert(1.1);
    set_double.insert(2.2);
    set_double.insert(3.3);
    if (!set_double.search(1.1) || !set_double.search(2.2) || !set_double.search(3.3)) {
        fail += 1;
        cout << "Test 3 failed." << endl;
    } else {
        cout << "Test 3 passed." << endl;
    }

    // Test insert duplicate (should not insert duplicate)
    set_int.insert(10); 
    set_int.insert(20); 
    set_int.insert(30); 
    if (set_int.search(10) != true || set_int.search(20) != true || set_int.search(30) != true) {
        fail += 1;
        cout << "Test 4 failed." << endl;
    } else {
        cout << "Test 4 passed." << endl;
    }

    // Test remove and search for removed element
    set_int.remove(20);
    if (set_int.search(20) != false) {
        fail += 1;
        cout << "Test 5 failed." << endl;
    } else {
        cout << "Test 5 passed." << endl;
    }

    // Test exception for removing a non-existent element
    try {
        set_int.remove(9999); // Non-existent value
        fail += 1; 
        cout << "Test 6 failed." << endl;
    } catch (const key_not_found_exception &e) {
        cout << "Test 6 passed." << endl;
    } catch (...) {
        fail += 1;
        cout << "Test 6 failed." << endl;
    }

    // Test copy constructor
    Set<int> set_copy(set_int);
    if (!set_copy.search(10) || set_copy.search(20) || !set_copy.search(30)) {
        fail += 1;
        cout << "Test 7 failed." << endl;
    } else {
        cout << "Test 7 passed." << endl;
    }

    // Test assignment operator
    Set<int> set_assign;
    set_assign = set_int;
    if (!set_assign.search(10) || set_assign.search(20) || !set_assign.search(30)) {
        fail += 1;
        cout << "Test 8 failed." << endl;
    } else {
        cout << "Test 8 passed." << endl;
    }


    return fail;
}

int main()
{
    int hashmap_test = HashMap_sanity_check();
    cout << "-> "<< hashmap_test << " tests failed." << endl;
    cout << "-> "<< 11 - hashmap_test << " tests passed." << endl;
    cout << endl;

    int hashmaptree_test = HashMapTree_sanity_check();
    cout << "-> "<< hashmaptree_test << " tests failed." << endl;
    cout << "-> "<< 11 - hashmaptree_test << " tests passed." << endl;
    cout << endl;

    int set_test = Set_sanity_check();
    cout << "-> " << set_test << " tests failed." << endl;
    cout << "-> " << 8 - set_test << " tests passed." << endl;
    cout << endl;
    return 0;
};
