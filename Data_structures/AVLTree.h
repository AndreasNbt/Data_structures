#ifndef DATA_STRUCTURES_AVLTREE_H
#define DATA_STRUCTURES_AVLTREE_H

#include <utility>

#include "Data_structures/BinarySearchTree.h"


class AVLTree : public BinarySearchTree {
    private:

    public:
        AVLTree();
        void Insert(const std::string &word) override;
        bool Delete(const std::string& word) override;
};


#endif //DATA_STRUCTURES_AVLTREE_H
