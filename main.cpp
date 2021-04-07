#include <iostream>
#include <fstream>
#include <algorithm>


#include "Data_structures/array.h"
#include "Data_structures/sorted_array.h"


std::string Erase(std::string word)
{
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

    file.open(filename.c_str());
    if (file.is_open())
        while (file >> word)
        {
            word = Erase(word);
            if (word.empty()) continue;
            arr.insert(word);
            sarr.insert(word);
        }
    else
        std::cerr << "Couldn't open file.\n";





}