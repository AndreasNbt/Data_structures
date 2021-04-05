#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H

#include <string>



class array {
    private:
        std::string *words;
        int *wordCounter;
        long length;

    public:
        array() = delete;
        explicit array(int size);

        void insert(const std::string &word);
        void remove(const std::string &word);
        int search(const std::string &word) const;
        std::string& operator[](int index);
        void display();

};


#endif //DATA_STRUCTURES_ARRAY_H
