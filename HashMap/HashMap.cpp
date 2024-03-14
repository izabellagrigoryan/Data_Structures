// HashMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair
#include <algorithm> // for std::find

class HashMap {
private:
    std::vector<std::list<std::pair<int, int>>> buckets;
    int capacity;

    int hash(int key) {
        // Simple hash function example: modulo operation
        return key % capacity;
    }

public:
    HashMap(int capacity = 10) : capacity(capacity) {
        buckets.resize(capacity);
    }

    void put(int key, int value) {
        int index = hash(key);
        // Check if the key already exists in the map
        auto& bucket = buckets[index];
        auto it = std::find_if(bucket.begin(), bucket.end(),
            [&](const std::pair<int, int>& p) { return p.first == key; });
        if (it != bucket.end()) {
            // Update the value if the key exists
            it->second = value;
        }
        else {
            // Add the key-value pair to the corresponding bucket
            bucket.push_back({ key, value });
        }
    }

    int get(int key) {
        int index = hash(key);
        // Search for the key in the corresponding bucket
        auto& bucket = buckets[index];
        auto it = std::find_if(bucket.begin(), bucket.end(),
            [&](const std::pair<int, int>& p) { return p.first == key; });
        if (it != bucket.end()) {
            // Return the value if the key is found
            return it->second;
        }
        else {
            // Return -1 if the key is not found
            return -1;
        }
    }

    void remove(int key) {
        int index = hash(key);
        // Find and remove the key-value pair from the corresponding bucket
        auto& bucket = buckets[index];
        bucket.remove_if([&](const std::pair<int, int>& p) { return p.first == key; });
    }
};

int main() {
    HashMap hashMap;
    hashMap.put(1, 10);
    hashMap.put(2, 20);
    hashMap.put(3, 30);

    std::cout << "Value for key 2: " << hashMap.get(2) << std::endl; // Output: 20
    std::cout << "Value for key 5: " << hashMap.get(5) << std::endl; // Output: -1

    hashMap.remove(2);
    std::cout << "Value for key 2 after removal: " << hashMap.get(2) << std::endl; // Output: -1

    return 0;
}