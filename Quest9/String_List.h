// Student ID:20434384
// TODO - Type in your student ID after the colon above.
// String_List.h
//
#ifndef String_List_h
#define String_List_h
#include <iostream>
#include <sstream>
// Important implementation note: With the exception of to_string(),
// and clear(), all list methods below should operate in a constant amount
// of time regardless of the size of the String_List instance.
//
// The semantics of _prev_to_current is such that it always points to the
// node *BEFORE* the current one. This makes the manipulations easy because
// we can only look forward (and not back) in singly linked lists.
//
// I've included some method header comments below where there's likely to
// be confusion.
//
class String_List {
private:
    struct Node {
        std::string data;
        Node *next;
        Node(std::string s = "") : data(s), next(nullptr) {}
    };
    Node *_head, *_tail, *_prev_to_current;
    size_t _size;
public:
    String_List() {
    // TODO - Your code here
        _head = new Node("_SENTINEL_"); 
        _tail = _head; 
        _prev_to_current = _head; 
        _size = 0; 
    }
    ~String_List() {
    // TODO - Your code here
        Node *runner = _head; 
        for (size_t i = 0; i < _size; i++) {
            Node *n = runner->next; 
            delete(runner); 
            runner = n; 
        }
        _size = 1;  
    }
    String_List *insert_at_current(std::string s) {
    // TODO - Your code here
        Node *new_node = new Node(s); 
        new_node->next = _prev_to_current->next; 
        _prev_to_current->next = new_node; 
        _size++; 
        Node* runner = _head; 
        while (runner->next != nullptr) {
            runner = runner->next;
        }
        _tail = runner;
        return this;  
    }
    String_List *push_back(std::string s) {
    // TODO - Your code here
        Node* temp = _prev_to_current; 
        _prev_to_current = _tail; 
        insert_at_current(s);
        _prev_to_current = temp; 
        return this; 
    }
    String_List *push_front(std::string s) {
    // TODO - Your code here
        Node* temp = _prev_to_current;
        _prev_to_current = _head; 
        insert_at_current(s);         
        // at this point, new_head is pointing to sentinel, and head_ref is pointing to this
        _prev_to_current = temp;
        //_size++;
        return this; 
    }
    String_List *advance_current() {
    // TODO - Your code here
        if (_prev_to_current == _tail) {
            return nullptr; 
        }
        _prev_to_current = _prev_to_current->next; 
        return this; 
    }
    std::string get_current() const {
    // TODO - Your code here
        Node *current = _prev_to_current->next;
        return current->data; 
    }
    String_List *remove_at_current() {
    // TODO - Your code here
        Node* temp = _prev_to_current->next; 
        _prev_to_current->next = temp->next;
        delete(temp); 
        _size--;  
        return this; 
    }
    size_t get_size() const {
    // TODO - Your code here
        return _size; 
    }
    String_List *rewind() {
    // TODO - Your code here
        _prev_to_current = _head;
        return this; 
    }
    void clear() {
    // TODO - Your code here
        Node *runner = _head->next; 
        while (runner != nullptr) {
            Node *current = runner; 
            runner = runner->next; 
            delete(current); 
        }
        _size = 0;
        _prev_to_current = _head; 
        _tail = _head; 
        _head->next = nullptr; 
    }
    // Find a specific item. Does NOT change cursor.
    //
    // The following returns a reference to the target string if found. But what will
    // you do if you didn't find the requested string? Using sentinel markers is
    // one way to handle that situation. Usually there's only one copy of the
    // sentinel that's global. We will use a local one so it's cleaner with a
    // little more risk (what's the risk?)
    //
    std::string& find_item(std::string s) const {
    // TODO - Your code here 
        Node* runner = _head; 
        size_t count = 0;  
        while (count <= _size) {
            if (runner->data.compare(s) == 0) {
                return (*runner).data; 
            }
            count++;
            runner = runner->next;
        }
        static std::string Sentinel = "_SENTINEL_"; 
        std::string& sent = Sentinel; 
        return sent; 
    }
    // Print up to max_lines lines starting at _prev_to_current->next. If the caller
    // wants to print from the beginning of the list, they should rewind() it first.
    //
    std::string to_string() const {
    // TODO - Your code here
        std::string ts = ""; 
        ts = "# String_List - " + std::to_string(_size) + " entries total. Starting at cursor:"; 
        ts = ts + "\n"; 
        if (_size <= 25) {
            Node *runner = _prev_to_current->next; 
            while(runner != nullptr) {
                ts += runner->data; 
                runner = runner->next;
                ts += "\n"; 
            }
            return ts; 
        }
        else {
            Node *runner = _prev_to_current->next;
            while (runner != nullptr) {
                ts += runner->data;
                runner = runner->next;
                ts += "\n"; 
            }
            ts += "..."; 
            ts += "\n";
            return ts; 
        }
    }
    friend class Tests; // Don't remove this line
};
#endif /* String_List_h */
/*
int main() {
    std::cout << "It works"  << std::endl; 
}
*/ 