// Genric Tree
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public : 
        T data;
        vector <TreeNode<T>*> children;
        TreeNode (T data) {
            this->data = data;
        }
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children.at(i);
            }
        }
};

template <typename T>
TreeNode<T>* input () {
    T data;
    cout << "Enter Root data : ";
    cin >> data;
    TreeNode<T>* root = new TreeNode<T>(data);
    queue<TreeNode<T>*> q;
    q.push(root);
    while (!q.empty())
    {
        int n;
        cout << "No. of children of "<< q.front()->data << " : ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout <<"\nEnter data of " << i << "th position of " << q.front()->data << " node : ";
            cin >> data;
            TreeNode<T>* child = new TreeNode<T>(data);
            q.push(child);
            q.front()->children.push_back(child);
        } cout << endl;
        q.pop();
    }
    return root;    
}

// Level-Order Print of tree.
template <typename T>
void LevelOrder (TreeNode<T>* root) {
    if (root == NULL) {
        cout << "No element found\n";
        return;
    }
    queue<TreeNode<T>*> q;
    q.push(root);
    while (!q.empty()) {
        cout << q.front()->data << " : ";
        for (int i = 0; i < q.front()->children.size(); i++) {
            cout << q.front()->children.at(i)->data << ", ";
            q.push(q.front()->children.at(i));  
        } cout << endl; 
        q.pop();
    }
}

// Another method
// template <typename T>
// void LevelOrder (TreeNode<T>* root) {
//     if (root == NULL) {
//         cout << "No element found\n";
//         return;
//     }
//     queue<TreeNode<T>*> q;
//     q.push(root);
//     cout << q.front()->data << ", ";
//     while (!q.empty()) {
//         for (int i = 0; i < q.front()->children.size(); i++) {
//             cout << q.front()->children.at(i)->data << ", ";
//             q.push(q.front()->children.at(i));  
//         }  
//         q.pop();
//     }
// }

// Pre-order Traversal
template <typename T>
void PreOrder (TreeNode<T>* root) {
    if (root == NULL) {
        cout << "Tree Empty\n";
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++) {
        PreOrder (root->children.at(i) );
    }
}

// Post-order Traversal
template <typename T>
void PostOrder (TreeNode <T>* root) {
    if (root == NULL) {
        cout << "Tree Empty\n";
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        PostOrder(root->children.at(i));
    }
    cout << root->data << " ";
}

// To calculate Total no. of nodes
template <typename T>
int TotalNode (TreeNode<T>* root) {
    if (root == NULL) {
        cout << "No element found\n";
        return 0;
    }  
    int count = 1;
    for (int i = 0; i < root->children.size(); i++) {
        count += TotalNode (root->children.at(i));
    }  
    return count;
}

// Height of Tree
template <typename T>
int HeightOfTree (TreeNode<T>* root) {
    if (root == NULL) {
        cout << "Root is Null , No element present\n";
        return 0;
    }
    int height = 1;
    int arr[root->children.size()];
    for (int i = 0; i < root->children.size(); i++) {
        height = 1 + HeightOfTree (root->children.at(i));
        arr[i] = height;
    }
    if (root->children.size() > 1) 
       return *max_element(arr, arr + root->children.size() );
    else 
        return height;
}

//  To Print all element at depth k or at level k
template <typename T>
void PrintAtDepth_K (TreeNode<T>* root, int k) {
    if (root == NULL) {
        cout << "No element present, Tree Empty\n";
        return;
    }
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        PrintAtDepth_K (root->children.at(i), k-1);
    }
}

// No of Leaf Nodes (Leaf Node : having 0 child / no child)
template <typename T>
int Leaf_Node (TreeNode<T>* root) {
    if (root == NULL) {
        cout << "Tree Empty\n";
        return 0;
    }
    int count = 0;
    if (root->children.size() == 0) {
        // cout << root->data << " ";
        count ++;
        return count;
    }
    for (int i = 0; i < root->children.size(); i++) {
        count = count + Leaf_Node (root->children.at(i));
    }
    return count;
}

// Another method to delete a tree by function
// template <typename T>
// void deleteTree (TreeNode<T>* root) {
//     if (root == NULL) {
//         return;
//     }
//     for (int i = 0; i < root->children.size(); i++) {
//         deleteTree (root->children.at(i));
//     }
//     delete root;
// }

// Input : 8 3 4 5 6 1 1 1 2 1 3 0 0 0
int main () {
    TreeNode<int>* root = input<int>();
    LevelOrder(root);
    cout << endl << "Total Tree Node : " << TotalNode (root);
    cout << endl << "Height of a Tree : " << HeightOfTree (root);
    int k;
    cout << "\nEnter the depth : ";
    cin >> k;
    if (k > HeightOfTree(root)) {
        cout << "Please Enter valid data\n";
    } 
    else {
        cout << "Tree Nodes at  depth " << k << " : ";
        PrintAtDepth_K (root, k);
    }
    cout << "\nNo of Leaf Node : " << Leaf_Node(root);
    cout << "\nPreOrder Traversal : ";
    PreOrder(root);
    cout << "\nPostOrder Traversal : ";
    PostOrder(root);
    // deleteTree (root);  // to delete a Tree by function.
    delete root; // 2nd Method to delete a Tree by destructor. as while deleting a obj, desconstructor is automaticaly called.
    // Note : deleting a tree will be much benifited or required when user will creat multiple tree.
    return 0;
}

// height with better way
