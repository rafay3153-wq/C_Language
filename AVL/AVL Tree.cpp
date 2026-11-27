#include <iostream>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
    int ht;
};
int height(node *T) {
    int lh, rh;
    if (T == NULL)
        return 0;
    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;
    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;
    if (lh > rh)
        return lh;
    return rh;
}
node *rotateleft(node *x) {
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}
node *rotateright(node *x) {
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}
node *LL(node *T) {
    return rotateright(T);
}

node *RR(node *T) {
    return rotateleft(T);
}
node *LR(node *T) {
    T->left = rotateleft(T->left);
    T = rotateright(T);
    return T;
}
node *RL(node *T) {
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return T;
}
int BF(node *T) {
    int lh, rh;
    if (T == NULL)
        return 0;
    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;
    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;
    return lh - rh;
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
                T = RR(T);
            else
                T = RL(T);
        }
    } else if (x < T->data) {
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->data)
                T = LL(T);
            else
                T = LR(T);
        }
    }
    T->ht = height(T);
    return T;
}
node *Delete(node *T, int x) {
    node *p;
    if (T == NULL) {
        return NULL;
    } else if (x > T->data) {
        T->right = Delete(T->right, x);
        if (BF(T) == 2) {
            if (BF(T->left) >= 0)
                T = LL(T);
            else
                T = LR(T);
        }
    } else if (x < T->data) {
        T->left = Delete(T->left, x);
        if (BF(T) == -2) {
            if (BF(T->right) <= 0)
                T = RR(T);
            else
                T = RL(T);
        }
    } else {
        if (T->right != NULL) {
            p = T->right;
            while (p->left != NULL)
                p = p->left;
            T->data = p->data;
            T->right = Delete(T->right, p->data);
            if (BF(T) == 2) {
                if (BF(T->left) >= 0)
                    T = LL(T);
                else
                    T = LR(T);
            }
        } else {
            node *temp = T->left;
            delete T;
            return temp;
        }
    }
    T->ht = height(T);
    return T;
}
void inorder(node *T) {
    if (T != NULL) {
        inorder(T->left);
        cout << T->data << "(BF:" << BF(T) << ") ";
        inorder(T->right);
    }
}
int main() {
    node *root = NULL;
    int values[] = {30, 20, 40, 10, 25, 50, 5};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }
    cout << "Inorder after insertions: ";
    inorder(root);
    cout << "\nTree height: " << height(root) << endl;
    root = Delete(root, 40);
    cout << "Inorder after deleting 40: ";
    inorder(root);
    cout << "\nTree height: " << height(root) << endl;
    return 0;
}
