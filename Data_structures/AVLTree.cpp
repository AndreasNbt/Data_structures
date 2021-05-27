#include "AVLTree.h"


AVLTree::AVLTree() : BinarySearchTree() {}


Node* AVLTree::InsertAndBalance(Node *n, const std::string &word) {
    if (!n) {
        n = new Node(word);
        return n;
    } else if (word< n->data) {
        n->leftChild = InsertAndBalance(n->leftChild, word);
        n = balanceTree(n, word);
    } else if (word > n->data) {
        n->rightChild = InsertAndBalance(n->rightChild, word);
        n = balanceTree(n, word);
    } else if (word == n->data) {
        n->count++;
    }

    return n;
}

void AVLTree::insert(const std::string &word) {
    root = InsertAndBalance(root, word);

}

Node *AVLTree::DeleteAndBalance(Node *n, const std::string &word) {
    if (!n)
        return n;

    if (word < n->data) //searching for the Node
        n->leftChild = DeleteAndBalance(n->leftChild, word);
    else if (word > n->data)
        n->rightChild = DeleteAndBalance(n->rightChild, word);
    else
    { //Node found
        if (n->leftChild == nullptr || n->rightChild == nullptr) // Node has 1 child case
        {
            Node *temp;
            if (n->leftChild)
                temp = n->leftChild;
            else
                temp = n->rightChild;

            if (!temp) // if Node has 0 children.
            {
                temp = n;
                n = nullptr;
            }
            else // If node has 1 child
                *n = *temp;

            delete(temp);
        }
        else
        {
            Node *temp = findMaxOfSubtree(n->leftChild);
            n->data = temp->data;
            n->count = temp->count;
            n->leftChild = DeleteAndBalance(n->leftChild, temp->data);
        }
    }
    if (!n)
        return n;

    n = balanceTree(n, word);

    return n;


}

 void AVLTree::remove(const std::string &word) {
    root = DeleteAndBalance(root, word);
}

int AVLTree::height(Node *n) {
    return (n != nullptr ? n->height : 0 );
}


Node *AVLTree::balanceTree(Node *n, const std::string& word) {

    if (height(n->leftChild) > height(n->rightChild))
        n->height = height(n->leftChild) + 1;
    else
        n->height = height(n->rightChild) + 1;


    int balanceFactor = height(n->leftChild) - height(n->rightChild);


    if (balanceFactor > 1) {
        if (word < n->leftChild->data) {
            n = R(n);
        }
        else if (word > n->leftChild->data) {
            n = LR(n);
        }
    } else if (balanceFactor < -1) {
        if (word < n->rightChild->data ) {
            n = RL(n);
        }
        else if (word > n->rightChild->data) {
            n = L(n);
        }
    }
    return n;
}

Node *AVLTree::R(Node *parent) {
    Node *t;
    t = parent->leftChild;
    parent->leftChild = t->rightChild;
    t->rightChild = parent;

    if (height(parent->leftChild) > height(parent->rightChild))
        parent->height = height(parent->leftChild) + 1;
    else
        parent->height = height(parent->rightChild) + 1;

    if (height(t->leftChild) > height(t->rightChild))
        t->height = height(t->leftChild) + 1;
    else
        t->height = height(t->rightChild) + 1;
    return t;
}

Node *AVLTree::L(Node *parent) {
    Node *t;
    t = parent->rightChild;
    parent->rightChild = t->leftChild;
    t->leftChild = parent;

    if (height(parent->leftChild) > height(parent->rightChild))
        parent->height = height(parent->leftChild) + 1;
    else
        parent->height = height(parent->rightChild) + 1;

    if (height(t->leftChild) > height(t->rightChild))
        t->height = height(t->leftChild) + 1;
    else
        t->height = height(t->rightChild) + 1;
    return t;
}

Node *AVLTree::LR(Node *parent) {
    Node *t;
    t = parent->leftChild;
    parent->leftChild = L(t);
    return R(parent);
}

Node *AVLTree::RL(Node *parent) {
    Node *t;
    t = parent->rightChild;
    parent->rightChild = R(t);
    return L(parent);
}



