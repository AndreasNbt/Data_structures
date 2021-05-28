#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H
#define C1 197
#define C2 307

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
    unsigned int tempLoc{};
    HashNode *hashTable;
    int size;
    int length;
    static unsigned long long HashFunc(const std::string &word) ;
    static int findNextPrime(int n);
    void resize();

public:

    explicit HashTable();
    ~HashTable();
    void insert(const std::string &word);
    int search(const std::string &word);
};


#endif //DATA_STRUCTURES_HASHTABLE_H
