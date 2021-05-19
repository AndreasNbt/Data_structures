#include <iostream>
#include "sorted_array.h"

// sorted array constructor.
// We benefit from the base class (array class) and we are using it's constructor for the sorted array constructor.
sorted_array::sorted_array(int size): array(size) {}

// search function, we use the binary search method to find the given word.
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

// insert method for the sorted array, we benefit from the search method,
// if the word is not in the array we add it on the right position in the array (ascending order),
// if the word is already in the array we just increase the counter of this word.
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

// using the search function, if we find the given word we delete it from the array.
void sorted_array::remove(const std::string &word) {
    int index = search(word);
    if (index == -1)
        return;
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
