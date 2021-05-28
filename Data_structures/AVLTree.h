#ifndef DATA_STRUCTURES_AVLTREE_H
#define DATA_STRUCTURES_AVLTREE_H

#include <utility>

#include "Data_structures/BinarySearchTree.h"

// AVLTree consist of 9 private & 3 public members
class AVLTree : public BinarySearchTree {
    private:
        Node* InsertAndBalance(Node *n, const std::string &word);
        Node* DeleteAndBalance(Node *n, const std::string &word);
        void heightUpdate(Node *parent, Node *t);
        static Node *R(Node *parent);
        static Node *L(Node *parent);
        static Node *LR(Node *parent);
        static Node *RL(Node *parent);
        static int height(Node *n);
        static Node* balanceTree(Node *n, const std::string& word);

    public:
        AVLTree();
        void insert(const std::string &word) override;
        void remove(const std::string &word) override;

};


#endif //DATA_STRUCTURES_AVLTREE_H
