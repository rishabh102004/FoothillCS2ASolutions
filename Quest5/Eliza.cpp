// Student ID: 20434384
// TODO - Replace the number above with your actual Student ID
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//
#include <iostream>
#include <sstream>
#include "Eliza.h"
using namespace std;
// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
//
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.
string rotate_vowels(string& s) {
    string a;
    string updated_string = s; 
    string vowels = "aeiouaAEIOUA";
    for (size_t i = 0; i < (s).length(); i++) {
        for (size_t j = 0; j < vowels.length(); j++) {
            if (vowels[j] == (s)[i]) {
                updated_string = updated_string.substr(0,i) + vowels[j + 1] + updated_string.substr(i + 1);
                break;
            }
        }
    }
    s = updated_string;
    return updated_string; 
}
// Return a string in which all occurrences of s have been replaced by th
string lispify(string s) {
    if (s.length() == 0) {
        return s; 
    }
    if (s.substr(0,1) == "s") {
        return "th" + lispify(s.substr(1)); 
    }
    if (s.substr(0,1) == "S") {
        return "Th" + lispify(s.substr(1)); 
    }
    return s.substr(0,1) + lispify(s.substr(1)); 
}
// Enter the user-interaction loop as described earlier
void enter() {
// TODO - Your code here
    cout << "What?" << endl; 
    string s;
    while (true) { 
        getline(cin, s); 
        cout << "     " << s << endl;
        if (s.length() == 0) {
            cout << "What?" << endl; 
            continue; 
        } 
        cout << "" << endl; 
        cout << "" << endl; 
        if (s.find("bye") != string::npos|| s.find("quit") != string::npos || s.find("Bye") != string::npos || s.find("Quit") != string::npos) {
            cout << "Ok Bye. Nice being a force of change in your life." << endl;
            break; 
        }
        if (s.find("!") != string::npos) {
            cout << "OMG! You don't say!! " << s << "!!!!!" << endl; 
            continue; 
        }
        if (s.find("why") != string::npos || s.find("what") != string::npos) {
            cout << "I'm sorry, I don't like questions that contain what or why." << endl ;
            continue; 
        }
        if (s.find("s") != string::npos) {
            cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl; 
            cout << lispify(s) << "! Sheesh! Now what?" << endl; 
            continue; 
        }
        else {
            int num = rand() % 10; 
            if (num == 8 || num == 9) {
                cout << "Huh? Why do you say: " << s << "?" << endl; 
            }
            else {
                cout << rotate_vowels(s) << "?" << endl; 
            }
        }
    }
}
/*
int main() {
    string a = "AEIOU"; 
    string b = "aeiou";
    string c = "bakA"; 
    string d = "baka";
    cout << rotate_vowels(a) << endl; 
    cout << rotate_vowels(b) << endl; 
    cout << rotate_vowels(c) << endl; 
    cout << rotate_vowels(d) << endl;
    cout << a << endl; 
    cout << b << endl;
    cout << c << endl; 
    cout << d << endl; 
}
*/