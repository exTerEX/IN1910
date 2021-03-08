#include <iostream>
#include <vector>

struct newNode {
    int data;
    newNode *next;

    newNode(int n) { data = n; next = nullptr; }
    newNode(int n, newNode* p) { data = n; next = p; }
};

class CircLinkedList {
public:
    CircLinkedList(void) {
        head = nullptr;
        size = 0;
    }

    ~CircLinkedList(){
        newNode* current = head; newNode* next;

        while(current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = 0;
    }

    CircLinkedList(int n) {
        head = nullptr; size = 0;
        
        for (int index = 1; index <= n; index++) {
            append(index);
        }
    }

    int& operator[](int index) {
        return get_node(index) -> data;
    }

    void append(int value) {
        if (head == nullptr) {
            head = new newNode(value);
            head->next = head;
            size++;
            return;
        }
        
        newNode *current = head;
        while (current->next != head) {
            current = current->next;
        }

        current->next = new newNode(value);
        current->next->next = head;
        size++;
    }
    
    int length() { return size; }

    void print() {
        newNode* current = head;
        int count = 0;
        std::cout << "[";
        while (current -> next != nullptr && count < size - 1) {
            std::cout << current -> data << ", ";
            current = current -> next;
            count++;
        }
        std::cout << current -> data << "]" << std::endl;
    }

    void remove(int index) {
        newNode* current = head, *Next = nullptr;
        if (index == 0) {
            head = current -> next;
            delete current;
            size--;
            return;
        }      
        for (int i = 0; i < index - 1; i++) {
            current = current -> next;
            if (size < 1) {
                delete current;
                return;
            }
        }
        newNode* prev = current -> next;
        current -> next = prev -> next;
        delete prev;
        size--;
    }

    std::vector<int> josephus_sequence(const int k) {
        newNode* current = head, *temp = nullptr;
        
        std::vector<int> vec;


        while (size >= 1) {
            for (int i = 1; i < k-1; i++) {
	      //prev = current;
                current = current->next;
            }
	    
	    //std::cout << "now at:" <<  current->data << std::endl;
	  
	    //Link two nodes and remove the one in between:
	    temp = current;
            current = current->next;
            temp->next = current->next;
	   
	    //std::cout << current->data << std::endl;
            vec.push_back(current->data);
	    if (current == head)
	      head = temp->next;
            delete current;
	    //print();
            current = temp->next;
	    size--;
        }
        return vec;
	
    }

protected:

private:
    newNode* head;
    int size;

    newNode* get_node(int index) {
        newNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current -> next;
        }
        return current;
    }
};
