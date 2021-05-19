#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int size)  {
    this->size = size;
    hashTable = new HashNode[size];
}

HashTable::~HashTable() {
    delete[] hashTable;
}

int HashTable::HashFunc(const std::string &word, int i) {

    size_t len = word.length();
    int key = 0;

    for (int j=0;j<len;j++)
        key += word[j];
    key = abs(key);

    return (key + C1*i*i + C2*i*i);

}


void HashTable::insert(const std::string &word) {

    int i=0;
    int location = HashFunc(word, i);

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
            return;
        }
        else if (hashTable[location].word != word) //collision
        {
            location = HashFunc(word, i++);
        }
    }
}

bool HashTable::search(const std::string &word) {
    int i = 0;
    int location = HashFunc(word, i);

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
            location = HashFunc(word, i++);
        }
    }
    return false;
}

void HashTable::Print() {
    for (int i = 0; i < size; i++)
        std::cout << hashTable[i].word << "  " << hashTable[i].count << std::endl;
}



