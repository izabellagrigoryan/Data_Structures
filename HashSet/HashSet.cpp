// HashSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class HashSet {
private:
    std::vector<std::list<int>> buckets;
    int capacity;

    int hash(int key) {
        // Simple hash function example: modulo operation
        return key % capacity;
    }

public:
    HashSet(int capacity = 10) : capacity(capacity) {
        buckets.resize(capacity);
    }

    void add(int key) {
        int index = hash(key);
        // Check if the key already exists in the set
        if (!contains(key)) {
            // Add the key to the corresponding bucket
            buckets[index].push_back(key);
        }
    }

    void remove(int key) {
        int index = hash(key);
        // Find and remove the key from the corresponding bucket
        buckets[index].remove(key);
    }

    bool contains(int key) {
        int index = hash(key);
        // Search for the key in the corresponding bucket
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        return it != buckets[index].end();
    }
};

int main() {
    HashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    hashSet.add(3);

    std::cout << "Contains 2: " << std::boolalpha << hashSet.contains(2) << std::endl; // Output: true
    std::cout << "Contains 5: " << std::boolalpha << hashSet.contains(5) << std::endl; // Output: false

    hashSet.remove(2);
    std::cout << "Contains 2 after removal: " << std::boolalpha << hashSet.contains(2) << std::endl; // Output: false

    return 0;
}