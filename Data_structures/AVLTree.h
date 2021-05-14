#ifndef DATA_STRUCTURES_AVLTREE_H
#define DATA_STRUCTURES_AVLTREE_H

#include <utility>

#include "Data_structures/BinarySearchTree.h"


class AVLTree : public BinarySearchTree {
    private:
        Node* InsertNode(Node *n, const std::string &word);
        void Output(Node *) override;
    public:
        AVLTree();
        int height(Node *n);
        int heightDiff(Node *n);
        Node* balanceTree(Node *n);
        void Insert(const std::string &word) override;
        Node* Delete(const std::string& word) override;
        static Node *R(Node *parent);
        static Node *L(Node *parent);
        static Node *LR(Node *parent);
        static Node *RL(Node *parent);
};


#endif //DATA_STRUCTURES_AVLTREE_H
