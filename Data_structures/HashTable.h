#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H
#define Size 99

#include <string>
#include <utility>
#include <array>

struct HashNode {
    std::string word;
    int count;
    HashNode *next;
    HashNode() : count(0), next(nullptr) {}
    explicit HashNode(std::string s) : word(std::move(s)), count(1), next(nullptr) {}
};

class HashTable {

private:
    HashNode *hashTable;
    int HashFunc(const std::string &word);

public:
    HashTable();
    void Insert(const std::string &word);
    void Search(const std::string &word);
};


#endif //DATA_STRUCTURES_HASHTABLE_H
