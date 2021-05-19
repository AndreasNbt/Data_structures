#include "array.h"
#include <iostream>

// array constructor.
array::array(int size)
{
    words = new std::string[size];
    wordCounter = new int[size];
    length = 0;
}

// ordering search for the array.
int array::search(const std::string &word) const
{
    for (int i=0;i<length;i++)
    {
        if (word == words[i])
            return i;
    }
    return -1;
}

// using the search function, if the word is not in the array we add it,
// if the word is already in the array we just increase the counter of this word.
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

// using the search function, if we find the given word we delete it from the array.
void array::remove(const std::string &word)
{
    int index = search(word);
    if (index == -1)
        return;
    else
    {
        length--;
        words[index] = words[length];
        wordCounter[index] = wordCounter[length];
        words[length] = "";
        wordCounter[length] = 0;
    }
}

// a function to print the words and how many times they are found in the text.
void array::display() {
    for (int i=0;i<length;i++)
        std::cout << words[i] << ": " << wordCounter[i] << std::endl;
}

// operator overload for the brackets operator.
std::string &array::operator[](int index) {
    return words[index];
}


