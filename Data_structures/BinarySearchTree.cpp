#include "BinarySearchTree.h"

// Binary Search Tree constructor
BinarySearchTree::BinarySearchTree()
    : root(nullptr)
{}

// An output method to print the data of the tree
void BinarySearchTree::Output(Node *t) {
    std::cout << t->data << " " << t->count <<  std::endl;
}

Node *BinarySearchTree::InsertNode(Node *n, const std::string &word) {
    if (!n) {   // if there is no data in the node we just add the new data.
        n = new Node(word);
        return n;
// searching for the Node.
    } else if (word< n->data) { // if the word is "smaller" than the current node's data, we use recursion to enter the left child of the node
        n->leftChild = InsertNode(n->leftChild, word);
    } else if (word > n->data) { // if the word is "bigger" than the current node's data, we use recursion to enter the right child of the node
        n->rightChild = InsertNode(n->rightChild, word);
    } else if (word == n->data) { // finally if the word is found we increase the counter.
        n->count++;
    }

    return n;
}

// insert method, this is the function we use in the main.cpp file to make insertions.
// InsertNode method does all the work for the insertion.
void BinarySearchTree::insert(const std::string& word) {
    root = InsertNode(root, word);
}

Node* BinarySearchTree::DeleteNode(Node *n, const std::string &word)
{
    if (!n) //if there are no Nodes in the tree we just stop the method because there is nothing to delete.
        return n;

    if (word < n->data) //searching for the Node.
        n->leftChild = DeleteNode(n->leftChild, word);
    else if (word > n->data)
        n->rightChild = DeleteNode(n->rightChild, word);
    else
    { //Node found
        if (n->leftChild == nullptr || n->rightChild == nullptr) // Node has 1 child case.
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
            else // If node has 1 child.
                *n = *temp;

            delete(temp);
        }
        else //Node has 2 children. It gets replaced with the max node of its left subtree.
        {
            Node *temp = findMaxOfSubtree(n->leftChild);
            n->data = temp->data;
            n->count = temp->count;
            n->leftChild = DeleteNode(n->leftChild, temp->data);
        }
    }
    return n;
}

// delete method, this is the function we use in the main.cpp file to make deletions.
// DeleteNode method does all the work for the deletions.
void BinarySearchTree::remove(const std::string& word) {
   DeleteNode(root, word);
}

// search method. Returns the number of appearances of the word
int BinarySearchTree::search(const std::string& word) {
    Node *currentNode = root;
    while (currentNode)
    {
        if (word == currentNode->data) {
            return currentNode->count;
        }
        else if (word < currentNode->data)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    return 0;
}

// a function to find the Max element of a subtree.
Node *BinarySearchTree::findMaxOfSubtree(Node *n) {
    if(n == nullptr)
        return nullptr;
    else if(n->rightChild == nullptr)
        return n;
    else
        return findMaxOfSubtree(n->rightChild);
}

// The three order methods
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

void BinarySearchTree::PreOrder() {
    PreOrder(root);
}

void BinarySearchTree::PostOrder() {
    PreOrder(root);
}

void BinarySearchTree::InOrder() {
    PreOrder(root);
}






