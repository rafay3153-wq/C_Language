#include <iostream>
using namespace std;
struct BST {
    int data;
    BST* left;
    BST* right;
};
BST* root = NULL;
void insert(int value) {
    BST* curr = new BST;
    curr->data = value;
    curr->left = NULL;
    curr->right = NULL;
    if (root == NULL) {
        root = curr;
        return;
    }
    BST* p = root;
    BST* q = NULL;
    while (p != NULL) {
        q = p;
        if (value > p->data) {
            p = p->right;
        }
        else {
            p = p->left;
        }
    }
    if (value > q->data) {
        q->right = curr;
    }
    else {
        q->left = curr;
    }
}
BST* findMin(BST* p) {
    while (p != NULL && p->left != NULL) {
        p = p->left;
    }
    return p;
}
BST* deleteNode(BST* p, int key) {
    if (p == NULL) {
        return NULL;
    }
    if (key < p->data) {
        p->left = deleteNode(p->left, key);
    }
    else if (key > p->data) {
        p->right = deleteNode(p->right, key);
    }
    else {
        if (p->left == NULL && p->right == NULL) {
            delete p;
            return NULL;
        }
        else if (p->left == NULL) {
            BST* temp = p->right;
            delete p;
            return temp;
        }
        else if (p->right == NULL) {
            BST* temp = p->left;
            delete p;
            return temp;
        }
        else {
            BST* temp = findMin(p->right);
            p->data = temp->data;
            p->right = deleteNode(p->right, temp->data);
        }
    }
    return p;
}
void Inorder(BST* p) {

    if (p != NULL) {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}
int main() {
    int n, value, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n < 0) {
        cout << "Invalid number of nodes!";
        return 0;
    }
    cout << "Enter values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }
    cout << "\nOriginal BST (Inorder): ";
    Inorder(root);
    cout << "\n\nEnter value to delete: ";
    cin >> key;
    root = deleteNode(root, key);
    cout << "\nBST after deletion: ";
    Inorder(root);
    return 0;
}