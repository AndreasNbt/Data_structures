#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H
#define C1 5
#define C2 7

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
    static int HashFunc(const std::string &word, int i);

public:
    explicit HashTable(int size);
    ~HashTable();
    void insert(const std::string &word);
    bool search(const std::string &word);
    void Print();
};


#endif //DATA_STRUCTURES_HASHTABLE_H
