#ifndef DATA_STRUCTURES_BINARYTREE_H
#define DATA_STRUCTURES_BINARYTREE_H

#include <string>
#include <utility>

struct Node {
    std::string data;
    Node *leftChild;
    Node *rightChild;
    Node() : leftChild(nullptr), rightChild(nullptr) {}
    explicit Node(std::string word) :data(std::move(word)), leftChild(nullptr), rightChild(nullptr) {}
};

class BinaryTree {

private:
    Node *root;
    int size;

public:
    BinaryTree();

};


#endif //DATA_STRUCTURES_BINARYTREE_H
