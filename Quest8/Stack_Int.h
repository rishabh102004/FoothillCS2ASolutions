class Stack_Int {
private:
std::vector<int> _data;
public:
// No explicit constructor or destructor. You must implement the remaining
// methods below in-line (directly in this header file) within the class-def.
// See the starter code for more detail.
size_t size() const;
bool is_empty() const;
void push(int val);
int top(bool& success) const;
bool pop();
bool pop(int& val);
string to_string() const;
};