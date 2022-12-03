#include <iostream>
#include <random>

struct Node {
    int data;
    Node* next;
};

Node* generate(int n) {
    Node* ptr = nullptr;
    for(int i = n; i > 0; i--) {
        Node* new_node = new Node{i, ptr};
        ptr = new_node;
    }
    return ptr;
}

Node* generate_random(int n) {
    Node* ptr = nullptr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for(int i = n; i > 0; i--) {
        Node* new_node = new Node{dis(gen), ptr};
        ptr = new_node;
    }
    return ptr;
}

void reverse(Node** list) {
    Node* prev = nullptr;
    Node* current = *list;
    Node* next = nullptr;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

void reverse2(Node** list, int left, int right) {
    Node* prev = nullptr;
    Node* current = *list;
    Node* next = nullptr;
    int i = 1;
    while(i < left) {
        prev = current;
        current = current->next;
        i++;
    }
    Node* left_node = current;
    Node* left_prev = prev;
    while(i <= right) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        i++;
    }
    Node* right_node = prev;
    Node* right_next = current;
    if(left_prev != nullptr) {
        left_prev->next = right_node;
    } else {
        *list = right_node;
    }
    left_node->next = right_next;
}

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
