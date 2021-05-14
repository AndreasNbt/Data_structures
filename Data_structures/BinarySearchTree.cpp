#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
    : root(nullptr), size(0)
{}

void BinarySearchTree::Output(Node *t) {
    std::cout << t->data << " " << t->count <<  std::endl;
}

Node *BinarySearchTree::InsertNode(Node *n, const std::string &word) {
    if (!n) {
        n = new Node(word);
        return n;
    } else if (word< n->data) {
        n->leftChild = InsertNode(n->leftChild, word);
    } else if (word > n->data) {
        n->rightChild = InsertNode(n->rightChild, word);
    } else if (word == n->data) {
        n->count++;
    }
    return n;
}


void BinarySearchTree::Insert(const std::string& word) {
    root = InsertNode(root, word);
}

Node* BinarySearchTree::Delete(const std::string& word) {

    Node* parentNode;
    Node *currentNode = root;
    Node *tempNode = nullptr;

    while (currentNode && currentNode->data != word) // find the node to be deleted and its parent
    {
        parentNode = currentNode;
        if (currentNode->data > word)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    if (!(currentNode)) // if node is not found, return false
        return nullptr;

    if (currentNode->leftChild && currentNode->rightChild) //if node has 2 kids
    {
        tempNode = currentNode->leftChild;
        Node *tempParentNode = currentNode;

        while (tempNode->rightChild)
        {
            tempParentNode = tempNode;
            tempNode = tempNode->rightChild;
        }
        tempParentNode->rightChild = nullptr;
        if (tempNode->leftChild)
            tempParentNode->rightChild = tempNode->leftChild;

        if (parentNode->leftChild == currentNode)
            parentNode->leftChild = tempNode;
        else
            parentNode->rightChild = tempNode;


        tempNode->leftChild = currentNode->leftChild;
        tempNode->rightChild = currentNode->rightChild;
    }
    else if (currentNode->leftChild || currentNode->rightChild) // if node has 1 kid
    {
        if (currentNode->leftChild && currentNode->rightChild == nullptr)
            tempNode = currentNode->leftChild;
        if (currentNode->leftChild == nullptr && currentNode->rightChild)
            tempNode = currentNode->rightChild;

        if (parentNode->leftChild == currentNode)
            parentNode->leftChild = tempNode;
        else
            parentNode->rightChild = tempNode;
    }
    else //if node has 0 kids
        if (parentNode->leftChild == currentNode)
            parentNode->leftChild = nullptr;
        else
            parentNode->rightChild = nullptr;

    delete currentNode; // deletes the appropriate node.
    size--;
    return tempNode;
}



Node* BinarySearchTree::Search(const std::string& word) {
    Node *currentNode = root;
    while (currentNode)
    {
        if (word == currentNode->data)
            return currentNode;
        else if (word < currentNode->data)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    return nullptr;
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

Node *BinarySearchTree::getRoot() {
    return root;
}





