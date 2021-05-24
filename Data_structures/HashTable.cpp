#include <iostream>
#include "HashTable.h"

HashTable::HashTable()  {
    this->size = 101;
    length = 0;
    hashTable = new HashNode[size];
}

HashTable::~HashTable() {
    delete[] hashTable;
}

int HashTable::HashFunc(const std::string &word) const {

    size_t len = word.length();
    int key = 0;

    for (int j=0;j<len;j++)
        key += word[j];
    key = abs(key) % size;

    return key;

}


void HashTable::insert(const std::string &word) {

    if (length >=  3*size/4)
        resize();

    int i=1;
    int location = HashFunc(word);


    for (int j = 0; j < size; j++)
    {
        if (hashTable[location].word == word) {
            hashTable[location].count++;
            return;
        }
        else if (hashTable[location].word.empty())
        {
            hashTable[location].word = word;
            hashTable[location].count = 1;
            length++;
            return;
        }
        else if (hashTable[location].word != word) //collision
        {
            location = (location + C1*i*i + C2*i*i) % size;
            i++;
        }
    }
}

// function that increases the size of the hashtable if it's 3/4 are filled.
// At first its current size is doubled and then we find the first prime number that comes after it.
void HashTable::resize() {

    auto *temp = new HashNode[size];

    std::copy(hashTable,hashTable + size, temp);

    delete[] hashTable;

    int tempSize = size;
    size = findNextPrime(size*2);

    hashTable = new HashNode[size];
    std::copy(temp, temp + tempSize, hashTable);

}

bool HashTable::search(const std::string &word) {
    int i = 1;
    int location = HashFunc(word);

    for (int j = 0; j < size; j++)
    {
        if (hashTable[location].word == word) {
            std::cout << "The word " << word << " appears " << hashTable[location].count << " times.";
            return true;
        }
        else if (hashTable[location].word.empty())
        {
            return false;
        }
        else if (hashTable[location].word != word) //collision
        {
            location = (location + C1*i*i + C2*i*i) % size;
            i++;
        }
    }
    return false;
}


int HashTable::findNextPrime(int n) {
    for (int i=n;; i++) {
        bool flag = true;
        for (int j = 2; j <= i / 2; j++)
            if (i % j == 0)
                flag = false;
        if (flag) return i;
    }
}





