#include "AVLTree.h"


AVLTree::AVLTree() : BinarySearchTree() {}

Node* AVLTree::InsertNode(Node *n, const std::string &word) {
    if (!n) {
        n = new Node(word);
        return n;
    } else if (word< n->data) {
        n->leftChild = InsertNode(n->leftChild, word);
        n = balanceTree(n);
    } else if (word >= n->data) {
        n->rightChild = InsertNode(n->rightChild, word);
        n = balanceTree(n);
    } else if (word == n->data) {
        n->count++;
    }

    return n;
}
 Node* AVLTree::Delete(const std::string &word) {
    BinarySearchTree::Delete(word);

}

int AVLTree::height(Node *n) {
    int h = 0;
    if (n != nullptr) {
        int l_height = height(n->leftChild);
        int r_height = height(n->rightChild);
        h += l_height > r_height ? l_height : r_height;
        h += 1;
    }
    return h;
}

int AVLTree::heightDiff(Node *n) {
    int l_height = height(n->leftChild);
    int r_height = height(n->rightChild);
    return l_height - r_height;
}

void AVLTree::Insert(const std::string &word) {
    root = InsertNode(root, word);
}

Node *AVLTree::balanceTree(Node *n) {
    int balanceFactor = heightDiff(n);
    if (balanceFactor > 1) {
        if (heightDiff(n->leftChild) > 0) {
            n = R(n);
        }
        else {
            n = LR(n);
        }
    } else if (balanceFactor < -1) {
        if (heightDiff(n->rightChild) > 0) {
            n = RL(n);
        }
        else {
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
    return t;
}

Node *AVLTree::L(Node *parent) {
    Node *t;
    t = parent->rightChild;
    parent->rightChild = t->leftChild;
    t->leftChild = parent;
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

void AVLTree::Output(Node *t) {
    std::cout << t->data << " " << t->count << " " << height(t) << std::endl;
}



void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == nullptr)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->rightChild, space);

    // Print current node after space
    // count
    std::cout<<std::endl;
    for (int i = 10; i < space; i++)
        std::cout<<" ";
    std::cout<<root->data<<"\n";

    // Process left child
    print2DUtil(root->leftChild, space);
}

void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}