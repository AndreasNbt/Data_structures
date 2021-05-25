#ifndef DATA_STRUCTURES_SORTED_ARRAY_H
#define DATA_STRUCTURES_SORTED_ARRAY_H

#include "array.h"
#include <string>

class sorted_array: public array{
    // Sorted array inherits from the array class 3 protected members: *words, *wordCounter & length.
    // Also it inherits 2 public methods from the base class (array class): the [] operator overloading and the display() function.
    // Finally it has it's own 3 methods for insertion, deletion & searching.
private:
    int m_SearchIndex{};
    int find(const std::string &word) override;

public:
    sorted_array();
    void insert(const std::string &word) override;
    void remove(const std::string &word) override;

};

#endif //DATA_STRUCTURES_SORTED_ARRAY_H
