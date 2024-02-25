#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public : 
        T data;
        vector<TreeNode<T>*> children;
        TreeNode (T data) {
            this->data = data;
        }
};

TreeNode <int>* input () {
    int data;
    cout << "Enter root Node : ";
    cin >> data;
    TreeNode<int>* root = new TreeNode<int>(data);
    int n;
    cout << "No of children of root of " << root->data << " : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        TreeNode<int>* child = input ();
        root->children.push_back(child);
    }
    return root;
}

template <typename T>
void PrintTree (TreeNode<T>* root) {
    if (root == NULL) {     // not a base case since I will never come here if root exits. it's a edge case. No need of base case here since I never call recurion more the vector size. 
        cout << "No element found\n";
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++) {
        cout << root->children.at(i)->data << ", ";
    } cout << endl;
    for (int i = 0; i < root->children.size(); i++) {
        PrintTree (root->children.at(i));
    }
}

int main () {
    // TreeNode<int>* root = new TreeNode<int> (1);  
    // TreeNode<int>* child_1 = new TreeNode<int> (2);  
    // TreeNode<int>* child_2 = new TreeNode<int> (3);  
    // root->children.push_back(child_1);
    // root->children.push_back(child_2);
    TreeNode<int>* root = input();
    PrintTree (root);
    return 0;
}