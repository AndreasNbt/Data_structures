#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
    : root(nullptr), size(0)
{}

void BinarySearchTree::Insert(Node *t) {

}

void BinarySearchTree::Delete(Node *t) {

}

bool BinarySearchTree::Search(Node *t) {
    return false;
}

void BinarySearchTree::PreOrder(Node *t) {
    if (t) {
        Output(t);
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);
    }
}

void BinarySearchTree::PostOrder(Node *t) {
    if (t)
    {
        PostOrder(t->leftChild);
        PostOrder(t->rightChild);
        Output(t);
    }

}

void BinarySearchTree::InOrder(Node *t) {
    if (t)
    {
        InOrder(t->leftChild);
        Output(t);
        InOrder(t->rightChild);
    }
}

void BinarySearchTree::Output(Node *t) {
    std::cout << t->data << std::endl;
}


