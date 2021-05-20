#ifndef DATA_STRUCTURES_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_BINARYSEARCHTREE_H

#include <string>
#include <iostream>

//Node for the tree data.
struct Node {
    Node *leftChild;
    Node *rightChild;
    std::string data;
    int count;
    Node() = delete;
    explicit Node(std::string word) :data(std::move(word)), leftChild(nullptr), rightChild(nullptr), count(1) {}
};

class BinarySearchTree {

    //Binary Search Tree has 2 private methods, insert and delete a specific node.
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

    //The three order methods
    void PreOrder(Node *t);
    void PostOrder(Node *t);
    void InOrder(Node *t);

};


#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
