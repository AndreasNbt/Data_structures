#include "AVLTree.h"

// AVL Tree constructor, we use the Binary Search Tree constructor using inheritance as the operation is the same.
AVLTree::AVLTree() : BinarySearchTree() {}


// the private function that is used to insert
Node* AVLTree::InsertAndBalance(Node *n, const std::string &word) {
    if (!n) {   // memory commitment for the new Node if the node pointer points to an empty node
        n = new Node(word);
        return n;
    } else if (word< n->data) { // recursion to enter left side of the subtree
        n->leftChild = InsertAndBalance(n->leftChild, word);
        n = balanceTree(n, word, 1);
    } else if (word > n->data) { // recursion to enter right side of the subtree
        n->rightChild = InsertAndBalance(n->rightChild, word);
        n = balanceTree(n, word, 1);
    } else if (word == n->data) { // update of the counter in case word is already in the tree
        n->count++;
    }
    return n;
}

// the public function that the main function calls to insert a new node.
void AVLTree::insert(const std::string &word) {
    root = InsertAndBalance(root, word);
}

Node *AVLTree::DeleteAndBalance(Node *n, const std::string &word) {
    if (!n) // if node is not found
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
        {   // if node has 2 children
            Node *temp = findMaxOfSubtree(n->leftChild);
            n->data = temp->data;
            n->count = temp->count;
            n->leftChild = DeleteAndBalance(n->leftChild, temp->data);
        }
    }
    if (!n)
        return n;

    n = balanceTree(n, word, 0);

    return n;
}

// the public function that the main function calls to remove a node.
 void AVLTree::remove(const std::string &word) {
    root = DeleteAndBalance(root, word);
}

// returns the height of the tree
int AVLTree::height(Node *n) {
    return (n != nullptr ? n->height : 0 );
}

//function for the height update for the nodes that need it when we use the rotations
void AVLTree::heightUpdate(Node *t)
{
    if (height(t->leftChild) > height(t->rightChild))
        t->height = height(t->leftChild) + 1;
    else
        t->height = height(t->rightChild) + 1;
}

// the function for the tree balancing
Node *AVLTree::balanceTree(Node *n, const std::string& word, int f) {

    // height update for the nodes after the insert or remove function
    heightUpdate(n);


    // balance factor is the height difference between the left and right subtree of a node
    int balanceFactor = height(n->leftChild) - height(n->rightChild); // the factor we use to check if the tree is balanced.

    // selection of the rotation to balance the tree
    if (f == 1) { // if called by insert
        if (balanceFactor > 1) {
            if (word < n->leftChild->data) {
                return(R(n));
            } else if (word > n->leftChild->data) {
                return(LR(n));
            }
        } else if (balanceFactor < -1) {
            if (word < n->rightChild->data) {
                return(RL(n));
            } else if (word > n->rightChild->data) {
                return(L(n));
            }
        }
    }
    else { // if called by delete
        if (balanceFactor > 1) {
            if (word < n->leftChild->data) {
                return(LR(n));
            } else if (word > n->leftChild->data) {
                return(R(n));
            }
        } else if (balanceFactor < -1) {
            if (word < n->rightChild->data) {
                return(L(n));
            } else if (word > n->rightChild->data) {
                return(RL(n));
            }
        }
    }
    return n;
}

// right rotation
Node *AVLTree::R(Node *parent) {
    Node *t = parent->leftChild;
    parent->leftChild = t->rightChild;
    t->rightChild = parent;

    // height update for the nodes
    heightUpdate(parent);
    heightUpdate(t);

    return t;
}

// left rotation
Node *AVLTree::L(Node *parent) {
    Node *t = parent->rightChild;
    parent->rightChild = t->leftChild;
    t->leftChild = parent;

    // height update for the nodes
    heightUpdate(parent);
    heightUpdate(t);

    return t;
}

// left-right rotation
Node *AVLTree::LR(Node *parent) {
    Node *t = parent->leftChild;
    parent->leftChild = L(t);
    return R(parent);
}

// right-left rotation
Node *AVLTree::RL(Node *parent) {
    Node *t = parent->rightChild;
    parent->rightChild = R(t);
    return L(parent);
}



