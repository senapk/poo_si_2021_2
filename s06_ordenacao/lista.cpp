#include <iostream>

#template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
};

#template <typename T>
struct Lista {
    Node<T>* head;
    Node<T>* tail;

    public:
    Lista() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void push_front(T value) {
        auto node = new Node<T>(value);
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
};


