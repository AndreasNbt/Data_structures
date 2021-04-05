#include <iostream>
#include "sorted_array.h"

sorted_array::sorted_array(int size) {
    words = new std::string[size];
    wordCounter = new int[size];
    length = 0;
}

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
    return -1;

}

std::string &sorted_array::operator[](int index) {
    return words[index];
}

void sorted_array::display() {
    for (int i=0;i<length;i++)
        std::cout << words[i] << ": " << wordCounter[i] << std::endl;
}

void sorted_array::insert(const std::string &word) {
    int index = search(word);
    if (index == -1 ) {
        int i;
        for (i = length - 1; (i >= 0 && words[i] > word); i--) {
            words[i + 1] = words[i];
            wordCounter[i + 1] = wordCounter[i];
        }
        words[i + 1] = word;
        wordCounter[i + 1] = 1;
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
