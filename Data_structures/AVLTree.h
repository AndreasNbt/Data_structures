#ifndef DATA_STRUCTURES_AVLTREE_H
#define DATA_STRUCTURES_AVLTREE_H

#include <utility>

#include "Data_structures/BinarySearchTree.h"

// AVLTree consist of 8 private & 4 public members
class AVLTree : public BinarySearchTree {
private:
    Node* InsertAndBalance(Node *n, const std::string &word);
    Node* DeleteAndBalance(Node *n, const std::string &word);
    static Node *R(Node *parent);
    static Node *L(Node *parent);
    static Node *LR(Node *parent);
    static Node *RL(Node *parent);
    static Node* balanceTree(Node *n, const std::string& word, int f);
    static void heightUpdate(Node *t);

public:
    AVLTree();
    static int height(Node *n);
    void insert(const std::string &word) override;
    void remove(const std::string &word) override;

};



#endif //DATA_STRUCTURES_AVLTREE_H