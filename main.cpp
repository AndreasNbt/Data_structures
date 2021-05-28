#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

#include "Data_structures/array.h"
#include "Data_structures/sorted_array.h"
#include "Data_structures/BinarySearchTree.h"
#include "Data_structures/AVLTree.h"
#include "Data_structures/HashTable.h"
#include "Timer.h"


// this is the method we use to lowercase every character in the text
// and remove the special characters from it to make our word counting easier
std::string Erase(std::string word)
{
    for(int i=0;i<word.size();i++)    // a for loop for the word length
    {
        if(word[i]>='A' && word[i]<='Z')
            word[i] -= 32; // lowercasing
        // removing special characters
        if(word[i] == '='  || word[i] == '"' || word[i] == '!' || word[i] == '@' || word[i] == '#' || word[i] == '$' || word[i] == '%' || word[i] == '^' || word[i] == '&' || word[i] == '*' || word[i] == '(' || word[i] == ')' || word[i] == '-' || word[i] == '_' || word[i] == '{' || word[i] == '}' || word[i] == '[' || word[i] == ']' || word[i] == '|' || word[i] == ';' || word[i] == ':' || word[i] == '<' || word[i] == '>' || word[i] == '?' || word[i] == '/' || word[i] == ',' || word[i] == '.' || word[i] == '\'' || word[i] == '~' || word[i] == '\t')
            word.erase(i, 1);
    }
    return word;
}
void print2D(Node *root);

int main()
{
    std::ifstream file, fil1;
    std::string word, filename;
    filename = R"(C:\Users\andre\Desktop\Data_structures\temp.txt)";
    Timer timer;

    array arr;
    sorted_array sarr;
    BinarySearchTree btree;
    AVLTree avl;
    HashTable hash;

    int words_count = 0;

    timer.start();
    file.open(filename);
    if (file.is_open()) { // the insertions in all the data structures happen
        while (file >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            arr.insert(word);
            sarr.insert(word);
            btree.insert(word);
            avl.insert(word);
            hash.insert(word);
            words_count++;
        }
    }
    else {
        std::cout << "Couldn't open file.";
        return 0;
    }

    file.close();
    file.clear();

    auto *words = new std::string[words_count]; //temporary array in which all the words will be stored, so 1000 random ones can be selected.

    int count = 0;
    file.open(filename);
    if (file.is_open()) {
        while (file >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            words[count] = word;
            count++;
        }
    }
    else {
        std::cout << "Couldn't open file.";
        return 0;
    }


    std::string Q[1000]; // Q array which will contain the randomly chosen 1000 words.


    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,words_count);

    for (auto & i : Q) {
        unsigned int num = dist6(rng);
        i = words[num];
    }

    std::cout << "Search method testing\n" ;

    std::cout << "-----------------------\n";
    timer.start();
    for (auto &i: Q) {
        int c = arr.search(i);
        //std::cout << "The word " << i << " appears " << c << " times.\n";
    }
    timer.stop();
    std::cout << "Searching in Unsorted array took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q) {
        int c = sarr.search(i);
        //std::cout << "The word " << i << " appears " << c << " times.\n";
    }
    timer.stop();
    std::cout << "Searching in Sorted array took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q) {
        int c = btree.search(i);
        //std::cout << "The word " << i << " appears " << c << " times.\n";
    }
    timer.stop();
    std::cout << "Searching in Binary Search Tree took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q) {
        int c = avl.search(i);
        //std::cout << "The word " << i << " appears " << c << " times.\n";
    }
    timer.stop();
    std::cout << "Searching in AVL Tree took: " << timer.getDuration() << " microseconds.\n\n";




    timer.start();
    for (auto &i: Q) {
        int c = hash.search(i);
        //std::cout << "The word " << i << " appears " << c << " times.\n";
    }
    timer.stop();
    std::cout << "Searching in HashTable took: " << timer.getDuration() << " microseconds.\n";
    std::cout << "-----------------------\n\n";

    std::cout << "Remove method testing\n";


    timer.start();
    for (auto &i: Q)
        arr.remove(i);

    timer.stop();
    std::cout << "Deleting in Unsorted array took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q)
        sarr.remove(i);

    timer.stop();
    std::cout << "Deleting in Sorted array took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q)
        btree.remove(i);

    timer.stop();
    std::cout << "Deleting in Binary Search Tree took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q) {
        avl.remove(i);
    }
    timer.stop();
    std::cout << "Deleting in AVL Tree took: " << timer.getDuration() << " microseconds.\n\n";


    // Hash table has no remove method

    return 0;
}