#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    explicit LinkedList(Node* head) {
        this->head = nullptr;
        for (Node* node = head; node != nullptr; node = node->next) {
            push_back(node->data);
        }
    }

    LinkedList(std::initializer_list<int> list) {
        head = nullptr;
        for (int data : list) {
            push_back(data);
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void clone(const LinkedList& other) {
        head = nullptr;
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
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

    void insert_node(int data, int index) {
        if (index == 0) {
            push_front(data);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        auto* newNode = new Node;
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }

    void delete_node(int index) {
        if (index == 0) {
            pop_front();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* next = current->next->next;
        delete current->next;
        current->next = next;
    }

    void push_front(int data) {
        auto* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void push_back(int data) {
        auto* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void pop_front() {
        Node* next = head->next;
        delete head;
        head = next;
    }

    void pop_back() {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    Node* head = nullptr;
};

inline std::ostream &operator<<(std::ostream &out, const LinkedList &list) {
    Node* p = list.head;
    while (p != nullptr) {
        out << p->data << std::endl;
        p = p->next;
    }
    return out;
}
