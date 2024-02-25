#include <iostream>
using namespace std;

class BinaryTree {
    public :
        int data;
        BinaryTree* left;
        BinaryTree* right;
        BinaryTree (int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

int main () {

    return 0;
}