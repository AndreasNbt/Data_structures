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
    explicit Node(std::string word) :data(std::move(word)), leftChild(nullptr), rightChild(nullptr), count(1), height(1) {}
};

class BinarySearchTree {

private:
    Node* InsertNode(Node *n, const std::string &word);
    Node* DeleteNode(Node *n, const std::string &word);

protected:
     Node *root;
     virtual void Output(Node *t);
     Node* findMaxOfSubtree(Node *n);

public:
    Node* getRoot();
    BinarySearchTree();
    virtual void insert(const std::string& word);
    virtual void remove(const std::string& word);
    Node* search(const std::string& word);


    void PreOrder(Node *t);
    void PostOrder(Node *t);
    void InOrder(Node *t);

};


#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
