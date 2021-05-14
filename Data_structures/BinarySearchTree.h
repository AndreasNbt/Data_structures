#ifndef DATA_STRUCTURES_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_BINARYSEARCHTREE_H

#include <string>
#include <iostream>


struct Node {
    Node *leftChild;
    Node *rightChild;
    std::string data;
    int count;
    Node() = delete;
    explicit Node(std::string word) :data(std::move(word)), leftChild(nullptr), rightChild(nullptr),count(1) {}
};

class BinarySearchTree {
private:
    Node* InsertNode(Node *n, const std::string &word);


protected:
     Node *root;
     int size;
     virtual void Output(Node *t);

public:
    virtual Node* getRoot();
    BinarySearchTree();
    virtual void Insert(const std::string& word);
    virtual Node* Delete(const std::string& word);
    Node* Search(const std::string& word);

    void PreOrder(Node *t);
    void PostOrder(Node *t);
    void InOrder(Node *t);

};


#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
