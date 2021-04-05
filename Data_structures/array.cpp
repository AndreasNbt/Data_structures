#include "array.h"

#include <iostream>

array::array(int size)
{
    words = new std::string[size];
    wordCounter = new int[size];
    length = 0;
}

int array::search(const std::string &word) const
{
    for (int i=0;i<length;i++)
    {
        if (word == words[i])
            return i;
    }
    return -1;

}

void array::insert(const std::string &word)
{
    int index = search(word);
    if (index == -1)
    {
        words[length] = word;
        wordCounter[length] = 1;
        length++;
    }
    else
    {
        wordCounter[index]++;
    }

}

void array::remove(const std::string &word)
{
    int index = search(word);
    if (index != -1)
    {
        length--;
        words[index] = words[length];
        wordCounter[index] = wordCounter[length];
        words[length] = "";
        wordCounter[length] = 0;
    }
}

void array::display() {
    for (int i=0;i<length;i++)
        std::cout << words[i] << ": " << wordCounter[i] << std::endl;
}

std::string &array::operator[](int index) {
    return words[index];
}


