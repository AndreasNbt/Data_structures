#include <iostream>
#include "HashTable.h"

HashTable::HashTable()  {
    this->size = 10069;
    length = 0;
    hashTable = new HashNode[size];
}

HashTable::~HashTable() {
    delete[] hashTable;
}

// Polynomial rolling hash function
unsigned long long HashTable::HashFunc(const std::string &word) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long key = 0;
    long long p_pow = 1;
    for (char c : word) {
        key = (key + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }


    return key;
}



void HashTable::insert(const std::string &word) {

    if (length >=  3*size/4)
        resize();

    int i=1;
    unsigned long long key  = HashFunc(word);
    unsigned int location = key % size;


    for (int j = 0; j < size; j++)
    {
        if (hashTable[location].word == word) {
            hashTable[location].count++;
            return;
        }
        else if (hashTable[location].word.empty())
        {
            tempLoc = location;
            hashTable[location].word = word;
            hashTable[location].count = 1;
            length++;
            return;
        }
        else if (hashTable[location].word != word) //collision
        {
            location = (location + C1*i*i + C2*i*i) % size; //Quadratic probing
            i++;
        }
    }
}

int HashTable::search(const std::string &word) {

    int i = 1;
    unsigned long long key = HashFunc(word);
    unsigned int location = key % size;

    for (int j = 0; j < size; j++) {
        if (hashTable[location].word == word) {
            return hashTable[location].count;
        } else if (hashTable[location].word.empty()) {
            return 0;
        } else if (hashTable[location].word != word) //collision
        {
            location = (location + C1 * i * i + C2 * i * i) % size;
            i++;
        }
    }
    return 0;
}

// function that increases the size of the hashtable if it's 3/4 are filled.
// At first its current size is doubled and then we find the first prime number that comes after it.
    void HashTable::resize() {

        auto *temp = new HashNode[size];


        for (int i=0;i<size;i++)
        {
            temp[i].word = hashTable[i].word;
            temp[i].count = hashTable[i].count;
        }

        delete[] hashTable;

        int tempSize = size;
        size = findNextPrime(size * 2);

        hashTable = new HashNode[size];

        for (int i=0;i<tempSize;i++) {
            if (!temp[i].word.empty()) {
                insert(temp[i].word);
                hashTable[tempLoc].count = temp[i].count;
            }
        }

        delete[] temp;
   }

    int HashTable::findNextPrime(int n) {
        for (int i = n;; i++) {
            bool flag = true;
            for (int j = 2; j <= i / 2; j++)
                if (i % j == 0)
                    flag = false;
            if (flag) return i;
        }
    }



