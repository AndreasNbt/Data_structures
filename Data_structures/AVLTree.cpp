#include "AVLTree.h"


AVLTree::AVLTree() : BinarySearchTree() {}

void AVLTree::Insert(const std::string &word) {
    BinarySearchTree::Insert(word);
}

bool AVLTree::Delete(const std::string &word) {
    return BinarySearchTree::Delete(word);
}


