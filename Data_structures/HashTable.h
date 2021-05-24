#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H
#define C1 99
#define C2 107

#include <string>
#include <utility>
#include <array>

struct HashNode {
    std::string word;
    int count{};
    HashNode() = default;
};

class HashTable {

private:
    HashNode *hashTable;
    int size;
    int length;
    int HashFunc(const std::string &word) const;
    static int findNextPrime(int n);
    void resize();

public:

    explicit HashTable();
    ~HashTable();
    void insert(const std::string &word);
    bool search(const std::string &word);
};


#endif //DATA_STRUCTURES_HASHTABLE_H
