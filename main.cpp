#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "Data_structures/array.h"
#include "Data_structures/sorted_array.h"
#include "Data_structures/BinarySearchTree.h"
#include "Data_structures/AVLTree.h"
#include "Data_structures/HashTable.h"



//this is the method we use to lowercase every character in the text and remove the special characters from it to make our word counting easier.
std::string Erase(std::string word)
{
    std::transform(word.begin(), word.end(),word.begin(), ::tolower);
    word.erase(remove_if(word.begin(), word.end(), [](char c) {return (c == '='  || c == '"' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '<' || c == '>' || c == '?' || c == '/' || c == ',' || c == '.' || c == '\'' || c == '~'); }), word.end());
    return word;
}

int main()
{

    std::ifstream file;
    std::string word, filename;
    filename = "text.txt";


    array arr(251352);
    sorted_array sarr(251352);
    BinarySearchTree btree;
    AVLTree avl;
    HashTable hash(251352);

    file.open(filename.c_str());
    if (file.is_open())
        while (file >> word)
        {
            word = Erase(word);
            if (word.empty()) continue;
            arr.insert(word);
            sarr.insert(word);
            btree.insert(word);
            avl.insert(word);
            hash.insert(word);
        }
    else
        std::cerr << "Couldn't open file.\n";


}