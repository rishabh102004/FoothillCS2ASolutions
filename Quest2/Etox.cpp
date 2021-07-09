//Student ID: 20434384
// Etox.cpp
// 2a-Lab-01
//
#include <iostream>
#include <sstream>
#include <cmath> // needed for sqrt
#include <cstdlib> // for exit()
using namespace std;
double etox_5_terms(double x) {
    double e = 1 + x; 
    e += (x*x)/2; 
    e += (x*x*x)/(3*2*1); 
    e += (x*x*x*x)/(4*3*2*1); 
    return e; 
}
int main(int argc, char **argv) {
    string user_input;
    double x;
    cout <<"Enter a value for x: ";
    getline(cin, user_input);
    istringstream(user_input) >>x;
    double etox = etox_5_terms(x); 
    cout << etox << endl; 
    return 0;
}