// Student ID: 20434384
// TODO - Replace the number above with your actual student ID
//
#ifndef Stacks_h
#define Stacks_h
#include <vector>
#include <sstream>
class Stack_Int {
private:
std::vector<int> _data;
public:
// No explicit constructor or destructor
size_t size() const {
// TODO - Your code here
    return _data.size(); 
}
bool is_empty() const {
// TODO - Your code here
    return _data.empty(); 
}
void push(int val) {
// TODO - Your code here
    _data.push_back(val); 
}
int top(bool& success) const {
// TODO - Your code here
    if (is_empty()) {
        success = false; 
        return 0; 
    }
    success = true; 
    return _data.back(); 
}
bool pop() {
// TODO - Your code here
    if (is_empty()) {
        return false; 
    }
    _data.pop_back(); 
    return true;
}
bool pop(int& val) {
// TODO - Your code here
    if (is_empty()) {
        return false; 
    }
    val = _data.back();  
    _data.pop_back(); 
    return true;  
}
std::string to_string() const {
// TODO - Your code here
    std::string ts = ""; 
    ts = "Stack (" + std::to_string(_data.size()); 
    ts = ts  + " elements):"; 
    if (_data.size() <= 10) {
        for (size_t i = 0; i < _data.size(); i++) {
            ts += std::to_string(_data[i]); 
            ts += "\n"; 
        }
    }
    else {
        ts += "\n"; 
        for (int i = 1; i < 11; i++) {
            int val = _data[_data.size() - i]; 
            ts += std::to_string(val);
            ts += "\n";
        }
        ts = ts + "..."; 
        ts = ts + "\n";
    } 
    ts = ts + "Elements, if listed above, are in increasing order of age."; 
    return ts; 
}
// Don't remove the following line
friend class Tests;
};



class Stack_String {
// TODO - Your code here. Ask in the forums if you're stuck.
private:
std::vector<std::string> _data;
public:
// No explicit constructor or destructor
size_t size() const {
// TODO - Your code here
    return _data.size(); 
}
bool is_empty() const {
// TODO - Your code here
    return _data.empty(); 
}
void push(std::string& val) {
// TODO - Your code here
    _data.push_back(val); 
}
std::string top(bool& success) const {
// TODO - Your code here
    if (is_empty()) {
        success = false; 
        return ""; 
    }
    success = true; 
    return _data.back(); 
}
bool pop() {
// TODO - Your code here
    if (is_empty()) {
        return false; 
    }
    _data.pop_back(); 
    return true;
}
bool pop(std::string& val) {
// TODO - Your code here
    if (is_empty()) {
        return false; 
    }
    val = _data.back();  
    _data.pop_back(); 
    return true;  
}
std::string to_string() const {
// TODO - Your code here
    std::string ts = ""; 
    ts = "Stack (" + std::to_string(_data.size()); 
    ts = ts  + " elements):"; 
    if (_data.size() <= 10) {
        for (size_t i = 0; i < _data.size(); i++) {
            ts += _data[i]; 
            ts += "\n"; 
        }
    }
    else {
        ts += "\n"; 
        for (int i = 1; i < 11; i++) {
            ts += _data[_data.size() - i];
            ts += "\n";
        }
        ts = ts + "..."; 
        ts = ts + "\n";
    } 
    ts = ts + "Elements, if listed above, are in increasing order of age."; 
    return ts; 
}
friend class Tests;
};
#endif /* Stacks_h */