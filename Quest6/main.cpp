#include <iostream> 
using namespace std; 
#include "Pet.h"; 
int main() {
    Pet *dog = new Pet("Tom", 20434384, 4); 
    cout << dog << endl; 
    cout << dog->get_name() << endl;   
}