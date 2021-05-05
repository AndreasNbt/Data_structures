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

void BinarySearchTree::Delete(const std::string& word) {

    Node* parentNode;

    if (root == nullptr)
        return;
    else
    {
        Node *currentNode = root;
        while (currentNode)
            if (word == currentNode->data)
            {
                if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr) {
                    delete currentNode;
                    return;
                }
                else if (currentNode->leftChild && currentNode->rightChild == nullptr) {
                    if (parentNode->leftChild == currentNode)
                    {
                        parentNode->leftChild = currentNode->leftChild;
                        delete currentNode;
                        return;
                    }
                    else
                    {
                        parentNode->rightChild = currentNode->leftChild;
                        delete currentNode;
                        return;
                    }
                }
                else if (currentNode->leftChild == nullptr && currentNode->rightChild ) {
                    if (parentNode->leftChild == currentNode)
                    {
                        parentNode->leftChild = currentNode->rightChild;
                        delete currentNode;
                        return;
                    }
                    else
                    {
                        parentNode->rightChild = currentNode->rightChild;
                        delete currentNode;
                        return;
                    }
                }
                else if (currentNode->leftChild && currentNode->rightChild)
                {
                    if (parentNode->leftChild == currentNode)
                    {
                        parentNode->leftChild = currentNode->rightChild;
                    }
                }



            }
            else if (word < currentNode->data)
                if (currentNode->leftChild == nullptr)
                    return;
                else {
                    parentNode = currentNode;
                    currentNode = currentNode->leftChild;
                }

            else if (currentNode->rightChild == nullptr)
                return;
            else {
                parentNode = currentNode;
                currentNode = currentNode->rightChild;
            }
    }
}



bool BinarySearchTree::Search(const std::string& word) {


    if (root == nullptr)
        return false;
    else
    {
        Node *currentNode = root;
        while (currentNode)
        {
            if (word == currentNode->data) {
                return true;
            }
            else if (word < currentNode->data){
                if (currentNode->leftChild == nullptr) {
                    return false;
                }
                else
                    currentNode = currentNode->leftChild;
            }
            else {
                if (currentNode->rightChild == nullptr) {
                    return false;
                } else
                    currentNode = currentNode->rightChild;}
        }
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




