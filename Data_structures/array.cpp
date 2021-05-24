#include "array.h"
#include <iostream>

// array constructor.
array::array()
{
    size = 10000;
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
// Also, if the array is full, we increase its size calling the resize function.
void array::insert(const std::string &word)
{
    if (length >= size)
        resize();

    int index = search(word);
    if (index == -1) {
        words[length] = word;
        wordCounter[length] = 1;
        length++;
    } else {
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

// function that increases the size of the array if it is full.
// It creates two temporary arrays temp and temp2 and stores the previous data in them
// Then, it deletes the old arrays and recreates them with double the size.
// And, using std::copy the data is copies from one array to another.
void array::resize() {

    auto *temp = new std::string[size];
    auto *temp2 = new int[size];

    std::copy(words,words + size, temp);
    std::copy(wordCounter, wordCounter+size, temp2);

    delete[] words;
    delete[] wordCounter;

    size *= 2;

    words = new std::string[size];
    wordCounter = new int[size];

    std::copy(temp, temp+ size/2, words);
    std::copy(temp2, temp2 + size/2, wordCounter);


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

