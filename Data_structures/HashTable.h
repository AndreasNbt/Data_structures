#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H

#include <string>
#include <utility>

struct HashNode {
    std::string word;
    int count;
    HashNode *next;
    HashNode() = delete;
    explicit HashNode(std::string s) : word(std::move(s)), count(1), next(nullptr) {}
};

class HashTable {

};


#endif //DATA_STRUCTURES_HASHTABLE_H
