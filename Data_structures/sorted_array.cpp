#include <iostream>
#include "sorted_array.h"

//sorted array constructor.
sorted_array::sorted_array(int size) {
    words = new std::string[size];
    wordCounter = new int[size];
    length = 0;
}

//search function, we use the binary search method to find the given word.
int sorted_array::search(const std::string &word) {

    int start = 0;
    int end = length;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (words[mid] == word)
            return mid;
        else
            if (words[mid] < word)
                start = mid + 1;
            else
                end = mid - 1;
    }
    m_SearchIndex = mid;
    return -1;

}

//operator overload for the brackets operator
std::string &sorted_array::operator[](int index) {
    return words[index];
}

//a function to print the words and how many times they are found in the text
void sorted_array::display() {
    for (int i=0;i<length;i++)
        std::cout << words[i] << ": " << wordCounter[i] << std::endl;
}


void sorted_array::insert(const std::string &word) {
    int index = search(word);
    if (index == -1) {
        if (words[m_SearchIndex] < word)
            m_SearchIndex++;
        int i;
        for (i=length;i>m_SearchIndex;i--)
        {
            words[i] = words[i-1];
            wordCounter[i] = wordCounter[i-1];
        }
        words[i] = word;
        wordCounter[i] = 1;
        length++;
    }
    else
        wordCounter[index]++;

}



void sorted_array::remove(const std::string &word) {
    int index = search(word);
    if (index == -1)
        std::cout << "Word does not exist in the array.";
    else
    {
        for (int i=index;i<length;i++)
        {
            words[i] = words[i+1];
            wordCounter[i] = wordCounter[i+1];
        }
        length--;
    }
}
