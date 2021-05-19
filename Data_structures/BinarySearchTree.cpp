#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
    : root(nullptr)
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


void BinarySearchTree::insert(const std::string& word) {
    root = InsertNode(root, word);
}

Node* BinarySearchTree::DeleteNode(Node *n, const std::string &word)
{
    if (!n)
        return n;

    if (word < n->data) //searching for the Node
        n->leftChild = DeleteNode(n->leftChild, word);
    else if (word > n->data)
        n->rightChild = DeleteNode(n->rightChild, word);
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
        else //Node has 2 children. It gets replaced with the max node of its left subtree
        {
            Node *temp = findMaxOfSubtree(n->leftChild);
            n->data = temp->data;
            n->count = temp->count;
            n->leftChild = DeleteNode(n->leftChild, temp->data);
        }
    }
    return n;
}

void BinarySearchTree::remove(const std::string& word) {
   DeleteNode(root, word);
}

Node* BinarySearchTree::search(const std::string& word) {
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
Node *BinarySearchTree::findMaxOfSubtree(Node *n) {
    if(n == nullptr)
        return nullptr;
    else if(n->rightChild == nullptr)
        return n;
    else
        return findMaxOfSubtree(n->rightChild);
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





