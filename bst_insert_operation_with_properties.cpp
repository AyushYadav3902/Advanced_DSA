// Given a Binary Search Tree(BST), implement INSERT operation while maintaining BST properties, and display the tree using inorder traversal //
#include <iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node *left, *right;

    Node (int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class BST
{
    Node *root;
    Node* insert(Node *temp, int value)
    {
        if (temp == NULL)
        return new Node(value);
        if (value < temp -> data)
        temp -> left = insert(temp -> left, value);
        else
        temp -> right = insert(temp -> right, value);
        return temp;
    }
    public :
    BST()
    {
        root = NULL;
    }
    void insert(int value)
    {
        root = insert(root, value); 
    }
};

int main() {
    BST bst;
    bst.insert(5);
    return 0;
}