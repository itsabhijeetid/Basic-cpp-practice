#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTree {
    public : 
        T data;
        BinaryTree<T>* left;
        BinaryTree<T>* right;
        BinaryTree<T> (T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

// Build Tree From PreOrder and InOrder.
template <typename T>
BinaryTree<T>* BuildTree (int inOrder[], int inSi, int inEi, int PreOrder[], int PreSi, int PreEi) {
    if (inSi > inEi) {
        return NULL;
    }  
    int rootData = PreOrder[PreSi]; 
    // InOrder
    int rootIndex;
    for (int i = inSi; i <= inEi; i++) {
        if (inOrder[i] == rootData) {
            rootIndex = i;
            break;
        }
    } 
    int inLSi = inSi;
    int inLEi = rootIndex - 1;
    int inRSi = rootIndex + 1;  
    int inREi = inEi;
    // PreOrder
    int PreLSi = PreSi + 1;
    int PreLEi = (inLEi - inLSi) + PreLSi;
    int PreRSi = PreLEi + 1;
    int PreREi = PreEi;

    BinaryTree<T> *root = new BinaryTree<T> (rootData);
    root->left  = BuildTree<T> (inOrder, inLSi, inLEi, PreOrder, PreLSi, PreLEi );
    root->right = BuildTree<T> (inOrder, inRSi, inREi, PreOrder, PreRSi, PreREi );
    return root;
}

template <typename T>
void print (BinaryTree<T>* root) {
    if (root == NULL) {
        cout << "Empty Tree\n";
        return;
    }
    queue <BinaryTree<T>*> q;
    q.push (root);
    while (!q.empty())
    {
        cout << q.front()->data << " : ";
        if (q.front()->left != NULL) {
            cout << "L " << q.front()->left->data << ", ";
            q.push(q.front()->left);
        }
        if (q.front()->right != NULL) {
            cout << "R " << q.front()->right->data << " ";
            q.push(q.front()->right);
        } cout << endl;
        q.pop();
    }
}

int main () {
    // int inOrder[]= {1,3,4,6,7,8,10,13,14};
    // int PreOrder[]= {8,3,1,6,4,7,10,14,13};
    int inOrder[]= {4,2,5,1,8,6,9,3,7};
    int PreOrder[]= {1,2,4,5,3,6,8,9,7};
    int Si = 0; // since starting index of both will be same. 
    int Ei = 9; // since end index of both will be same.
    BinaryTree<int>* root = BuildTree<int>(inOrder, Si, Ei - 1,PreOrder, Si, Ei - 1 );
    print (root);
    return 0;
}