#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        BinaryTree<T>* left;
        BinaryTree<T>* right;
        BinaryTree (T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

BinaryTree<int>* insert () {
    int data;
    cout << "Enter root data : ";
    cin >> data;
    BinaryTree<int>* root = new BinaryTree<int>(data);
    queue<BinaryTree<int>*> q;
    q.push (root);
    while (!q.empty() )
    {
        cout << "Enter left Node of " << q.front()->data << " : ";
        cin >> data;
        if (data != -1) {
            BinaryTree<int>* leftNode = new BinaryTree<int> (data);
            q.push (leftNode);
            q.front()->left = leftNode;
        }
        cout << "Enter right Node of " << q.front()->data << " : ";
        cin >> data;
        if (data != -1) {
            BinaryTree<int>* rightNode = new BinaryTree<int> (data);
            q.push (rightNode);
            q.front()->right = rightNode;   
        }
        q.pop();
    }
    return root;    
}

// Level Wise Print
template <typename T>
void levelOrder (BinaryTree<T>* root) {
    if (root == NULL) {
        cout << "Binary Tree Empty\n";
        return;
    }
    queue<BinaryTree<T>*> q;
    q.push (root);
    while (!q.empty() )
    {
        cout << q.front()->data << " : ";
        if (q.front()->left != NULL) {
            cout << "L " << q.front()->left->data << ", ";
            q.push (q.front()->left);
        }
        if (q.front()->right != NULL) {
            cout << "R " << q.front()->right->data;
            q.push (q.front()->right);
        } cout << endl;
        q.pop ();
    }
}

// Total no of Nodes of BT
template <typename T>
int CountNode (BinaryTree<T>* root) {
    if (root == NULL) {
        return 0;
    }
    // int count = 1;
    // if (root->left != NULL) {
    //     count = count + CountNode(root->left);
    // }
    // if (root->right != NULL) {
    //     count = count + CountNode(root->right);
    // }
    // return count;
    return 1 + CountNode(root->left) + CountNode(root->right);  // Another way
}

// PreOrder (Root, left, right)
template <typename T>
void PreOrder (BinaryTree<T>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    PreOrder (root->left);
    PreOrder (root->right);
}

// PostOrder (Left, Right, Root)
template <typename T>
void PostOrder (BinaryTree<T>* root) {
    if (root == NULL) {
        return;
    }
    PostOrder (root->left);
    PostOrder (root->right);
    cout << root->data << " "; 
}

// InOrder (Left, Root, Right)
template <typename T>
void InOrder (BinaryTree<T>* root) {
    if (root == NULL) {
        return;
    }
    InOrder (root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// input : 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main () {
    BinaryTree<int>* root = insert();
    levelOrder (root);
    cout << "Total no of nodes : " << CountNode (root);
    cout << "\nPre Order : ";
    PreOrder(root);   // PreOrder (Root, left, right)
    cout << "\nPost Order : ";
    PostOrder(root);   // PostOrder (Left, Right, Root)
    cout << "\nInOrder : ";
    InOrder(root);   // InOrder (Left, Root, Right)
    return 0;
}