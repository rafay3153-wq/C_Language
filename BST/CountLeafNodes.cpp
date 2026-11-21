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
void printLeaf(BST* p) {
    if (p != NULL) {
        if (p->left == NULL && p->right == NULL) {
            cout << p->data << " ";
        }
        printLeaf(p->left);
        printLeaf(p->right);
    }
}
int countLeaf(BST* p) {
    if (p == NULL) {
        return 0;
    }
    if (p->left == NULL && p->right == NULL) {
        return 1;
    }
    return countLeaf(p->left) +
           countLeaf(p->right);
}
int main() {
    int n, value;
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
    cout << "\nLeaf Nodes: ";
    printLeaf(root);
    cout << "\nTotal Leaf Nodes: ";
    cout << countLeaf(root);
    return 0;
}


