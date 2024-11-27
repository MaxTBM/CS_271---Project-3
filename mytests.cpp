#include <iostream>
#include <string>
#include "HashMap.cpp"
#include "customexceptions.hpp"

using namespace std;

int HashMap_sanity_check()
{
    int check = 0;

    // Test default constructor
    HashMap<int, int> map_int;
    HashMap<string, string> map_string;
    HashMap<double, double> map_double;

    // Test insert and operator=
    map_int.insert(1213, 10);
    map_int.insert(211, -20);
    map_int.insert(-12, 31);
    if (map_int[1213] != 10 || map_int[211] != -20 || map_int[-12] != 31)
    {
        check += 1;
    }

    map_string.insert("one", "aaaas");
    map_string.insert("two", "bbbbs");
    map_string.insert("three", "ccccs");
    if (map_string["one"] != "aaaas" || map_string["two"] != "bbbbs" || map_string["three"] != "ccccs")
    {
        check += 1;
    }

    map_double.insert(1.12, 652.2);
    map_double.insert(-34.1, -41.1);
    map_double.insert(112.11, 43.0);
    if (map_double[1.12] != 652.2 || map_double[-34.1] != -41.1 || map_double[112.11] != 43.0)
    {
        check += 1;
    }
    return check;
}

int main()
{   
    cout << HashMap_sanity_check() << endl;
};
