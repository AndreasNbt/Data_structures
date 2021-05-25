#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H

#include <string>

class array {
    protected:
        std::string *words;
        int *wordCounter;
        long length;
        long size;
        void resize();
        virtual int find(const std::string &word);
    public:
        array();
        int search(const std::string &word);
        virtual void insert(const std::string &word);
        virtual void remove(const std::string &word);
        std::string& operator[](int index);
        void display();
};

#endif //DATA_STRUCTURES_ARRAY_H
