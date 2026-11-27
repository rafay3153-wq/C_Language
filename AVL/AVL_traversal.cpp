#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
    int ht;
};
int height(node *T) {
    if (T == NULL)
        return 0;
    int lh = (T->left == NULL) ? 0 : 1 + T->left->ht;
    int rh = (T->right == NULL) ? 0 : 1 + T->right->ht;
    return (lh > rh) ? lh : rh;
}
int BF(node *T) {
    if (T == NULL)
        return 0;
    int lh = (T->left == NULL) ? 0 : 1 + T->left->ht;
    int rh = (T->right == NULL) ? 0 : 1 + T->right->ht;
    return lh - rh;
}
node *rotateRight(node *x) {
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}
node *rotateLeft(node *x) {
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}
node *insert(node *T, int x) {
    if (T == NULL) {
        T = new node;
        T->data = x;
        T->left = NULL;
        T->right = NULL;
        T->ht = 0;
    } else if (x > T->data) {
        T->right = insert(T->right, x);
        if (BF(T) == -2) {
            if (x > T->right->data)
                T = rotateLeft(T);
            else {
                T->right = rotateRight(T->right);
                T = rotateLeft(T);
            }
        }
    } else if (x < T->data) {
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->data)
                T = rotateRight(T);
            else {
                T->left = rotateLeft(T->left);
                T = rotateRight(T);
            }
        }
    }
    T->ht = height(T);
    return T;
}
void levelOrderTraversal(node *root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }
    queue<node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "Level " << level << ": ";
        for (int i = 0; i < levelSize; i++) {
            node *curr = q.front();
            q.pop();
            cout << curr->data << "(BF:" << BF(curr) << ") ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << endl;
        level++;
    }
}
int main() {
    node *root = NULL;
    int keys[] = {50, 25, 75, 15, 35, 60, 85, 10, 20};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }
    cout << "AVL Tree Level Order Traversal:\n";
    levelOrderTraversal(root);
    return 0;
}
