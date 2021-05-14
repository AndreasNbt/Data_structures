#ifndef DATA_STRUCTURES_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_BINARYSEARCHTREE_H

#include <string>
#include <iostream>


struct Node {
    Node *leftChild;
    Node *rightChild;
    std::string data;
    int count;
    int height;
    Node() = delete;
    explicit Node(std::string word) :data(std::move(word)), leftChild(nullptr), rightChild(nullptr), height(0), count(1) {}
};

class BinarySearchTree {
protected:
     Node *root;
     int size;
     static void Output(Node *t);

public:
    virtual Node* getRoot();
    BinarySearchTree();
    virtual void Insert(const std::string& word);
    virtual bool Delete(const std::string& word);
    bool Search(const std::string& word);

    void PreOrder(Node *t);
    void PostOrder(Node *t);
    void InOrder(Node *t);

};


#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
