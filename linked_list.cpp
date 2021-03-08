// singly linked list
// ------------------
#include <vector>
#include <iostream>

// Node structure
struct Node {
    int data;
    Node *next;

    Node(int n) { data = n; next = nullptr; }
    Node(int n, Node* p) { data = n; next = p; }
};

class LinkedList {
public:
    LinkedList() { head = nullptr; tail = nullptr; size = 0; }

    ~LinkedList(){
        Node* current = head; Node* next;

        while(current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = 0;
    }

    LinkedList(std::vector<int> list) {
        head = nullptr; tail = nullptr;
        size = 0;

        for (int value : list) {
            append(value);
        }
    }

    int& operator[](int index) {
        return get_node(index) -> data;
    }

    void append(int value) {
        if (head == nullptr) {
            head = new Node(value);
            tail = head;
            size++;
            return;
        }

        tail->next = new Node(value);
        tail = tail->next;
        size++;
    }

    void print() {
        Node* current = head;
        std::cout << "[";
        while (current -> next != nullptr) {
            std::cout << current -> data << ", ";
            current = current -> next;
        }
        std::cout << current -> data << "]" << std::endl;
    }

    int length() { return size; }

    void insert(int value, int index) {
        Node* prev = get_node(index - 1);
        Node* next = prev -> next;
        prev -> next = new Node(value, next);
        size++;
    }

    void remove(int index) {
        pop(index);
    }

    int pop() {
        return pop(size - 1);
    }

    int pop(int index) {

        Node* current = head, *Next = nullptr;

        if (index == 0) {
            Node *prev = head;
            head = current -> next;
            delete current;
            size--;
            return prev->data;
        }

        for (int i = 0; i < index - 1; i++) {
            current = current -> next;
        }
        Next = current -> next;
        int int_data = Next->data;
        current -> next = Next -> next;
        delete Next;
        size--;
        return int_data;
    }

protected:

private:
    Node* head; Node* tail;
    int size;
    

    Node* get_node(int index) {
        if (index < 0 || index >= size) {
            throw std::range_error("IndexError: Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current -> next;
        }
        return current;
    }
};