// Given a binary tree with N nodes, perform Preorder , Inorder , Postorder , and Level Oreder Traversals and Display the Traversal sequences //
#include <cstddef>
class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// 2. Create Binary Tree
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    // Preorder: Root Left Right
    void preorder(Node* temp) {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Inorder: Left Root Right
    void inorder(Node* temp) {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Postorder: Left Right Root
    void postorder(Node* temp) {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    // Level Order Traversal
    void levelOrder() {
        if (root == NULL)
            return;

        Node* q[100];
        int front = 0, rear = 0;

        q[rear++] = root;

        while (front < rear) {
            Node* temp = q[front++];
            cout << temp->data << " ";

            if (temp->left != NULL)
                q[rear++] = temp->left;

            if (temp->right != NULL)
                q[rear++] = temp->right;
        }
    }
};

// Main Function
int main() {
    BinaryTree bt;

    // Creating Binary Tree
    bt.root = new Node(1);
    bt.root->left = new Node(2);
    bt.root->right = new Node(3);
    bt.root->left->left = new Node(4);
    bt.root->left->right = new Node(5);
    bt.root->right->left = new Node(6);
    bt.root->right->right = new Node(7);

    cout << "Preorder Traversal: ";
    bt.preorder(bt.root);

    cout << "\nInorder Traversal: ";
    bt.inorder(bt.root);

    cout << "\nPostorder Traversal: ";
    bt.postorder(bt.root);

    cout << "\nLevel Order Traversal: ";
    bt.levelOrder();

    return 0;
}