#include <iostream>
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
node *createNode(int val) {
    node *n = new node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    n->ht = 0;
    return n;
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
node *leftLeftRotation(node *T) {
    return rotateRight(T);
}
node *rightRightRotation(node *T) {
    return rotateLeft(T);
}
node *leftRightRotation(node *T) {
    T->left = rotateLeft(T->left);
    return rotateRight(T);
}
node *rightLeftRotation(node *T) {
    T->right = rotateRight(T->right);
    return rotateLeft(T);
}
void preorder(node *T) {
    if (T != NULL) {
        cout << T->data << " ";
        preorder(T->left);
        preorder(T->right);
    }
}
int main() {
    node *llRoot = createNode(30);
    llRoot->left = createNode(20);
    llRoot->left->left = createNode(10);
    llRoot->left->ht = height(llRoot->left);
    llRoot->ht = height(llRoot);
    llRoot = leftLeftRotation(llRoot);
    cout << "After LL Rotation (Preorder): ";
    preorder(llRoot);
    cout << endl;
    node *rrRoot = createNode(10);
    rrRoot->right = createNode(20);
    rrRoot->right->right = createNode(30);
    rrRoot->right->ht = height(rrRoot->right);
    rrRoot->ht = height(rrRoot);
    rrRoot = rightRightRotation(rrRoot);
    cout << "After RR Rotation (Preorder): ";
    preorder(rrRoot);
    cout << endl;
    node *lrRoot = createNode(30);
    lrRoot->left = createNode(10);
    lrRoot->left->right = createNode(20);
    lrRoot->left->ht = height(lrRoot->left);
    lrRoot->ht = height(lrRoot);
    lrRoot = leftRightRotation(lrRoot);
    cout << "After LR Rotation (Preorder): ";
    preorder(lrRoot);
    cout << endl;
    node *rlRoot = createNode(10);
    rlRoot->right = createNode(30);
    rlRoot->right->left = createNode(20);
    rlRoot->right->ht = height(rlRoot->right);
    rlRoot->ht = height(rlRoot);
    rlRoot = rightLeftRotation(rlRoot);
    cout << "After RL Rotation (Preorder): ";
    preorder(rlRoot);
    cout << endl;
    return 0;
}
