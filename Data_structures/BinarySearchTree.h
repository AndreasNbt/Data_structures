#ifndef DATA_STRUCTURES_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_BINARYSEARCHTREE_H

#include <string>
#include <iostream>
#include <utility>

struct Node {
    std::string data;
    int count;
    Node *leftChild;
    Node *rightChild;
    Node() = delete;
    explicit Node(std::string word) :data(std::move(word)), leftChild(nullptr), rightChild(nullptr), count(1) {}
};

class BinarySearchTree {

private:
    Node *root;
    int size;

private:
    static void Output(Node *t);

public:
    BinarySearchTree();
    void Insert(Node *t);
    void Delete(Node *t);
    bool Search(Node *t);

    void PreOrder(Node *t);
    void PostOrder(Node *t);
    void InOrder(Node *t);

};


#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
