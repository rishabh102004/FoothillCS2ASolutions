//Student ID: 20434384
// Pet.cpp
// 2a-Lab-06-Pets
//
#include <iostream>
#include <sstream>
#include <vector>
#include "Pet.h"
using namespace std;
// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;
Pet::Pet(string name, long id, int num_limbs) {
// TODO - Your code here
    _name= name; 
    _id = id; 
    _num_limbs = num_limbs; 
}
Pet::~Pet() {
// TODO - Your code here
    _name = ""; 
    _id = -1; 
    _num_limbs = 0; 
}
string Pet::get_name() const { return _name; }
long Pet::get_id() const {
// TODO - Your code here
    return _id; 
}
int Pet::get_num_limbs() const {
// TODO - Your code here
    return _num_limbs; 
}
bool Pet::set_name(string name) {
// TODO - Your code here
    if (name.length() == 0) {
        return false; 
    }
    _name = name; 
    return true; 
}
bool Pet::set_id(long id) {
// TODO - Your code here
    if (id < 0) {
        return false; 
    }
    _id = id; 
    return true; 
}
bool Pet::set_num_limbs(int num_limbs) {
// TODO - Your code here
    if (num_limbs < 0) {
        return false; 
    }
    _num_limbs = num_limbs; 
    return true; 
}
string Pet::to_string() const {
// TODO - Your code here
    ostringstream id; 
    id << _id; 
    ostringstream num_limbs; 
    num_limbs << _num_limbs; 
    return "(Name: " + _name + ", ID: " + id.str() + ", Limb Count: " + num_limbs.str() + ")"; 
}
// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.

void Pet::get_n_pets(size_t n, std::vector<Pet> &pets, int name_len) {
// TODO - Resize pets as necessary
    long prev_id = 0;
    pets.resize(n); 
    for (size_t i = 0; i < n; i++) {
        long id = prev_id + 1 + rand() % 10; 
        pets[i].set_id(id);
        pets[i].set_num_limbs(rand() % 9); 
        pets[i].set_name(Pet::make_a_name(name_len));
        prev_id = id;  
    // TODO - make and set a name of the requested length
    // TODO - adjust prev_id as necessary   
    }
}

// ---------------------------------------------------------------------
string Pet::make_a_name(int len) {
// TODO - Your code here
    char vowels[] = "aeiou"; 
    char consonants[] = "bcdfghjklmnpqrstvwxyz"; 
    string name = ""; 
    if (len == 0) {
        return name; 
    }
    int first_letter = rand() % 2; 
    if (first_letter % 2 == 0) {
        char con = consonants[rand() % 21]; 
        name = name + con; 
        for (int i = 0; i < len - 1; i++) {
            if (i % 2 == 1) {
               name = name + consonants[rand() % 21];  
            }
            else {
                name = name + vowels[rand() % 5]; 
            }
        }
        return name;
    }
    else {
        char vow = vowels[rand() % 5]; 
        name = name + vow; 
        for (int i = 0; i < len - 1; i++) {
            if (i % 2 == 0) {
               name = name + consonants[rand() % 21];  
            }
            else {
                name = name + vowels[rand() % 5]; 
            }
        }
        return name; 
    }
}
// Optional EC points
// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2) {
    return (pet1.get_id() == pet2.get_id() && pet1.get_num_limbs() == pet2.get_num_limbs() && pet1.get_name() == pet2.get_name()); 
}
bool operator!=(const Pet& pet1, const Pet& pet2) {
    return !(operator==(pet1, pet2)); 
}
ostream& operator<<(ostream& os, const Pet& pet) {
    std::cout << pet.to_string() << endl; 
    return os; 
}
/* 
int main() {
    Pet *dog = new Pet("Tom", 20434384, 4); 
}
*/ 