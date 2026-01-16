#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int EmptyTree(Node* root) {
    return root == NULL;
}

Node* Root(Node* root) {
    return root;
}

void ThemTrai(Node* p, int x) {
    if (p != NULL && p->left == NULL)
        p->left = new Node(x);
}
void ThemPhai(Node* p, int x) {
    if (p != NULL && p->right == NULL)
        p->right = new Node(x);
}
void DuyetTruoc(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        DuyetTruoc(root->left);
        DuyetTruoc(root->right);
    }
}
void DuyetGiua(Node* root) {
    if (root != NULL) {
        DuyetGiua(root->left);
        cout << root->data << " ";
        DuyetGiua(root->right);
    }
}
void DuyetSau(Node* root) {
    if (root != NULL) {
        DuyetSau(root->left);
        DuyetSau(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = new Node(1);

    ThemTrai(root, 2);
    ThemPhai(root, 3);

    ThemTrai(root->left, 4);
    ThemPhai(root->left, 5);

    ThemTrai(root->right, 6);
    ThemPhai(root->right, 7);

    cout << "DuyetTruoc: ";
    DuyetTruoc(root);

    cout << "\nDuyetGiua: ";
    DuyetGiua(root);

    cout << "\nDuyetSau: ";
    DuyetSau(root);

    return 0;
}