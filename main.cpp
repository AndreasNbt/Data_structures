#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <chrono>

#include "Data_structures/array.h"
#include "Data_structures/sorted_array.h"
#include "Data_structures/BinarySearchTree.h"
#include "Data_structures/AVLTree.h"
#include "Data_structures/HashTable.h"
#include "Timer.h"


//this is the method we use to lowercase every character in the text and remove the special characters from it to make our word counting easier.
std::string Erase(std::string word)
{
    std::transform(word.begin(), word.end(),word.begin(), ::tolower);
    word.erase(remove_if(word.begin(), word.end(), [](char c) {return (c == '='  || c == '"' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '<' || c == '>' || c == '?' || c == '/' || c == ',' || c == '.' || c == '\'' || c == '~' || c=='1'
    || c=='2' ||c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9' ||c=='0'); }), word.end());
    return word;
}


int main()
{

    std::ifstream file1, file2, file3, file4, file5;
    std::string word, filename;
    filename = "temp.txt";
    Timer timer;

    array arr;
    sorted_array sarr;
    BinarySearchTree btree;
    AVLTree avl;
    HashTable hash;

    file1.open(filename);
    if (file1.is_open()) {
        timer.start();
        while (file1 >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            arr.insert(word);
        }
        timer.stop();
        std::cout << "Unsorted Array" << std::endl;
        std::cout << "Insertions took " << timer.getDuration() << " seconds.\n";
        std::cout << "--------------\n";
    }
    else {
        std::cerr << "Couldn't open file.\n";
        return 1;
    }
    file1.close();

    file2.open(filename);
    if (file2.is_open()) {
        timer.start();
        while (file2 >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            sarr.insert(word);
        }
        timer.stop();
        std::cout << "Sorted Array" << std::endl;
        std::cout << "Insertions took " << timer.getDuration() << " seconds.\n";
        std::cout << "--------------\n";
    }
    else {
        std::cerr << "Couldn't open file.\n";
        return 1;
    }
    file2.close();


    file3.open(filename);
    if (file3.is_open()) {
        timer.start();
        while (file3 >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            btree.insert(word);
        }
        timer.stop();
        std::cout << "Binary Search Tree\n";
        std::cout << "Insertions took " << timer.getDuration() << " seconds.\n";
        std::cout << "--------------\n";
    }
    else {
        std::cerr << "Couldn't open file.\n";
        return 1;
    }
    file3.close();


    file4.open(filename);
    if (file4.is_open()) {
        timer.start();
        while (file4 >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            avl.insert(word);
        }
        timer.stop();
        std::cout << "AVL Tree\n";
        std::cout << "Insertions took " << timer.getDuration() << " seconds.\n";
        std::cout << "--------------\n";
    }
    else {
        std::cerr << "Couldn't open file.\n";
        return 1;
    }
    file4.close();


    file5.open(filename);
    if (file5.is_open()) {
        timer.start();
        while (file5 >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            hash.insert(word);
        }
        timer.stop();
        std::cout << "HashTable\n";
        std::cout << "Insertions took " << timer.getDuration() << " seconds.\n";
        std::cout << "--------------\n";
    }
    else {
        std::cerr << "Couldn't open file.\n";
        return 1;
    }
    file5.close();


    return 0;
}