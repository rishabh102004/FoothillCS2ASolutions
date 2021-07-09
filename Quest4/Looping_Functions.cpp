//Student ID: 20434384
#include <iostream>
#include <sstream>
#include "Looping_Functions.h"
using namespace std;
// Give the user 6 chances to guess the secret number n (0-10). If they get it,
// say so and return true. Else say so and return false.
bool play_game(int n) {
// TODO - Your code here
    cout << "Welcome to my number guessing game"; 
    cout << "" << endl; 
    cout << "" << endl; 
    int guesses = 0; 
    int user_input; 
    while (guesses != 6) {
        cout << "Enter your guess: " << endl; 
        cin >> user_input; 
        cout << "You entered: " << user_input << endl; 
        guesses++; 
        if (user_input == n) {
            cout << "You found it in " << guesses << " guess(es)." << endl; 
            //cout << "" << endl; 
            return true; 
        }
    }
    cout << "" << endl; 
    cout << "I'm sorry. You didn't find my number." << endl; 
    cout << "It was " << n << endl; 
    return false; 
}
// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term.
double etox(double x, size_t n) {
// TODO - Your code here
    double e = 1 + x; 
    double xt = x; 
    double divisor = 1; 
    if (n == 0) {
        return 0; 
    }
    if (n == 1) {
        return 1; 
    }
    if (n == 2) {
        return 1 + x; 
    }
    else {
        for (int i = 2; i < n; i++) {
            xt *= x; 
            divisor *= i; 
            e += (xt/divisor); 
        }
        return e; 
    }
}
// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c) {
// TODO - Your code here
    size_t count = 0; 
    for (size_t i = 0;  i < s.length(); i++) {
        if (s[i] == c) {
            count++; 
        }
    }
    return count; 
}
// Use Euclid's algorithm to calculate the GCD of the given numbers
size_t gcd(size_t a, size_t b) {
// TODO - Your code here
    if (a == 0) {
        return b; 
    }
    if (b == 0) {
        return a; 
    }
    if (a == b) {
        return b; 
    }
    if (b > a) {
        return gcd(a, b - a); 
    }
    else {
        return gcd(a - b, b); 
    }
}
// Return a string of the form n1,n2,n3,... for the given AP.
string get_ap_terms(int a, int d, size_t n) {
// TODO - Your code here
    string ap_terms = to_string(a); 
    if (n == 0) {
        return ""; 
    }
    if (n <= 1) {
        return ap_terms;  
    }
    ap_terms += ","; 
    ap_terms += get_ap_terms(a + d, d, n - 1); 
    return ap_terms; 
}
// Return a string of the form n1,n2,n3,... for the given GP.
string get_gp_terms(double a, double r, size_t n) {
// TODO - Your code here
    double a_copy = a; 
    ostringstream a_cnv; 
    a_cnv << a_copy; 
    string gp_terms = a_cnv.str(); 
    if (n == 0) {
        return ""; 
    } 
    if (n <= 1) {
        return gp_terms; 
    } 
    gp_terms += ","; 
    gp_terms += get_gp_terms(a*r, r, n - 1);
    return gp_terms; 
}
double get_nth_fibonacci_number(size_t n) {
// TODO - Your code here
    double a = 0;
    double b = 0; 
    double c = 1; 
    for (size_t i = 0; i < n; i++) {
        a = b + c; 
        b = c; 
        c = a;
    }
    return b; 
}