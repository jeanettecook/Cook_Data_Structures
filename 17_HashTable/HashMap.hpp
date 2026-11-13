#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <vector>
#include "HashMap.hpp"

template <typename T> 

class HashMap {
    public:
        HashMap(int capacity = 31); 
        void insert(int key, const T& value);
        void print() const;

    private:
        std::vector<HashNode<T>> data;
        int size;
        int hash(int key) const;

        int searchIndex(int key) const;
        }
#include "HashMap.hpp"
#endif