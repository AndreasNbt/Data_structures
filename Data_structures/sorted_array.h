#ifndef DATA_STRUCTURES_SORTED_ARRAY_H
#define DATA_STRUCTURES_SORTED_ARRAY_H


#include <string>

class sorted_array {
private:
    std::string *words;
    int *wordCounter;
    long length;


public:
    sorted_array() = delete;
    explicit sorted_array(int size);

    void insert(const std::string &word);
    void remove(const std::string &word);
    int search(const std::string &word) ;
    std::string& operator[](int index);
    void display();

};

#endif //DATA_STRUCTURES_SORTED_ARRAY_H
