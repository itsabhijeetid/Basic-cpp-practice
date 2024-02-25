#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BST {
    public : 
        T data;
        BST<T>* left;
        BST<T>* right;
        BST (T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

// insert is of Binary Tree not BST
BST<int>* insert () {
    int data;
    cout << "Enter root data : ";
    cin >> data;
    BST<int>* root = new BST<int>(data);
    queue<BST<int>*> q;
    q.push (root);
    while (!q.empty() )
    {
        cout << "Enter left Node of " << q.front()->data << " : ";
        cin >> data;
        if (data != -1) {
            BST<int>* leftNode = new BST<int> (data);
            q.push (leftNode);
            q.front()->left = leftNode;
        }
        cout << "Enter right Node of " << q.front()->data << " : ";
        cin >> data;
        if (data != -1) {
            BST<int>* rightNode = new BST<int> (data);
            q.push (rightNode);
            q.front()->right = rightNode;   
        }
        q.pop();
    }
    return root;    
}

// check tree is BST or not 
template <typename T>
bool isBST (BST<T>* root) {
    if (root == NULL) {
        return true;
    }
    if (root->data > root->left->data && root->data < root->right->data) {
        if (isBST (root->left) && isBST (root->right) ) {
            return true;
        } else {
            return false;
        }
    } 
    return false;
}


template <typename T>
bool findElement (BST<T>* root, T n) {
    if (root == NULL) {
        return 0;
    }
    if (n == root->data) {
        return 1;
    } else {
        if (n < root->data) {
            return findElement (root->left, n);
        } else {
            return findElement (root->right, n);
        }
    }
}

template <typename T>
void printInRange (BST<T>* root, int k1, int k2) {
    if (root == NULL) {
        return;
    }
    if (root->data >= k1 && root->data <= k2) {
        cout << root->data << " ";
    }
    if (k1 < root->data) {
        printInRange (root->left, k1, k2);
    }
    if (k2 >= root->data) {      
        printInRange (root->right, k1, k2);
    }
}

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// wrong Input : 25 20 36 10 22 30 40 12 5 -1 -1 28 -1 38 48 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main () {
    BST<int>* root = insert();
    cout << "\nisBST : " << isBST(root); // Error not working
    int n = 11;
    cout << endl;
    if (findElement(root, n)) {
        cout << "Present\n";
    } else {
        cout << "Not Present\n";
    }
    printInRange (root,10,13);
    return 0;
}