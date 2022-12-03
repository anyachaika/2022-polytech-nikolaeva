#include <iostream>
#include <random>

struct Node {
    int data;
    Node* next;
};

class Queue {
public:
    Queue() {
        head = nullptr;
    }

    ~Queue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Node* get(int index) {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    int size() {
        int size = 0;
        Node* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }

    void enqueue(int data) {
        auto* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    int dequeue() {
        if (head->next == nullptr) {
            int data = head->data;
            delete head;
            head = nullptr;
            return data;
        }
        Node* current = head;
        Node* previous = nullptr;
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        int data = current->data;
        delete current;
        previous->next = nullptr;
        return data;
    }
    Node* head = nullptr;
};

inline std::ostream &operator<<(std::ostream &out, const Queue &list) {
    Node* p = list.head;
    while (p != nullptr) {
        out << p->data << std::endl;
        p = p->next;
    }
    return out;
}
