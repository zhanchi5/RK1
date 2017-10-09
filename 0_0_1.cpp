#include <iostream>


struct Node {
    int data;
    Node * next;
};

Node* reverse(Node *head) {
    Node *ptr = nullptr, *tmp;
    while (head) {
        tmp = head->next;
        head->next = ptr;
        ptr = head;
        head = tmp;
    }
    return head;
}

int main() {
    Node* head = new Node();
    Node* cur = head, *new_nd;
    head->data = 0;
    for (int i = 0; i < 5; i++)
    {
        new_nd = new Node();
        new_nd->data = i + 1;
        new_nd->next = nullptr;
        cur->next = new_nd;
        cur = new_nd;
    }

    head = reverse(head);

    return 0;
}
