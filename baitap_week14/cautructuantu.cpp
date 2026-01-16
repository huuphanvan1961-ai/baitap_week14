#include <iostream>
using namespace std;
#define MAXLENGTH 100
#define NIL -1
typedef int DataType;
typedef int Node;
typedef struct {
    DataType Data[MAXLENGTH];
    int MaxNode;
} Tree;
int EmptyTree(Tree T) {
    return T.MaxNode == 0;
}

Node Root(Tree T) {
    if (!EmptyTree(T))
        return 0;
    return NIL;
}
Node ConTrai(Node p, Tree T) {
    Node ct = 2 * (p + 1) - 1;
    if (ct < T.MaxNode)
        return ct;
    return NIL;
}
Node ConPhai(Node p, Tree T) {
    Node cp = 2 * (p + 1);
    if (cp < T.MaxNode)
        return cp;
    return NIL;
}
void ThemTrai(Node p, DataType x, Tree &T) {
    Node i = 2 * (p + 1) - 1;
    if (i >= MAXLENGTH) return;
    T.Data[i] = x;
    if (i >= T.MaxNode)
        T.MaxNode = i + 1;
}
void ThemPhai(Node p, DataType x, Tree &T) {
    Node i = 2 * (p + 1);
    if (i >= MAXLENGTH) return;
    T.Data[i] = x;
    if (i >= T.MaxNode)
        T.MaxNode = i + 1;
}
void DuyetTruoc(Node p, Tree T) {
    if (p != NIL) {
        cout << T.Data[p] << " ";
        DuyetTruoc(ConTrai(p, T), T);
        DuyetTruoc(ConPhai(p, T), T);
    }
}

void DuyetGiua(Node p, Tree T) {
    if (p != NIL) {
        DuyetGiua(ConTrai(p, T), T);
        cout << T.Data[p] << " ";
        DuyetGiua(ConPhai(p, T), T);
    }
}

void DuyetSau(Node p, Tree T) {
    if (p != NIL) {
        DuyetSau(ConTrai(p, T), T);
        DuyetSau(ConPhai(p, T), T);
        cout << T.Data[p] << " ";
    }
}
void InputTree(Tree &T) {
    T.MaxNode = 1;      
    T.Data[0] = 1;      

    ThemTrai(0, 2, T);  
    ThemPhai(0, 3, T);  

    ThemTrai(1, 4, T);  
    ThemPhai(1, 5, T);  

    ThemTrai(2, 6, T);  
    ThemPhai(2, 7, T);  
}
int main() {
    Tree T;
    InputTree(T);

    Node r = Root(T);

    cout << "DuyetTruoc: ";
    DuyetTruoc(r, T);

    cout << "\nDuyetGiua: ";
    DuyetGiua(r, T);

    cout << "\nDuyetSau: ";
    DuyetSau(r, T);

    return 0;
}
