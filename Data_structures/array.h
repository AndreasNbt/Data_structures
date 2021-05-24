#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H

#include <string>

class array {
    protected:
        int size;
        std::string *words;
        int *wordCounter;
        long length;
        void resize();
    public:
        array();
        virtual void insert(const std::string &word);
        virtual void remove(const std::string &word);
        virtual int search(const std::string &word) const;
        std::string& operator[](int index);

        void display();
};

#endif //DATA_STRUCTURES_ARRAY_H
