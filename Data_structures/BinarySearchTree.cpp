#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
    : root(nullptr), size(0)
{}

void BinarySearchTree::Output(Node *t) {
    std::cout << t->data << " " << t->count << std::endl;
}

void BinarySearchTree::Insert(const std::string& word) {

    Node* newNode = new Node(word);

    if (root == nullptr)
        root = newNode;
    else
    {
        Node *currentNode = root;
        while (currentNode)
        {
            if (word == currentNode->data) {
                currentNode->count++;
                return;
            }
            else if (word < currentNode->data){
                if (currentNode->leftChild == nullptr) {
                    currentNode->leftChild = newNode;
                    return;
                }
                else
                    currentNode = currentNode->leftChild;
            }
            else {
                if (currentNode->rightChild == nullptr) {
                    currentNode->rightChild = newNode;
                    return;
                } else
                    currentNode = currentNode->rightChild;}
            }
    }
}

bool BinarySearchTree::Delete(const std::string& word) {

    Node* parentNode;
    Node *currentNode = root;

    while (currentNode && currentNode->data != word)
    {
        parentNode = currentNode;
        if (currentNode->data > word)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    if (!(currentNode))
        return false;

    if (currentNode->leftChild && currentNode->rightChild) //if node has 2 kids
    {
        Node *tempNode = currentNode->leftChild;
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
        Node *tempNode2;
        if (currentNode->leftChild && currentNode->rightChild == nullptr)
            tempNode2 = currentNode->leftChild;
        if (currentNode->leftChild == nullptr && currentNode->rightChild)
            tempNode2 = currentNode->rightChild;

        if (parentNode->leftChild == currentNode)
            parentNode->leftChild = tempNode2;
        else
            parentNode->rightChild = tempNode2;
    }
    else //if node has 0 kids
        if (parentNode->leftChild == currentNode)
            parentNode->leftChild = nullptr;
        else
            parentNode->rightChild = nullptr;

    delete currentNode; // deletes the appropriate node. Also covers the case when the node has no kids.
    return true;
}



bool BinarySearchTree::Search(const std::string& word) {
    Node *currentNode = root;
    while (currentNode)
    {
        if (word == currentNode->data)
            return true;
        else if (word < currentNode->data)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }

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

Node *BinarySearchTree::getRoot() {
    return root;
}




