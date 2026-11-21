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

void Inorder(BST* p) {
    if (p != NULL) {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}

void Preorder(BST* p) {
    if (p != NULL) {
        cout << p->data << " ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

void Postorder(BST* p) {
    if (p != NULL) {
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }
}

BST* recursive_insert(BST* p, int value) {
    if (p == NULL) {
        BST* curr = new BST;
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
        return curr;
    }
    if (value > p->data) {
        p->right = recursive_insert(p->right, value);
    }
    else {
        p->left = recursive_insert(p->left, value);
    }
    return p;
}
 
BST* search(int key, int& comparisons) {
    BST* p = root;
    comparisons = 0;
    while (p != NULL) {
        comparisons++;
        if (p->data == key) {
            return p;
        }
        if (key > p->data) {
            p = p->right;
        }
        else {
            p = p->left;
        }
    }
    return NULL;
}

BST* minimum() {
    if (root == NULL) {
        return NULL;
    }
    BST* p = root;
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}

BST* maximum() {
    if (root == NULL) {
        return NULL;
    }
    BST* p = root;
    while (p->right != NULL) {
        p = p->right;
    }
    return p;
}

int count = 0;
int total = 0;
void sum(BST* p) {
    if (p != NULL) {
        count++;
        total = total + p->data;

        sum(p->left);
        sum(p->right);
    }
}
int main() {
    int n, value;
    cout << "How many nodes? ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }
    cout << "\nInorder: ";
    Inorder(root);
    cout << "\nPreorder: ";
    Preorder(root);
    cout << "\nPostorder: ";
    Postorder(root);
    int key, comparisons = 0;
    cout << "\n\nEnter value to search: ";
    cin >> key;
    BST* result = search(key, comparisons);
    if (result != NULL) {
        cout << "Value found!";
        cout << "\nComparisons: " << comparisons;
    }
    else {
        cout << "Value not found!";
        cout << "\nComparisons: " << comparisons;
    }
    BST* minNode = minimum();
    BST* maxNode = maximum();
    if (minNode != NULL && maxNode != NULL) {
        cout << "\nMinimum: " << minNode->data;
        cout << "\nMaximum: " << maxNode->data;
    }
    count = 0;
    total = 0;
    sum(root);
    cout << "\nTotal Nodes: " << count;
    cout << "\nSum of Nodes: " << total;
    return 0;
}
