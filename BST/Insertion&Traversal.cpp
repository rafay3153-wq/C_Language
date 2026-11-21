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
void Preorder(BST* p) {
    if (p != NULL) {
        cout << p->data << " ";
        Preorder(p->right);
        Preorder(p->left);
    }
}
void Postorder(BST* p) {
    if (p != NULL) {
        Postorder(p->right);
        Postorder(p->left);
        cout << p->data << " ";
    }
}
void Inorder(BST* p) {
    if (p != NULL) {
        Inorder(p->right);
        cout << p->data << " ";
        Inorder(p->left);
    }
}
int main() {
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }
    cout << "\nPreorder (NRL): ";
    Preorder(root);
    cout << "\nPostorder (RLN): ";
    Postorder(root);
    cout << "\nInorder (RNL): ";
    Inorder(root);
    return 0;
}
