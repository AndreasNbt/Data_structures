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
    int height;
    Node() = delete;
    explicit Node(std::string word) :data(std::move(word)), leftChild(nullptr), rightChild(nullptr), count(1), height(1) {}
};

class BinarySearchTree {

    //Binary Search Tree has 2 private methods, insert and delete a specific node.
private:
    Node* InsertNode(Node *n, const std::string &word);
    Node* DeleteNode(Node *n, const std::string &word);

protected:

     void Output(Node *t);
     Node* findMaxOfSubtree(Node *n);
     void PreOrder(Node *root);
     void PostOrder(Node *root);
     void InOrder(Node *root);

public:
    Node *root;
    BinarySearchTree();
    virtual void insert(const std::string& word);
    virtual void remove(const std::string& word);
    int search(const std::string& word);

    //The three order methods
    void PreOrder();
    void PostOrder();
    void InOrder();

};


#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
