#include <iostream>
using namespace std;

class Node {
    public : 
        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            next = NULL;
        }
};

Node* insert () {
    int data;
    Node *head = NULL;
    Node *tail = NULL;  
    cin >> data;
    while (data != -1 ) {
        Node *newNode = new Node (data);
        if ( head == NULL ){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }   cin >> data;
    }
    return head;
}

Node* merge (Node *h1, Node *h1_stop, Node *h2, Node *h2_stop) {
    Node* head = NULL, *tail = NULL;
    while (h1 != h1_stop->next && h2 != h2_stop->next) {
        if (h1->data < h2->data) {
            if (head == NULL) {
                head = h1;
                tail = h1;
            } else {
                tail->next = h1;
                tail = tail->next;
            }
            h1 = h1->next;
        } else {
            if (head == NULL) {
                head = h2;
                tail = h2;
            } else {
                tail->next = h2;
                tail = tail->next;
            }
            h2 = h2->next;
        }
    }

    if (h1 != h1_stop->next) {
        tail->next = h1;
        while (tail != h1_stop) {
            tail = tail->next;
        }
    }

    if (h2 != h2_stop->next) {
        tail->next = h2;
        while (tail != h2_stop) {
            tail = tail->next;
        }
    }
    tail->next = NULL;
    return head;
}


// Node* merge (Node *h1, Node *h1_stop, Node *h2, Node *h2_stop) {
//     Node *head = NULL , *tail = NULL;
//     while (h1 != h1_stop && h2 != h2_stop) {
//         if (h1->data < h2->data) {
//             if (head == NULL) {
//                 head = h1;
//                 tail = h1;
//             } else {
//                 tail->next = h1;
//                 tail = tail->next;
//             } 
//             h1 = h1->next;
//         } else {
//             if (head == NULL) {
//                 head = h2;
//                 tail = h2;
//             } else {
//                 tail->next = h2;
//                 tail = tail->next;
//             }
//             h2 = h2->next;
//         } 
//     } 
//     if (h1 == h1_stop) {
//         tail->next = h2;
//     } else {
//        tail->next = h1; 
//     }
//     return head;
// }

Node* midElement (Node *head, Node *tail) {
    Node *slow = head;
    Node *fast = head;
    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    } 
    return slow;
}
 
Node* mergeSort (Node *head, Node *tail) {
    cout <<"merge Sort : ";
    if (head == tail) {
        return head;
    } 
    Node *mid = midElement(head, tail);
    Node *h1 = mergeSort (head, mid);
    Node *h2 = mergeSort (mid->next, tail);
    head = merge(h1, mid, h2, tail);
    return head;
}

void print (Node *temp) {
    cout <<"print : ";
    while (temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    } cout << endl;
}

Node *lastIndex (Node *head) {
    while (head->next != NULL) {
        head = head->next;;
    } 
    return head;
}

int main () {
    Node *head = insert();
    Node *tail = lastIndex(head);
    head = mergeSort (head, tail);
    print (head);
    return 0;
}