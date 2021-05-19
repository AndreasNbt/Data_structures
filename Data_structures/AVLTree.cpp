#include "AVLTree.h"


AVLTree::AVLTree() : BinarySearchTree() {}

Node* AVLTree::InsertAndBalance(Node *n, const std::string &word) {
    if (!n) {
        n = new Node(word);
        return n;
    } else if (word< n->data) {
        n->leftChild = InsertAndBalance(n->leftChild, word);
        n = balanceTree(n);
    } else if (word >= n->data) {
        n->rightChild = InsertAndBalance(n->rightChild, word);
        n = balanceTree(n);
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

    n = balanceTree(n);

    return n;


}

 void AVLTree::remove(const std::string &word) {
    root = DeleteAndBalance(root, word);
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


