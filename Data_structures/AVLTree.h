#ifndef DATA_STRUCTURES_AVLTREE_H
#define DATA_STRUCTURES_AVLTREE_H

#include <utility>

#include "Data_structures/BinarySearchTree.h"

// AVLTree consist of 9 private & 3 public members
class AVLTree : public BinarySearchTree {
    private:
        Node* InsertAndBalance(Node *n, const std::string &word);
        Node* DeleteAndBalance(Node *n, const std::string &word);
        Node *R(Node *parent);
        Node *L(Node *parent);
        Node *LR(Node *parent);
        Node *RL(Node *parent);
        Node* balanceTree(Node *n, const std::string& word);
        void heightUpdate(Node *t);

    public:
        AVLTree();
        static int height(Node *n);
        void insert(const std::string &word) override;
        void remove(const std::string &word) override;

};



#endif //DATA_STRUCTURES_AVLTREE_H
