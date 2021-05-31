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

int main()
{

    std::ofstream output("output.txt");

    std::ifstream file, fil1;
    std::string word, filename;
    filename = R"(C:\Users\andre\Desktop\Data_structures\gutenberg.txt\gutenberg.txt)";
    Timer timer;

    array arr;
    sorted_array sarr;
    BinarySearchTree btree;
    AVLTree avl;
    HashTable hash;

    unsigned long long words_count = 0;




    file.open(filename);
    if (file.is_open()) { // word counting
        while (file >> word) {
            word = Erase(word);
            if (word.empty()) continue;
            words_count++;
        }
    }
    else {
        output << "Couldn't open file.";
        return 0;
    }


    file.close();
    file.clear();


    auto *words = new std::string[words_count]; //temporary array in which all the words will be stored, so the insertions can happen
                                                // and 1000 random ones can be selected later
    unsigned long long count = 0;
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
        output << "Couldn't open file.";
        return 0;
    }

    output << "Insert method testing\n";
    output << "-----------------------\n";

    timer.start();

    for(unsigned long long i=0;i<words_count;i++)
        arr.insert(words[i]);

    timer.stop();


    output << "Inserting in Unsorted array took: " << timer.getSec() << " seconds.\n\n";


    timer.start();
    for(unsigned long long i=0;i<words_count;i++)
        sarr.insert(words[i]);

    timer.stop();
    output << "Inserting in Sorted array took: " << timer.getSec() << " seconds.\n\n";



    timer.start();
    for(unsigned long long i=0;i<words_count;i++)
        btree.insert(words[i]);

    timer.stop();
    output << "Inserting in Binary Search Tree took: " << timer.getSec() << " seconds.\n\n";


    timer.start();
    for(unsigned long long i=0;i<words_count;i++)
        avl.insert(words[i]);

    timer.stop();
    output << "Inserting in AVL Tree took: " << timer.getSec() << " seconds.\n\n";


    timer.start();
    for(unsigned long long i=0;i<words_count;i++)
        hash.insert(words[i]);

    timer.stop();
    output << "Inserting in Hash Table took: " << timer.getSec() << " seconds.\n\n";


    output << "-----------------------\n\n";



    std::string Q[1000]; // Q array which will contain the randomly chosen 1000 words.


    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,words_count);

    for (auto & i : Q) {
        unsigned int num = dist6(rng);
        i = words[num];
    }
    delete[] words; // words array won't be used more, so deleting it to free up space


    //Measuring time needed for searching 1000 words in each data structure

    output << "Search method testing\n" ;
    output << "-----------------------\n";

    timer.start();
    for (auto &i: Q) {
        arr.search(i);
    }
    timer.stop();
    output << "Searching in Unsorted array took: " << timer.getDuration() << " microseconds.\n\n";


    timer.start();
    for (auto &i: Q) {
        sarr.search(i);
    }
    timer.stop();
    output << "Searching in Sorted array took: " << timer.getDuration() << " microseconds.\n\n";


    timer.start();
    for (auto &i: Q) {
        btree.search(i);
    }
    timer.stop();
    output << "Searching in Binary Search Tree took: " << timer.getDuration() << " microseconds.\n\n";


    timer.start();
    for (auto &i: Q) {
        avl.search(i);
    }
    timer.stop();
    output << "Searching in AVL Tree took: " << timer.getDuration() << " microseconds.\n\n";




    timer.start();
    for (auto &i: Q) {
        hash.search(i);
    }

    timer.stop();
    output << "Searching in HashTable took: " << timer.getDuration() << " microseconds.\n";
    output << "-----------------------\n\n";


    //Testing if search has the same results for each data structure

    output << "Search method results\n" ;
    output << "-----------------------\n";


    output << "Unsorted array\n";
    output << "-----------------------\n";

    for (auto &i: Q) {
        int c = arr.search(i);
        output << "The word " << i << " appears " << c << " times.\n";
    }


    output << "-----------------------\n\n";
    output << "Sorted array\n";
    output << "-----------------------\n";
    for (auto &i: Q) {
        int c = sarr.search(i);
        output << "The word " << i << " appears " << c << " times.\n";
    }



    output << "-----------------------\n\n";
    output << "Binary Search Tree\n";
    output << "-----------------------\n";
    for (auto &i: Q) {
        int c = btree.search(i);
        output << "The word " << i << " appears " << c << " times.\n";
    }

    output << "-----------------------\n\n";
    output << "AVL Tree\n";
    output << "-----------------------\n";
    timer.start();
    for (auto &i: Q) {
        int c = avl.search(i);
        output << "The word " << i << " appears " << c << " times.\n";
    }


    output << "-----------------------\n\n";
    output << "AVL Tree\n";
    output << "-----------------------\n";
    for (auto &i: Q) {
        int c = hash.search(i);
        output << "The word " << i << " appears " << c << " times.\n";
    }

    //Measuring time needed for removing 1000 words in each data structure

    output << '\n';
    output << "Remove method testing\n";
    output << "-----------------------\n";

    timer.start();
    for (auto &i: Q)
        arr.remove(i);

    timer.stop();
    output << "Deleting in Unsorted array took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q)
        sarr.remove(i);

    timer.stop();
    output << "Deleting in Sorted array took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q)
        btree.remove(i);

    timer.stop();
    output << "Deleting in Binary Search Tree took: " << timer.getDuration() << " microseconds.\n\n";



    timer.start();
    for (auto &i: Q) {
        avl.remove(i);
    }
    timer.stop();
    output << "Deleting in AVL Tree took: " << timer.getDuration() << " microseconds.\n";
    output << "-----------------------\n\n\n";

    // Hash table has no remove method


    return 0;
}