#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
#include "HashMap.cpp"
#include "HashMapTree.cpp"
using namespace std;
using namespace std::chrono;

const int max_val = 100000;
const int min_val = -100000;

/*===========================================================================
rand_arr()
Generate an array of random integers from -100000 to 100000 of the desired length.
Parameters: length of the array to be generated
Return: array of random integers
===========================================================================*/
vector<long> rand_arr(long length)
{
    vector<long> arr(length);

    // Random number generation setup
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distri(min_val, max_val);

    // Populate the array with random numbers
    for (long i = 0; i < length; i++)
    {
        arr[i] = distri(gen);
    };

    // Return the pointer to the array
    return arr;
};

/*===========================================================================
hash_map_insert_run_time()
Calculates the run time of hash map insert() based on the input length
Parameters: length of array
Return: the run time of hash map insert() in microseconds
===========================================================================*/
long long hash_map_insert_run_time(long n)
{
    // Array length n
    vector<long> arr = rand_arr(n);
    HashMap<int, int> map_int;
    auto start = high_resolution_clock::now();
    for (long i = 0; i < n; i++)
    {
        map_int.insert(arr[i], arr[i]);
    }
    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(stop - start).count();
};

/*===========================================================================
hash_map_delete_run_time()
Calculates the run time of hash map remove() based on the input length
Parameters: length of array
Return: the run time of hash map remove() in microseconds
===========================================================================*/
long long hash_map_delete_run_time(long n)
{
    vector<long> arr = rand_arr(n);
    HashMap<int, int> map_int;

    // Insert n elements
    for (long i = 0; i < n; i++)
    {
        map_int.insert(arr[i], arr[i]);
    }

    long num_deletions = n / 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> prob(0, 1);

    auto start = high_resolution_clock::now();
    for (long i = 0; i < n && num_deletions > 0; i++)
    {
        if (prob(gen) < 0.5)
        { // 50% chance to delete
            try
            {
                pair<int, int> to_remove(arr[i], arr[i]);
                pair<int, int> *to_remove_ptr = &to_remove;
                map_int.remove(to_remove_ptr);
                num_deletions--;
            }
            catch (const key_not_found_exception &e)
            {
            }
            catch (...)
            {
            }
        }
    }
    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(stop - start).count();
}

/*===========================================================================
hash_map_search_run_time()
Calculates the run time of hash map search() based on the input length
Parameters: length of array
Return: the run time of hash map search() in microseconds
===========================================================================*/
long long hash_map_search_run_time(long n)
{
    vector<long> arr = rand_arr(n);
    HashMap<int, int> map_int;

    // Insert n elements
    for (long i = 0; i < n; i++)
    {
        map_int.insert(arr[i], arr[i]);
    }

    long numSearches = n / 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distri(0, n - 1); // Random indices

    auto start = high_resolution_clock::now();
    for (long i = 0; i < numSearches; i++)
    {
        int key = arr[distri(gen)];
        map_int.search(key); // Perform search
    }
    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(stop - start).count();
}

/*===========================================================================
hash_map_all_run_time()
Calls all runtime functions and print all the run times of hash map
Parameters: None
Return: None
===========================================================================*/
void hash_map_all_run_time()
{
    vector<long> sizes = {100, 1000, 10000, 100000, 1000000};
    vector<long long> run_times;

    // Measure insert() runtime for each size
    cout << "Insert:" << endl;
    for (long size : sizes)
    {
        long long time = hash_map_insert_run_time(size);
        run_times.push_back(time);
        cout << "Runtime for size " << size << ": " << time << " microseconds" << endl;
    }
    cout << endl;

    // Measure remove() runtime for each size
    cout << "Delete:" << endl;
    for (long size : sizes)
    {
        long long time = hash_map_delete_run_time(size);
        run_times.push_back(time);
        cout << "Runtime for size " << size << ": " << time << " microseconds" << endl;
    }
    cout << endl;

    // Measure search() runtime for each size
    cout << "Search:" << endl;
    for (long size : sizes)
    {
        long long time = hash_map_search_run_time(size);
        run_times.push_back(time);
        cout << "Runtime for size " << size << ": " << time << " microseconds" << endl;
    }
    cout << endl;
}

/*===========================================================================
hash_map_tree_insert_run_time()
Calculates the run time of hash map tree insert() based on the input length
Parameters: length of array
Return: the run time of hash map tree insert() in microseconds
===========================================================================*/
long long hash_map_tree_insert_run_time(long n)
{
    // Array length n
    vector<long> arr = rand_arr(n);
    HashMapTree<int, int> map_int;
    auto start = high_resolution_clock::now();
    for (long i = 0; i < n; i++)
    {
        map_int.insert(arr[i], arr[i]);
    }
    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(stop - start).count();
};

/*===========================================================================
hash_map_tree_delete_run_time()
Calculates the run time of hash map tree remove() based on the input length
Parameters: length of array
Return: the run time of hash map tree remove() in microseconds
===========================================================================*/
long long hash_map_tree_delete_run_time(long n)
{
    vector<long> arr = rand_arr(n);
    HashMapTree<int, int> map_int;

    // Insert n elements
    for (long i = 0; i < n; i++)
    {
        map_int.insert(arr[i], arr[i]);
    }

    long num_deletions = n / 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> prob(0, 1);

    auto start = high_resolution_clock::now();
    for (long i = 0; i < n && num_deletions > 0; i++)
    {
        if (prob(gen) < 0.5)
        { // 50% chance to delete
            try
            {
                pair<int, int> to_remove(arr[i], arr[i]);
                pair<int, int> *to_remove_ptr = &to_remove;
                map_int.remove(to_remove_ptr);
                num_deletions--;
            }
            catch (const key_not_found_exception &e)
            {
            }
            catch (...)
            {
            }
        }
    }
    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(stop - start).count();
}

/*===========================================================================
hash_map_tree_search_run_time()
Calculates the run time of hash map tree search() based on the input length
Parameters: length of array
Return: the run time of hash map tree search() in microseconds
===========================================================================*/
long long hash_map_tree_search_run_time(long n)
{
    vector<long> arr = rand_arr(n);
    HashMapTree<int, int> map_int;

    // Insert n elements
    for (long i = 0; i < n; i++)
    {
        map_int.insert(arr[i], arr[i]);
    }

    long numSearches = n / 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distri(0, n - 1); // Random indices

    auto start = high_resolution_clock::now();
    for (long i = 0; i < numSearches; i++)
    {
        int key = arr[distri(gen)];
        map_int.search(key); // Perform search
    }
    auto stop = high_resolution_clock::now();

    return duration_cast<microseconds>(stop - start).count();
}

/*===========================================================================
hash_map_tree_all_run_time()
Calls all runtime functions and print all the run times of hash map
Parameters: None
Return: None
===========================================================================*/
void hash_map_tree_all_run_time()
{
    vector<long> sizes = {100, 1000, 10000, 100000, 1000000};
    vector<long long> run_times;

    // Measure insert() runtime for each size
    cout << "Insert:" << endl;
    for (long size : sizes)
    {
        long long time = hash_map_tree_insert_run_time(size);
        run_times.push_back(time);
        cout << "Runtime for size " << size << ": " << time << " microseconds" << endl;
    }
    cout << endl;

    // Measure remove() runtime for each size
    cout << "Delete:" << endl;
    for (long size : sizes)
    {
        long long time = hash_map_tree_delete_run_time(size);
        run_times.push_back(time);
        cout << "Runtime for size " << size << ": " << time << " microseconds" << endl;
    }
    cout << endl;

    // Measure search() runtime for each size
    cout << "Search:" << endl;
    for (long size : sizes)
    {
        long long time = hash_map_tree_search_run_time(size);
        run_times.push_back(time);
        cout << "Runtime for size " << size << ": " << time << " microseconds" << endl;
    }
    cout << endl;
}

void asa()
{
    vector<long> arr = rand_arr(100); // rand_arr already returns a vector
    HashMapTree<int, int> map_int;

    // Insert elements into the hash map
    for (long i = 0; i < 100; i++) {
        map_int.insert(arr[i], arr[i]);
    }

    // Get the number of elements in each slot
    vector<long> slot_sizes = map_int.elements_per_slot();

    for (long i = 0; i < slot_sizes.size(); i++) {
        cout << "Slot " << i << " contains " << slot_sizes[i] << " elements." << endl;
    }
}




int main()
{
    //hash_map_tree_all_run_time();
    asa();

    return 0;
}