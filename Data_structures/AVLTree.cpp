#include "AVLTree.h"

// AVL Tree constructor, we use the Binary Search Tree constructor using inheritance as the operation is the same.
AVLTree::AVLTree() : BinarySearchTree() {}

void print2DUtil(Node *root, int space)
{
    if (root == nullptr)
        return;
    space += 10;
    print2DUtil(root->rightChild, space);

    std::cout<<std::endl;
    for (int i = 10; i < space; i++)
        std::cout<<" ";
    std::cout<<root->data<<"\n";

    print2DUtil(root->leftChild, space);
}

void print2D(Node *root)
{
    print2DUtil(root, 0);
}

// the private function that is used to insert
Node* AVLTree::InsertAndBalance(Node *n, const std::string &word) {
    if (!n) {   // memory commitment for the new Node if the node pointer points to an empty node
        n = new Node(word);
        return n;
    } else if (word< n->data) { // recursion to enter left side of the subtree
        n->leftChild = InsertAndBalance(n->leftChild, word);
        n = balanceTree(n, word);
    } else if (word > n->data) { // recursion to enter right side of the subtree
        n->rightChild = InsertAndBalance(n->rightChild, word);
        n = balanceTree(n, word);
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
        {
            Node *temp = findMaxOfSubtree(n->leftChild);
            n->data = temp->data;
            n->count = temp->count;
            n->leftChild = DeleteAndBalance(n->leftChild, temp->data);
        }
    }
    if (!n) // if node is not found
        return n;

    n = balanceTree(n, word);

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
Node *AVLTree::balanceTree(Node *n, const std::string& word) {

    // height update for the nodes after the insert or remove function
    heightUpdate(n);

    // subtraction of the left and right height
    int balanceFactor = height(n->leftChild) - height(n->rightChild); // the factor we use to check if the tree is balanced.
    //std::cout << balanceFactor << std::endl;
    // selection of the rotation to balance the tree
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

// right rotation
Node *AVLTree::R(Node *parent) {
    Node *t;
    t = parent->leftChild;

    if (t == nullptr) return parent;

    parent->leftChild = t->rightChild;
    t->rightChild = parent;

    // height update for the nodes
    heightUpdate(parent);
    heightUpdate(t);

    return t;
}

// left rotation
Node *AVLTree::L(Node *parent) {
    Node *t;
    t = parent->rightChild;

    if (t == nullptr) return parent;

    parent->rightChild = t->leftChild;
    t->leftChild = parent;

    // height update for the nodes
    heightUpdate(parent);
    heightUpdate(t);

    return t;
}

// left-right rotation
Node *AVLTree::LR(Node *parent) {
    Node *t;
    t = parent->leftChild;
    parent->leftChild = L(t);
    return R(parent);
}

// right-left rotation
Node *AVLTree::RL(Node *parent) {
    Node *t;
    t = parent->rightChild;
    parent->rightChild = R(t);
    return L(parent);
}



